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
    //     } /*���ﻹ����if��gotoд�˸�while����*/

out:
    *ps2 = 0;
    cout << s << endl;
    // *ps1 ? *ps2 = 0, cout << s << endl : *ps1 != ch ? *ps2 = *ps1, ps2++, ps1++, goto sb : ;
    // system("pause");�밴�������������
    return 0;
}