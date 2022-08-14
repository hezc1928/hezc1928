/*************************************************************************
P297 ¶þ·Ö²åÈë
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
template <typename T>
void SelectionSort(T e[], int n)
{
    int i, j, k, temp;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (e[j] < e[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            temp = e[i];
            e[i] = e[k];
            e[k] = temp;
        }
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
    SelectionSort(a, 15);
    cout << endl
         << "after sort" << endl;
    PrintList(a, 15);
    return 0;
}