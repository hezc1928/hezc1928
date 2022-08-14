/*************************************************************************
重载各种运算符
P196 ++运算符的重载
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
class sample
{
private:
    int x;

public:
    sample(int i = 0)
    {
        x = i;
    }
    void print()
    {
        cout << "x=" << x << endl;
    }
    sample &operator++();
    sample operator++(int);
    ~sample()
    {}
};
sample &sample::operator++()
{
    ++x;
    return *this;
}
sample sample::operator++(int)
{
    sample t = *this;
    x += 12;
    return *this;
}

int main()
{
    sample c(3);
    cout << "the original value of c.x is ";
    c.print();
    ++c;
    cout << "当前x值加一";
    c.print();
    ++(++c);
    cout << "当前x值连续两次加一";
    c.print();
    c++;

    cout << "对当前x值加12";
    c.print();
    (c++)++;

    cout << "c的最后x值";
    c.print();
    return 0;
}