#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
using namespace std;
class SeqList
{
private:
    int Maxsize;
    int length;
    char *element;

public:
    SeqList(int m = 10)
    {
        element = new char[m];
        Maxsize = m;
        length = 0;
    }
    ~SeqList()
    {
        delete[] element;
    }
    bool IsEmpty()
    {
        return length == 0;
    }
    int Length()
    {
        return length;
    }
    bool Find(int i, char &x);
    int Search(const char &x);
    bool Insert(int i, const char &x);
    bool Delete(int i, char &x);
    void ClearList() { length = 0; }
    void DeleteItem(SeqList &A, char &x);
    void output(ostream &out) const; //����Ī��������Ҫ�Ѻ�����Ž���д д����������Ҳ�� WINDOWS-936
    friend ostream &operator<<(ostream &out, const SeqList &x);
};

#endif // SEQLIST_H
