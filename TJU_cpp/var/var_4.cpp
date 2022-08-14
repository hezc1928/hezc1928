#include <iostream>
using namespace std;
int main()
{
    int a[10], amax, amin;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    amax = amin = a[0];
    int i = 0;
    while (i++ < 9)
    {
        if (a[i] > amax)
        {
            amax = a[i];
        }
        if (a[i] < amin)
        {
            amin = a[i];
        }
    }
    cout << "maxinum is " << amax << endl;
    cout << "mininum is " << amin << endl;
}