#include <iostream>//派生类调用构造函数示例
using namespace std;
class A
{
private:
    int a;

public:
    A(int i);
    A()
    {
        cout << "A default" << endl;
    }
    ~A();
};

A::A(int i)
{
    a = i;
    cout << "A constructed" << endl;
}

A::~A()
{
    cout << "A destructed" << endl;
}
class B : public A
{
private:
    int j;
    //A AAA;

public:
    B(int i);
    ~B();
};

B::B(int i) : A(i)
{
    cout << "B constructed" << endl;
}

B::~B()
{
    cout << "B destructed" << endl;
}
int main()
{
    int a = 1;
    //A AAA(a);
    cout << "*********************" << endl;
    B BBB(a);
}