#include <iostream>
using namespace std;
void fun(int a[], int n)
{
    int temp = a[n - 1];
    for (int i = n; i > -1; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = temp;
}
int main()
{
    int *a;
    a = new int[10];
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun(b, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}