#include <iostream>
using namespace std;
int main()
{
    char ch;
    cin >> ch;
    int num;
    num = (int)ch;
    if (num > 47 && num < 58)
    {
        cout << "����" << endl;
    }
    else if (num > 64 && num < 91)
    {
        cout << "��д��ĸ" << endl;
    }
    else if (num > 96 && num < 123)
    {
        cout << "Сд��ĸ" << endl;
    }
    else
    {
        cout << "�����ַ�" << endl;
    }
    return 0;
}