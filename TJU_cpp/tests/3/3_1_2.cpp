#include <iostream>
using namespace std;
int main()
{
    int a[10] = {0};
    int sum(0), high(0), fail(0);
    for (int i = 0; i < 10; i++)
    {
        cout << "������� " << i + 1 << " ���ɼ�" << endl;
        cin >> a[i];
        if (a[i] < 0 || a[i] > 100)
        {
            i--;
            cout << "�����ˣ�������" << endl;
        }
        sum += a[i];
    }
    for (int j = 0; j < 10; j++)
    {
        if (a[j] > sum / 10)
        {
            high++;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        if (a[j] < 60)
        {
            fail++;
        }
    }
    cout << fail << " students failed " << endl;
    cout << high << " students' score is higher than average " << endl;
    return 0;
}
