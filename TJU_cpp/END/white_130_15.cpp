#include <iostream>
using namespace std;
int *ff(int n, int s[])
{
    int &m = s[n];
    return &m;
}
int main()
{
    int *a;
    cout << a << endl;
    int s[] = {5, 4, 3, 2, 1};
    *ff(3, s) = 10;
    cout << ff(3, s) << endl;
}