/*************************************************************************
white P151 ���캯���ĵ��ô���
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
class test
{
private:
    int x;

public:
    test(int i);
    test(const test &a)
    {
        x = a.x;
        cout << "copy construct" << x;
    }
    test(test &a)
    {
        x = a.x;
        cout << "copy construct" << x;
    }
    ~test();
};

test::test(int i = 1)
{
    x = i;
    cout << "construct: " << i << endl;
}

test::~test()
{
}

int main()
{
    test a(1), b[2] = {2, 3}; //ִ��3��
    test c[3];                //ִ��3��

    cout << "d" << endl;
    test *d; //��ִ��
    cout << "d" << endl;
    d = new test[3]; //ִ��3��

    cout << "e" << endl;
    test *e[3]; //��ִ��
    cout << "e" << endl;
    int n = 4;
    *e = new test[n]; //ִ��n��

    cout << "f" << endl;
    test f(a); //ִ��1�ο������캯��
    return 0;
}