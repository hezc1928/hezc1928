/*************************************************************************
P224 ��ʽ���������
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
    cout.setf(ios::oct);
    cout << "dec:94 -> oct:" << 94 << endl; //��һ��û��
    cout << "dec:94 -> oct:" << oct << 94 << endl;
    cout.setf(ios::hex | ios::showbase);
    cout << "dec:94 -> hex:" << hex << 94 << endl;
    cout.unsetf(ios::showbase);
    cout.flags(ios::uppercase | ios::hex);
    cout << "dec:94 -> hex:" << 94 << endl;
    return 0;
}