#include <iostream>
//#include <cstdlib>
using namespace std;
bool fibon_elem(int pos, int &elem) //为了解决各种奇怪的输入，函数改成了布尔类型
{
    if (pos <= 0 || pos > 1024) //处理异常，本来用的是exit(-1);
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 2; ix < pos; ++ix) //运算主体部分
    {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}
int main()
{
    int pos;
    cout << "输入你想要的位置";
    cin >> pos;
    int elem;
    if (fibon_elem(pos, elem))
    {
        cout << "element #" << pos << " is " << elem << endl;
    }
    else
    {
        cout << "换个0-1024中间的数字吧" << endl;
    }
}