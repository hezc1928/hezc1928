#include <iostream>
using namespace std;
int absv(int x);
float absv(float x);
double absv(double x); //���ܽ�abs����Ϊ�Ѿ���std�����ռ��Ѿ������������
int main()
{
    int a(-3), b(4);
    float c(-5.2), d(8.3);
    double e(-5.352), f(0.524);
    cout << "the abs of a is " << absv(a) << "\nthe abs of b is " << absv(b) << endl;
    cout << "the abs of c is " << absv(c) << "\nthe abs of d is " << absv(d) << endl;
    cout << "the abs of e is " << absv(e) << "\nthe abs of f is " << absv(f) << endl;
    return 0;
}
int absv(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}
float absv(float x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}
double absv(double x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}