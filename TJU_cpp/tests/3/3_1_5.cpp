#include <iostream>
using namespace std;
int main()
{
    int a[11] = {2, 4, 5, 8, 12, 14, 16, 18, 20, 30, 0};
    int b(0);
    cout << "input a number " << endl;
    cin >> b;
    for (int i = 0; i < 11; i++)
    {
        if (b < a[i])
        {
            for (int j = 0; j < 11 - i; j++)//ÿλ��ǰһλ���棬�������
            {
                a[10 - j] = a[9 - j];
            }
            a[i] = b;
            i = 11;
        }
        else if (i == 10)//���i����10��û����ոյ�if��˵��b��a�����Ԫ�ض��󣬷ŵ����һλ����
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
