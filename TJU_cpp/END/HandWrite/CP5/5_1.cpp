/*************************************************************************
white P151 构造函数的调用次数
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
    test a(1), b[2] = {2, 3}; //执行3次
    test c[3];                //执行3次

    cout << "d" << endl;
    test *d; //不执行
    cout << "d" << endl;
    d = new test[3]; //执行3次

    cout << "e" << endl;
    test *e[3]; //不执行
    cout << "e" << endl;
    int n = 4;
    *e = new test[n]; //执行n次

    cout << "f" << endl;
    test f(a); //执行1次拷贝构造函数
    return 0;
}