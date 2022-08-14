/*************************************************************************
P297 ÷±Ω”≤Â»Î≈≈–Ú
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
template <typename T>
void InsertionSort(T e[], int n)
{
    int i, j;
    T temp;
    for (int i = 1; i < n; i++)
    {
        temp = e[i];
        for (j = i - 1; j >= 0 && temp < e[j]; j--)
        {
            e[j + 1] = e[j];
        }
        e[j + 1] = temp;
    }
}
template <typename T>
void PrintList(T list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {36, 45, 32, 42, 35, 73, 25, 46, 23, 74, 47, 88, 64, 86, 53};
    cout << "original" << endl;
    PrintList(a, 15);
    InsertionSort(a, 15);
    cout << endl
         << "after sort" << endl;
    PrintList(a, 15);
    return 0;
}