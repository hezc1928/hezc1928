#include <iostream>
using namespace std;
int main()
{
    char s[80] = "abaabaaabb";
    const char ch = 'a';
    char *ps1, *ps2;
    ps1 = ps2 = s;
    while (*ps1)
    {
        if (*ps1 != ch)
        {
            *ps2 = *ps1;
            ps2++;
        }
        ps1++;
    }
    *ps2 = 0;
    cout << s << endl;
}