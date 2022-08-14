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
        cout << "Êı×Ö" << endl;
    }
    else if (num > 64 && num < 91)
    {
        cout << "´óĞ´×ÖÄ¸" << endl;
    }
    else if (num > 96 && num < 123)
    {
        cout << "Ğ¡Ğ´×ÖÄ¸" << endl;
    }
    else
    {
        cout << "ÆäËû×Ö·û" << endl;
    }
    return 0;
}