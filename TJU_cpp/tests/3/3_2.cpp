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
// ��д����ʵ�ֽ�һ��n*n�ľ�������л���������Ļ�����������ľ��󡣾���Ҫ�����£�
// ��1��n�ɼ������룬��������̬�����ž���Ԫ�أ�
// ��2��ͨ�������������Ԫ�ص�ֵ��
// ��3��������ֻ����һ�����顣
// ��4�����ʱ���������һ��n������ÿ����ռ6����ȡ�
