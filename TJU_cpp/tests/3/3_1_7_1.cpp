#include <iostream>
using namespace std;
int main()
{
    char str[10] = "abcdefghi";
    char a[10] = "qwertyuio";
    char *ps = a;
    char temp = 'a';
    cout << str << endl;
    cout << ps << endl;
    for (int i = 0; i < 10; i++)
    {
        temp = *(str + i);
        *(str + i) = *(ps + i);
        *(ps + i) = temp;
    }
    cout << "after changed: " << endl;
    cout << str << endl;
    cout << ps << endl;
    return 0;
}
