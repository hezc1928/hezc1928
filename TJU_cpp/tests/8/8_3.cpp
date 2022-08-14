#include <iostream>
#include <cstring>
using namespace std;
class stststr
{
private:
    char *ps;
    int n;

public:
    stststr()
    {
        ps = 0;
        n = 0;
    }
    stststr(const char *cp)
    {
        n = strlen(cp) + 1;
        ps = new char[n];
        strcpy(ps, cp);
    }
    stststr(char *cp)
    {
        n = strlen(cp) + 1;
        ps = new char[n];
        strcpy(ps, cp);
    }
    stststr(stststr &b)
    {
        ps = new char[strlen(b.ps) + 1];
        strcpy(ps, b.ps);
    }
    ~stststr()
    {
        delete[] ps;
    }
    void Display()
    {
        cout << ps << endl;
    }
    stststr operator+(char *s)
    {
        char *p;
        p = new char[strlen(ps) + strlen(s) + 5];
        strcpy(p, ps);
        strcat(p, s);
        stststr b(p);
        delete[] p;
        return b;
    }
    stststr operator+(stststr &s)
    {
        char *p;
        p = new char[strlen(ps) + strlen(s.ps) + 1];
        strcpy(p, ps);
        strcat(p, s.ps);
        stststr c(p);
        delete[] p;
        return c;
    }
    friend stststr operator+(const char hp[], const stststr &m);
};
stststr operator+(const char hp[], const stststr &m)
{
    char *p;
    p = new char[strlen(hp) + strlen(m.ps) + 1];
    strcpy(p, hp);
    strcat(p, m.ps);
    stststr c(p);
    return c;
}
int main()
{
    stststr st1("st1 ");
    stststr st2("st2 ");
    stststr st3("st3 ");
    stststr st4("at4 ");
    char chchchar[] = "chchchar ";
    stststr st5, st6, st7;
    st5 = st1 + st2;
    st6 = st3 + chchchar;
    st7 = chchchar + st4;
    cout << "st1 + st2 = "; //字符串类型相加s
    st5.Display();
    cout << "st3 + chchchar = "; //字符串加字符数组
    st6.Display();
    cout << "chchchar + st4 = "; //字符数组加字符串
    st7.Display();
    return 0;
}
