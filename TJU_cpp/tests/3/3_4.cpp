#include <iostream>
using namespace std;
int main()
{
    int n(0), temp(0);
    cout << "���������ݸ���" << endl;
    cin >> n;
    int *b = NULL;
    b = new int[n]{0};
    cout << "����������" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] <= 0)
        {
            cout << "����������������������" << endl;
            i--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] % 5 != 0)
        {
            b[i] = -1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n - 1 - j; k++)
        {
            if (b[k] < b[k + 1])
            {
                temp = b[k];
                b[k] = b[k + 1];
                b[k + 1] = temp;
                temp = 0;
            }
        }
    }
    cout << "�ܱ�5��������";
    for (int k = 0; k < n && b[k] != -1; k++)
    {
        cout << b[k] << " ";
    }

    delete[] b;
}
