/*************************************************************************
重载各种运算符
P197 []运算符的重载
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
class charArray
{
private:
    char *Buff;
    int Length;

public:
    charArray(int n = 10);
    int getLength()
    {
        return Length;
    }
    char &operator[](int i)
    {
        static char ch = 0;
        if (i < Length && i >= 0)
        {
            return Buff[i];
        }
        else
        {
            cout << "\n下标越界";
            return ch;
        }
    }
    ~charArray();
};

charArray::charArray(int n)
{
    Length = n > 0 ? n : 10;
    Buff = new char[n];
}

charArray::~charArray()
{
    delete[] Buff;
}
int main()
{
    charArray str(8);
    char *s = "character string";
    for (int i = 0; i < 8; i++)
    {
        str[i] = s[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cout << str[i];
    }
    cout << endl;
    cout << "the length is " << str.getLength() << endl;
    return 0;
}