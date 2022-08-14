#include <iostream>
using namespace std;
int factorial(int a);
int sigma(int a);
int main()
{
    int m(0), n(0);
    for (int i = 0; i < 1; i++)
    {
        cout << "input an intergal m" << endl;
        cin >> m;
        cout << "input an intergal n" << endl;
        cin >> n;
        if (m > n)
        {
            int s1(0), s2(0);
            s1 = factorial(m) / (factorial(n) * factorial(m - n));
            s2 = sigma(m) - sigma(n);
            cout << "s1 = " << s1 << endl;
            cout << "s2 = " << s2 << endl;
        }
        else
        {
            cout << "m应当大于n!" << endl;
            i--;
        }
    }
    return 0;
}
int factorial(int a)
{
    if (a > 1)
    {
        a = a * factorial(a - 1);
        return a;
    }
    else
    {
        return 1;
    }
}
int sigma(int a)
{
    if (a > 1)
    {
        a += sigma(a - 1);
        return a;
    }
    else
    {
        return a;
    }
}
