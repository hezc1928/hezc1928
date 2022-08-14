#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cout << "input the size of matrix " << endl;
    cin >> n;
    int **a = NULL;
    a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n]{0};
    }
    cout << "input n*n numbers for a n*n matrix " << endl;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cout << "next row" << endl;
    }
    for (int j = 0; j < n; j++)
    {
        cin >> a[n-1][j];
    }
    cout << " after transposed: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(6) << a[j][i];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
// 编写程序实现将一个n*n的矩阵的行列互换，在屏幕上输出互换后的矩阵。具体要求如下：
// （1）n由键盘输入，并创建动态数组存放矩阵元素；
// （2）通过键盘输入矩阵元素的值；
// （3）程序中只能用一个数组。
// （4）输出时按行输出，一行n个数，每个数占6个宽度。
