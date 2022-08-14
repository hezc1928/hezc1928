#include <iostream>
using namespace std;
int main()
{
    char s[80] = "abaabcdabfabbabfabfv";
    const char ch = 'a';
    int i, j;
    for (i = j = 0; s[i]; i++)
    {
        if (s[i] != ch)
        {
            s[j] = s[i];
            j++;
        }
        s[j] = 0;
        
    }
    cout << s << endl;
}