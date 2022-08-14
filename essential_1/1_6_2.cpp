#include <string>
#include <iostream>
using namespace std;
int main()
{
    int ival = 1024;
    ival;                  //计算ival的值
    &ival;                 //计算ival的内存地址
    int *pi = &ival;       //将pi的初值设置为ival所在的内存地址
    cout << pi << '\n'     //输出地址
         << *pi << '\n'    //输出1024,即在pi前面加*号,代表对*pi所指位置的对象进行操作
         << &ival << '\n'  //输出地址
         << ival << endl;  //输出1024
    if (pi && *pi != 1024) //防止该指针的地址为0
    {
        *pi = 1024;
    }
    
    return 0;
}