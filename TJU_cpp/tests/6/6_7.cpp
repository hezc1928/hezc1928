#include <iostream>
using namespace std;
class Interger
{
private:
    int d;

public:
    Interger();
    ~Interger();
    int GetD()
    {
        cout << d;
        return d;
    }
    void SetD(int a)
    {
        if (a < 0)
        {
            SetD(-a);
            cout << "С���㣬������" << endl;
        }
        else
        {
            d = a;
            cout << "��ֵ�ɹ�" << endl;
        }
    }
    int factor()
    {
        int a = 1;
        for (int i = 1; i < d + 1; i++)
        {
            a *= i;
        }
        cout << a << endl;
        return a;
    }
};

Interger::Interger()
{
    if (d < 0)
    {
        SetD(-d);
        cout << "С���㣬������" << endl;
    }
    else
    {
        cout << "�����¶���ɹ�" << endl;
    }
}

Interger::~Interger()
{
    cout << "�������" << endl;
}

int main()
{
    int b = 5;
    Interger a;
    for (int i = 2; i < 10; i++)
    {
        a.SetD(i);
        a.GetD();
        cout << "�Ľ׳���";
        a.factor();
    }
    return 0;
}