/*************************************************************************
重载各种运算符
P200 流插入和流提取运算符的重载
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;
class Array
{
private:
    int *elems;
    int nums;

public:
    Array(int n = 10)
    {
        nums = n > 0 ? n : 10;
        elems = new int[nums];
    }

    ~Array()
    {
        delete[] elems;
    }
    friend ostream &operator<<(ostream &, Array &);
    friend istream &operator>>(istream &, Array &);
};
istream &operator>>(istream &in, Array &a)
{
    cout << "输入" << a.nums << "个整数" << endl;
    for (int i = 0; i < a.nums; i++)
    {
        in >> a.elems[i];
    }
    return in;
}
ostream &operator<<(ostream &out, Array &a)
{
    int c = 0;
    for (int i = 0; i < a.nums; i++)
    {
        out << setw(6) << a.elems[i];
        if (++c % 5 == 0)
        {
            out << endl;
        }
    }
    out << endl;
    return out;
}
int main()
{
    Array m(16);
    cin >> m;
    cout << "数组m: \n";
    cout << m;
}