#include <iostream>
using namespace std;
int d = 1;
void ff(int p)
{
    int d = 5;
    ::d += p++;
    cout << ::d << endl;
}
int main()
{
    int a = 2;
    ff(a);
    d += a++;
    cout << d;
}