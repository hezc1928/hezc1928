#include <iostream>
using namespace std;
int find(char a[], char ch);
int main()
{
    char *s1;
    char s2;
    int n(0);
    cout << "input the size" << endl;
    cin >> n;
    cout << "input the data" << endl;
    s1 = new char[n];
    cin >> s1;
    cout << "input the character to find" << endl;
    cin >> s2;
    cout << "at the " << find(s1, s2) << " digit we find the first " << s2 << endl;
    delete[] s1;
    return 0;
}
int find(char a[], char ch)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ch)
        {
            return i + 1;
        }
    }
    return 0;
}