#include <iostream>
using namespace std;
#define SIZE 20
int main()
{
    int *a;
    a = new int[SIZE + 1]{0};
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = i * i * i;
    }
    int b;
    cin >> b;
    int i(0);
    int j(0);
    while (!(i >= SIZE || i < -1 || j > SIZE + 3))
    {
        if (b > a[i])
        {
            i++;
            j++;
        }
        else if (b == a[i])
        {
            i = 99999;
        }
        else
        {
            j++;
        }
    }
    if (i == 99999)
    {
        cout << "find" << endl;
    }
    else
    {
        for (int j = SIZE + 1; j > i-1; j--)
        {
            a[j + 1] = a[j];
        }
        a[i] = b;
    }
    cout << i << endl;
    for (int i = 0; i < SIZE + 1; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}