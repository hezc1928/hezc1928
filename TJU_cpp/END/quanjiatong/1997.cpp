#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void reverse(char *s, int n)
{
    cout << 1 << endl;
    if (n > 1)
    {
        char temp;
        temp = *s;
        *s = *(s + n - 1);
        *(s + n - 1) = temp;
        reverse(s + 1, n - 2);
    }
}
int main()
{
    int n;
    cout << "input numbers";
    cin >> n;
    char *s = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    reverse(s, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    return 0;
}