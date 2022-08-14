#include <iostream>
using namespace std;
int yue(int m, int n);
int bei(int m, int n);
int main()
{
    int a(0), b(0);
    cout << "input a and b pls " << endl;
    cin >> a;
    cin >> b;
    cout << "最大公约数是" << yue(a, b) << endl;
    cout << "最小公倍数是" << bei(a, b) << endl;
    return 0;
}
int yue(int m, int n)
{
    int temp;
    while (m - n != 0)
    {
        if (m >= n)
        {
            return yue(m - n, n);
        }
        else
        {
            return yue(n - m, m);
        }
    }
    return n;
}
int bei(int m, int n)
{
    return m * n / yue(m, n);
}
