#include <iostream> //递归方法
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
    if (s1[0] != '\0')
    {
        if (s1[0] == s2)
        {
            for (int j = 0; s1[j] != '\0'; j++)
            {
                s1[j] = s1[j + 1];
            }
            delchar(s1, s2);
        }
        else
        {
            delchar(s1 + 1, s2);
        }
    }
    return s1;
    // if没执行到最后一个
    // 就判断一个；
    // 递归调用下一个
}