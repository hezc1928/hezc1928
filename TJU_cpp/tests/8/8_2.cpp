#include <iostream>
#include <cstring>
using namespace std;
const int SLength = 999;

class cstring
{
private:
    char *ps;
    int n;

public:
    cstring(const char *cp)
    {
        n = strlen(cp) + 1;
        ps = new char[n];
        strcpy(ps, cp);
    }
    cstring(char *cp)
    {
        n = strlen(cp) + 1;
        ps = new char[n];
        strcpy(ps, cp);
    }
    cstring &operator=(char *p)
    {
        delete[] ps;
        n = strlen(p) + 1;
        ps = new char[n];
        strcpy(ps, p);
        return *this;
    }
    cstring &operator=(cstring &s)
    {
        delete[] ps;
        n = s.n;
        ps = new char[n];
        strcpy(ps, s.ps);
        return *this;
    }
    cstring &operator+(char *p)
    {
        char *p1;
        int n1 = n;
        p1 = new char[n1];
        strcpy(p1, ps);
        n += strlen(p) + 1;
        delete[] ps;
        ps = new char[n];
        strcpy(ps, p1);
        delete[] p1;
        strcat(ps, p);
        return *this;
    }
    cstring &operator+(cstring &s)
    {
        char *p1;
        int n1 = n;
        p1 = new char[n1];
        strcpy(p1, ps);
        n += s.n;
        delete[] ps;
        ps = new char[n];
        strcpy(ps, p1);
        delete[] p1;
        strcat(ps, s.ps);
        return *this;
    }
    void disp()
    {
        cout << ps << endl;
    }
    friend cstring &operator+(char *p, cstring &s);
    cstring()
    {
        n = 0;
        ps = 0;
        cout << "cstring constructed" << endl;
    }
    ~cstring()
    {
        cout << "cstring destructed" << endl;
    }
};
// cstring &operator+(char *p, cstring &s)
// {
//     char t[SLength + 1] = "";
//     strcpy(t, p);
//     strcat(t, s.ps);
//     return cstring(t);
// }
int main()
{
    cstring str1, str2, str3(" string class "), str4;
    char *pc;
    pc = new char[4];
    *pc = 't';
    *(pc + 1) = 'e';
    *(pc + 2) = 's';
    *(pc + 3) = 't';
    cout << "pc =" << pc << endl;
    str1 = pc;
    cout << "str1 = ";
    str1.disp();
    str2 = str3;
    cout << "str2 = ";
    str2.disp();
    str4 = str3 + pc;
    cout << "str3 + pc = ";
    str4.disp();
    str4 = str1 + str2;
    cout << "str1 + str2 = ";
    str4.disp();
    return 0;
}