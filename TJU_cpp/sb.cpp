#include <iostream>
#include <cstring>
#include <list>
using namespace std;

void tuige()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << i << " " << j << ",";
        }
        cout << "\b";
        cout << " ";
        cout << "\n"; //��\bʵ���˸��ǿ��Եģ�����������������ã����һ���֮ǰҪ�Ӹ��ո�
    }
}
void anweifenjie() //��λ�ֽ�
{
    int b = 1;
    int dig[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 1; i < 11; i++)
    {
        b *= i;
        int a = b;
        int j = 0;
        while (a)
        {
            dig[j] = a % 10 + 48;

            a /= 10;
            j++;
        }
        for (int k = 0; k < j; k++)
        {
        }
    }
}
class human
{
private:
    char *FamilyName;
    char *SelfName;
    char *Bias;
    char *Job;
    int Age;

public:
    human(char *a, char *b, char *c, char *d, int f)
    {
        FamilyName = new char[strlen(a) + 1];
        strcpy(FamilyName, a);
        SelfName = new char[strlen(b) + 1];
        strcpy(SelfName, b);
        Bias = new char[strlen(c) + 1];
        strcpy(Bias, c);
        Job = new char[strlen(d) + 1];
        strcpy(Job, d);
        Age = f;
    }
    void print()
    {
        cout << "��:" << FamilyName << endl;
        cout << "��:" << SelfName << endl;
        cout << "�Ա�:" << Bias << endl;
        cout << "ְҵ:" << Job << endl;
        cout << "����:" << Age << endl;
    }
    ~human()
    {
        delete[] FamilyName;
        delete[] SelfName;
        delete[] Bias;
        delete[] Job;
        FamilyName = SelfName = Bias = Job = 0;
        Age = 0;
    }
};
class family : public human
{
};
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    // human guojing("��", "��", "��", "����ְҵ", 19);
    // guojing.print();
    int a;
    a = 31;
    int b;
    b = 00000000 << a;
    // b = ~b;
    // cout << b;
    int c = 32;
    return 0;
}
