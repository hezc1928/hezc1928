#include <iostream>
using namespace std;
int main()
{
    int a[11] = {2, 4, 5, 8, 12, 14, 16, 18, 20, 30, 0};
    int b(0);
    cin >> b;
    for (int i = 0; i < 11; i++)
    {
        if (b < a[i])
        {
            for (int j = 0; j < 11 - i; j++)//每位用前一位代替，倒序进行
            {
                a[10 - j] = a[9 - j];
            }
            a[i] = b;
            i = 11;
        }
        else if (i == 10)//如果i到了10还没进入刚刚的if，说明b比a里面的元素都大，放到最后一位即可
        {
            a[10] = b;
        }
    }
    for (int k = 0; k < 11; k++)
    {
        cout << a[k] << ' ';
    }
    return 0;
}