#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int fun(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
    return n;
}
int main()
{
    // int *a, n;
    // a = new int[10]{0};
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> a[i];
    // }
    // n = fun(a, 10);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // ofstream outFile ("E:\\cpp_project\\TJU_cpp\tests\\9",ios::out);
    char s[] = "ab23";
    cout << sizeof(s)<< strlen(s) << endl;
    return 0;
}