#include <iostream>
using namespace std;

int main()
{
    char s[80] = "abaabcdabfabbabfabfv";
    const char ch = 'a';
    char *ps1, *ps2;
    ps1 = ps2 = s;

    while (*ps1)
        *ps1 != ch ? *ps2 = *ps1, ps2++, ps1++ : ps1++;

    // sb:
    //     if (*ps1)
    //     {
    //         *ps1 != ch ? *ps2 = *ps1, ps2++, ps1++ : ps1++;
    //         goto sb;
    //     } /*这里还是用if和goto写了个while出来*/

out:
    *ps2 = 0;
    cout << s << endl;
    // *ps1 ? *ps2 = 0, cout << s << endl : *ps1 != ch ? *ps2 = *ps1, ps2++, ps1++, goto sb : ;
    // system("pause");请按任意键继续……
    return 0;
}