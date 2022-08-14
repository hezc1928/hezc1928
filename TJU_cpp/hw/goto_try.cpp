#include<iostream>
using namespace std;
int main()
{
    int a=1;
    a?goto abc:goto bcd;
    abc:
        cout<<"abc"<<endl;
    bcd:
        cout<<"bcd"<<endl;
    return 0;
}
