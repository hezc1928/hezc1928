/*************************************************************************
P216 Êä³öÁ÷º¯Êý
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
    ifstream tstfle("test.txt", ios::in);
    char *ch;
    ch = new char[10];
    tstfle.get(ch, 15);
    cout << &ch << endl;
    for (int i = 0; i < 18&&ch[i]!='\0'; i++)
    {
        cout << ch[i] << " ";
    }
    cout << endl;
    
    cout << endl;
    
    cout << "complete" << endl;
    return 0;
}
