#include <string>
#include <iostream>
using namespace std;
int main()
{
    int ival = 1024;
    ival;                  //����ival��ֵ
    &ival;                 //����ival���ڴ��ַ
    int *pi = &ival;       //��pi�ĳ�ֵ����Ϊival���ڵ��ڴ��ַ
    cout << pi << '\n'     //�����ַ
         << *pi << '\n'    //���1024,����piǰ���*��,�����*pi��ָλ�õĶ�����в���
         << &ival << '\n'  //�����ַ
         << ival << endl;  //���1024
    if (pi && *pi != 1024) //��ֹ��ָ��ĵ�ַΪ0
    {
        *pi = 1024;
    }
    
    return 0;
}