#include <iostream>
using namespace std;
int main()
{
    int m = 3;//m是待测的整数
    int i = 0;//i是每次循环的计数
    int seq[100] = {0};//seq是色情的简写，意思是刚刚运算出的质数表
    seq[0] = 2;
    cout << 2 << " ";
    while (seq[99] == 0)
    {
        if (seq[i] != 0)
        {
            if (m % seq[i] == 0)//如果m能被seq整除，就说明m不是质数，执行m++
            {
                m++;
                i = 0;
            }
            else//如果m不能被现在这个seq[i]整除，我们就看下一个seq[i+1]能不能整除
            {
                i++;
            }
        }
        else//如果seq[i]==0，就会进到这里，这时候就说明已经把前面的质数都试了一遍了，那么现在的m就是下一个质数
        {
            cout << m << " ";
            seq[i] = m;
            i = 0;
            m++;
        }
    }
    return 0;
}
