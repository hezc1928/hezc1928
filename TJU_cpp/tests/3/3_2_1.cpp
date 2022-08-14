#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int times = 0;
    cout << "input the size of matrix " << endl;
    cin >> n;
    int *p = new int[n * n];
    cout << "input n*n numbers for a n*n matrix " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> *(p + i * n + j);
        }
        cout << "next row" << endl;
    }
    for (int j = 0; j < n; j++)
    {
        cin >> *(p + (n - 1) * n + j);
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int temp = *(p + i * n + j);
            *(p + i * n + j) = *(p + j * n + i);
            *(p + j * n + i) = temp;
        }

    cout << "After transposed: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(p + n * i + j) << "  ";
            times++;
            if (times == n)
            {
                cout << endl;
                times = 0;
            }
        }
    }
}
