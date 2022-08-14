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
    int temp(0);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            temp = a[4 * i + j];
            a[4 * i + j] = a[4 * j + i];
            a[4 * j + i] = temp;
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
    delete[] a;
    return 0;
}