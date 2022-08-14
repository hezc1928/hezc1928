#include <iostream>
using namespace std;
#define SIZE 4
int main()
{
    int *a;
    a = new int[SIZE * SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a[4 * i + j] = 4 * i + j;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << a[4 * i + j] << " ";
        }
        cout << endl;
    }

    float *b;
    b = new float[SIZE]{0};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            b[i] += a[4 * i + j];
        }
        b[i] /= SIZE;
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}