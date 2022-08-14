/*************************************************************************
���ظ��������
P196 ++�����������
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
    cout << "��ǰxֵ��һ";
    c.print();
    ++(++c);
    cout << "��ǰxֵ�������μ�һ";
    c.print();
    c++;

    cout << "�Ե�ǰxֵ��12";
    c.print();
    (c++)++;

    cout << "c�����xֵ";
    c.print();
    return 0;
}