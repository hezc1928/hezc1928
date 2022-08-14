#include <iostream> //非递归方法
using namespace std;
char *delchar(char *s1, char s2);
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
    cout << "input the character to delete" << endl;
    cin >> s2;
    cout << "after delete we got : "
         << delchar(s1, s2) << endl;
    delete[] s1;
    return 0;
}
char *delchar(char *s1, char s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2)
        {
            for (int j = 0; s1[i + j] != '\0'; j++)
            {
                s1[i + j] = s1[i + j + 1];
            }
            i--;
        }
    }
    return s1;
}
