#include <iostream>
using namespace std;
#define SIZE 20
int main()
{

    //char a[] = "hezc 1928 # 5849";
    char *a;
    int na;
    cin >> na;
    a = new char[na];
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
    cout << "stu" << endl;
    char *b;
    int n;
    cin >> n;
    b = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    bool flag = 0;
    cout << "stu" << endl;
    for (int i = 0; i < 20; i++)
    {
        if (a[i] == b[i])
        {
            flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[i + j] != b[i + j])
                {
                    flag = 0;
                }
            }
        }
    }
    if (flag)
    {
        cout << "exists" << endl;
        cout << b << endl;
        cout << n;
    }

    return 0;
}