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
    cout << 1234 << endl;
    cout.width(12);
    cout << 1234 << endl;
    cout.fill('*');
    cout << 1234 << endl;
    cout.flags(ios::left);
    cout.width(12);
    cout << 1234 << endl;
    cout.flags(ios::right);
    cout.width(12);
    cout << 1234 << endl;
    cout.precision(5);
    cout << 123.45678 << endl;
    return 0;
}