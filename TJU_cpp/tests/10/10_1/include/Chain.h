#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
using namespace std;
class Chain;
class Node
{
    friend class Chain;

private:
    char data;
    Node *next;
};
class Chain
{
private:
    Node *head;
    int length;

public:
    Chain()
    {
        head = new Node;
        head->next = 0;
        length = 0;
    }
    ~Chain()
    {
        ClearList();
        delete head;
    }
    bool IsEmpty()
    {
        return length == 0;
    }
    int Length() { return length; }
    bool Find(int i, char &x);
    int Search(const char &x);
    bool Insert(int i, const char &x);
    bool Delete(int i, char &x);
    void ClearList();
    void DeleteItem(Chain &A, const char x);
    bool rInsert(const char &x);
    void output(ostream &out) const;
    friend ostream &operator<<(ostream &out, const Chain &x);
};

#endif // CHAIN_H
