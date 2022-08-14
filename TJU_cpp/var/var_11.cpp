#include <iostream>
using namespace std;

int main()
{
    int a[5], i, sum1, sum2;
    cout << "input five numbers:" << endl;
    const int count = 5;

    for (i = 0; i < count; i++)
    {
        cin >> *(a + i);
    }
    for (i = 0, sum1 = 0; i < count; i++)
    {
        sum1 += *(a + i);
    }
    for (i = 0, sum2 = 0; i < count; i++)
    {
        sum2 += a[i];
    }
    cout << "sum1=" << sum1 << endl;
    cout << "sum2=" << sum2 << endl;
}