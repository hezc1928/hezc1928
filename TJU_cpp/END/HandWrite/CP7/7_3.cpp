/*************************************************************************
重载各种运算符
P197 =,==运算符的重载
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
class intArray
{
private:
    int *Buff;
    int size;

public:
    intArray(int n = 10)
    {
        size = n;
        Buff = new int[size];
        for (int i = 0; i < size; i++)
        {
            Buff[i] = 0;
        }
    }
    int GetSize()
    {
        return size;
    }
    const intArray &operator=(const intArray &);
    int operator==(const intArray &);
    int &operator[](int);
    intArray(const intArray &a)
    {
        size = a.size;
        Buff = new int[size];
        for (int i = 0; i < size; i++)
        {
            Buff[i] = a.Buff[i];
        }
    }
    ~intArray()
    {
        delete[] Buff;
    }
};
int &intArray::operator[](int i)
{
    if (i >= 0 && i < size)
    {
        return Buff[i];
    }
    cout << "index out of range \n";
    exit(1);
}
const intArray &intArray::operator=(const intArray &r)
{
    if (this != &r)
    {
        delete[] Buff;
        size = r.size;
        Buff = new int[size];
        for (int i = 0; i < size; i++)
        {
            Buff[i] = r.Buff[i];
        }
    }
    return *this;
}
int intArray::operator==(const intArray &r)
{
    if (size != r.size)
    {
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (Buff[i] != r.Buff[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    intArray a1(6), a2;
    int n = a2.GetSize();
    cout << "the origin a1";
    for (int cnt = 0; cnt < 6; cnt++)
    {
        cout << a1[cnt] << " ";
    }
    cout << "\n input a2";
    for (int cnt = 0; cnt < n; cnt++)
    {
        cin >> a2[cnt];
    }
    intArray a3(a2);
    cout << "copy construct";
    for (int cnt = 0; cnt < n; cnt++)
    {
        cout << a3[cnt] << " ";
    }
    a1 = a2;
    cout << "\n = 的重载";
    for (int cnt = 0; cnt < a1.GetSize(); cnt++)
    {
        cout << a1[cnt] << " ";
    }
    cout << endl;
    if (a1 == a2)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}