#include <iostream>
using namespace std;
void InsSort(int x[], int n)
{
    int i(0), j(0), k(0);
    for (int i = 1; i < n; i++)
    {
        k = x[i];
        j = i;
        while (k < x[j - 1] && j > 0)
        {
            x[j] = x[j - 1];
            j--; //�����һλ��ʼ���룬��ǰѰ�ң����������С�ں�������ֹͣ���롣
        }
        x[j] = k;
    }
}
int main()
{
    // int a[6] = {43, 5, 4, 2, 5, 3};
    // InsSort(a, 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // 09101 һ.12
    // int x[10];
    // int *p = x + 2;
    // x[2] = *p + 2;
    // *p = *x;
    // p = x + 5;
    // x = p + 5;
    return 0;
}