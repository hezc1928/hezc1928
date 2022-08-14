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
            cout << "小于零，已修正" << endl;
        }
        else
        {
            d = a;
            cout << "赋值成功" << endl;
        }
    }
    int IsOdd()
    {
        if (d % 2 != 0)
        {
            cout << "是奇数" << endl;
            return 0;
        }
        else
        {
            cout << "是偶数" << endl;
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
            cout << "不是质数" << endl;
            return 0;
        }
        else
        {
            cout << "是质数" << endl;
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
        cout << "小于零，已修正" << endl;
    }
    else
    {
        cout << "创建新对象成功" << endl;
    }
}

Interger::~Interger()
{
    cout << "析构完毕" << endl;
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
