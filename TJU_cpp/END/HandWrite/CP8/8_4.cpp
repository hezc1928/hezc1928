/*************************************************************************
P216 ÊäÈëÁ÷º¯Êı
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
    ofstream tstfle("test.txt", ios::out);
    tstfle.write("iuspoisjeifoisjpoiej", 20);
    tstfle.put('\n');
    tstfle.write("hezc1928#5849", 13);
    tstfle << endl;
    for (int i = 1; i < 129; i++)
    {
        tstfle.put(i);
        tstfle << '\t';
        if (i % 16 == 0)
        {
            tstfle << endl;
        }
    }
    tstfle.put('\n');
    tstfle << 123 << endl;
    cout << "complete" << endl;
    return 0;
}
