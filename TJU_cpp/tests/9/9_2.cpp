#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("9_1.txt", ios::in | ios::binary);
    for (int i = 0; i < 999; i++)
    {
        char temp;
        infile.get(temp);
        cout << temp;
        if (temp == '\n')
        {
            i = 9999;
        }
    }
    infile.close();
    cout << endl;
    return 0;
}
