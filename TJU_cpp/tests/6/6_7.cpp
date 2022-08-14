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
            cout << "小于零，已修正" << endl;
        }
        else
        {
            d = a;
            cout << "赋值成功" << endl;
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
    int b = 5;
    Interger a;
    for (int i = 2; i < 10; i++)
    {
        a.SetD(i);
        a.GetD();
        cout << "的阶乘是";
        a.factor();
    }
    return 0;
}