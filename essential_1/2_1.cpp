#include <iostream>
//#include <cstdlib>
using namespace std;
bool fibon_elem(int pos, int &elem) //Ϊ�˽��������ֵ����룬�����ĳ��˲�������
{
    if (pos <= 0 || pos > 1024) //�����쳣�������õ���exit(-1);
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 2; ix < pos; ++ix) //�������岿��
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
    cout << "��������Ҫ��λ��";
    cin >> pos;
    int elem;
    if (fibon_elem(pos, elem))
    {
        cout << "element #" << pos << " is " << elem << endl;
    }
    else
    {
        cout << "����0-1024�м�����ְ�" << endl;
    }
}