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
void BinInsertionSort(T e[], int n)
{
    int i, j, temp;

    int high, low, mid;
    for (int i = 1; i < n; i++)
    {
        temp = e[i];
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (temp < e[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= low; j--)
        {
            e[j + 1] = e[j];
        }

        e[low] = temp;
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
    BinInsertionSort(a, 15);
    cout << endl
         << "after sort" << endl;
    PrintList(a, 15);
    return 0;
}