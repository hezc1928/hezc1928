#include <iostream>
using namespace std;
int main()
{
    bool flag[1000]; //�����100������С��1000
    int s = 0;
    for (int i = 0; i < 1000; i++)
    {
        flag[i] = true; //��ʼ����ȫ�����ó�true
    }
    for (int i = 2; i * i <= 1000; i++)
    {
        if (flag[i] == true)
        {
            for (int j = i * i; j < 1000; j = j + i)//��������
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