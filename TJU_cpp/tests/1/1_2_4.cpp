#include <iostream>
using namespace std;
void dafen(float score = 0)
{
    if (score >= 90 && score <= 100)
    {
        cout << "��ĳɼ���A" << endl;
    }
    else if (score >= 80 && score < 90)
    {
        cout << "��ĳɼ���B" << endl;
    }
    else if (score >= 60 && score < 80)
    {
        cout << "��ĳɼ���C" << endl;
    }
    else if (score >= 0 && score < 60)
    {
        cout << "��ĳɼ���D" << endl;
    }
}
int main()
{
    float a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cout << "������� " << i+1 << " ���ɼ�" << endl;
        cin >> a[i];
        if (a[i] < 0 || a[i] > 100)
        {
            i--;
            cout << "�����ˣ�������" << endl;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cout << "ѧ�� " << j << endl;
        dafen(a[j]);
    }
    return 0;
}
