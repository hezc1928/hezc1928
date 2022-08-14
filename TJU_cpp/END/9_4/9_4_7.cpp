#include <iostream>
using namespace std;
void printA(int a[], int n)
{
    int *b;
    b = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                b[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!b[i])
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    int n = 10;
    int a[10] = {0, 2, 3, 3, 2, 1, 1, 2, 3, 5};
    printA(a, n);
    return 0;
}