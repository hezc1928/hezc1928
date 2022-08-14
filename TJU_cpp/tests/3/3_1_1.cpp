#include <iostream>
using namespace std;
int main()
{
    int a[10] = {0};
    int max(0), min(0), sum(0);
    cout << "input 10 intergers " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    min=a[9];
    min=a[9];
    for (int j = 0; j < 10; j++)
    {
        if (a[j] > max)
        {
            max = a[j];
        }
    }
    for (int j = 0; j < 10; j++)
    {
        if (a[j] < min)
        {
            min = a[j];
        }
    }
    cout << "max is " << max << "\nmin is " << min << endl;
    cout << "avr is " << sum / 10 << endl;
    return 0;
}
