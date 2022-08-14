#include <iostream>
using namespace std;
int main()
{
    bool flag[1000]; //估算第100个质数小于1000
    int s = 0;
    for (int i = 0; i < 1000; i++)
    {
        flag[i] = true; //初始化，全都设置成true
    }
    for (int i = 2; i * i <= 1000; i++)
    {
        if (flag[i] == true)
        {
            for (int j = i * i; j < 1000; j = j + i)//运算主体
            {
                flag[j] = 0;
            }
        }
    }
    for (int i = 2; i < 1000; i++)
    {
        if (flag[i] == 1)
        {
            cout << i << " ";
            s++;
        }
        if (s == 100)
            break;
    }
    return 0;
}