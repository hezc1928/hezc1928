#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    // int t;
    // t = *x;
    // *x = *y;
    // *y = t;
    int *t;
    t = x;
    cout << x << endl;
    x = y;
    cout << x << endl;
    y = t;
    cout << *x << " " << *y << endl;
}
int main()
{
    // һ.8
    // int x, a(0), b(2);
    // x = a++ && b++ || ++b;
    // cout << x << " " << a << " " << b << " " << endl;
    // һ.11
    // int *a, *b;
    // a = new int;
    // b = new int;
    // *a = 1;
    // *b = 2;
    // cout << a << endl;
    // swap(a, b);
    // cout << *a << " " << *b << endl;
    return 0;
}