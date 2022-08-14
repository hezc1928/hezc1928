#include <iostream>
#include <cstring>
using namespace std;
class strs
{
private:
    char *sst;

public:
    strs() {}
    strs(char *s)
    {
        sst = new char[strlen(s) + 1];
        strcpy(sst, s);
    }
    strs(strs &b)
    {
        sst = new char[strlen(b.sst) + 1];
        strcpy(sst, b.sst);
    }
    strs operator+(char *s)
    {
        char *p;
        p = new char[strlen(sst) + strlen(s) + 5];
        strcpy(p, sst);
        strcat(p, s);
        strs b(p);
        delete[] p;
        return b;
    }
    strs operator+(strs b)
    {
        char *p;
        p = new char[strlen(sst) + strlen(b.sst) + 1];
        strcpy(p, sst);
        strcat(p, b.sst);
        strs c(p);
        delete[] p;
        return c;
    }
    void output()
    {
        cout << sst << endl;
    }
    friend strs operator+(char *b, strs a);
};
strs operator+(char *b, strs a)
{
    char *p;
    p = new char[strlen(b) + strlen(a.sst) + 1];
    strcpy(p, b);
    strcat(p, a.sst);
    strs c(p);
    return c;
}
int main()
{
    char a[100] = "rnm ";
    char b[100] = "tuiqian ";
    char c[100] = "guozu ";
    strs s(a);
    s.output();
    cout << endl;
    s = s + b + b + b + b;
    s.output();
    cout << endl;
    s = s + s;
    s.output();
    cout << endl;
    s = c + s;
    s.output();
    return 0;
}
