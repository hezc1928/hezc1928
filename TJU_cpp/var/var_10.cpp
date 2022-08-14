#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p1, *p2 = &a;
    p1 = p2;
    cout << "a=" << a << endl;
    cout << "*p1=" << *p1 << endl;
    cout << "p1=" << p1 << endl;
    cout << "*p2=" << *p2 << endl;
    /*  p1是地址，*p1是数据    */
    *p1 = 20;
    cout << "a=" << a << endl;
    cout << p1 << " " << p2 << " " << &a << endl;
}