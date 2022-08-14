/*************************************************************************
P224 格式化输入输出
**************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
    cout << "012345678901234567890\n";
    cout << setw(12) << setfill('*') << 1234 << endl
         << setw(12) << setiosflags(ios::left) << 1234 << endl
         << setw(12) << resetiosflags(ios::left) << 1234 << endl
         << setw(12) << setfill('$') << setprecision(5) << 12.34567 << endl;
    int *a;
    a = new int[3];
    cout << "012345678901234567890\n";
    cout << a << endl;
    cout << oct << a << endl;
    return 0;
}