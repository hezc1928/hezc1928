/*************************************************************************
P291 二分查找
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
template <typename T>
int BinSearch(T A[], int low, int high, T key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        if (key < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, i;
    int k(7); //给定要查找的值
    i = BinSearch(a, 0, 7, k);
    if (i == -1)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << i << endl;
    }
    return 0;
}