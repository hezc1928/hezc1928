#include <iostream>
using namespace std;
int main()
{
    char str[10] = "abcdefghi";
    char a[10] = "qwertyuio";
    char *ps = a;
    char *tpl;
    tpl = new char[10];
    char temp = 'a';
    cout << str << endl;
    cout << ps << endl;
    for (int i = 0; i < 10; i++)
    {
        *(tpl + i) = *(str + i);
        *(str + i) = *(ps + i);
        *(ps + i) = *(tpl + i);
    }
    delete tpl;
    cout << "after changed: " << endl;
    cout << str << endl;
    cout << ps << endl;
    return 0;
}
