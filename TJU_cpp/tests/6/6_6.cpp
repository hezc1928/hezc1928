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
        cout << d << endl;
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
    int IsOdd()
    {
        if (d % 2 != 0)
        {
            cout << "������" << endl;
            return 0;
        }
        else
        {
            cout << "��ż��" << endl;
            return 1;
        }
        return -1;
    }
    int IsPrime()
    {
        int i = 2;
        for (i = 2; i * i < d; i++)
        {
            if (d % i == 0)
            {
                i = d;
            }
        }
        if (i == d + 1)
        {
            cout << "��������" << endl;
            return 0;
        }
        else
        {
            cout << "������" << endl;
            return 1;
        }
        return -1;
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
    int b = 15;
    Interger a;
    a.SetD(b);
    a.GetD();
    a.IsOdd();
    a.IsPrime();
    a.~Interger();
    b = 31;
    a.SetD(b);
    a.GetD();
    a.IsOdd();
    a.IsPrime();
    a.~Interger();
    return 0;
}
