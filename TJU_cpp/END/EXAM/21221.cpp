/*************************************************************************
?????? row pointer
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
//void fun(int a, int b = 10, char *c = "*");
int main()
{
    //fun(1, 2);
    // cin >> str;
    // cin >> *str;
    // cin >> p;
    // p = "abcd";
    // cout << p << endl;
    // cout << *p << endl;
    char str[20], p;
    p = 'A';
    for (int i = 0; i < 4; i++)
    {
        cout << p++ << ' ' << endl;
    }

    // int a[10] = {};
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << sizeof(a) << endl;

    //cout << p << endl;
    return 0;
}
