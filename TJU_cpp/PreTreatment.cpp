#define _X86 hezc
#define TJU 1895
#define shuchu cout
#define exp(s) printf("test s is:%s\n", s)
#define exp1(s) printf("test s is:%s\n", #s)
#define exp2(s) #s
#ifdef _X86
#pragma message("_X86 macro activated!")
#endif
#include <iostream>
using namespace std;
int main()
{
     cout << "abc"
          << "TJU" << TJU << endl;
     shuchu << "TJU" << '\n'
            << 'TJU' << '\n'
            << 'T' << '\n'
            << 'J' << '\n'
            << 'U' << '\n'
            << TJU << endl;
     exp("hello");
     exp1(hello);

     string str = exp2(bac);
     cout << str << " " << str.size() << endl;
     /**
     * ���Դ��������ǰ��ͺ���Ŀո�
     */
     string str1 = exp2(asda bac);
     /**
     * ���������������ڿո�ʱ�������������Զ����Ӹ������ַ�����
     * ��ÿ�����ַ���֮����һ���ո����ӣ�����ʣ��ո�
     */
     cout << str1 << " " << str1.size() << endl;
     return 0;
}