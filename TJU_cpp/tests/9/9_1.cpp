#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char *temp;
    cout << "����һ���ַ�����#��Ϊ��β" << endl;
    temp = new char[999]{};
    ofstream ofile("9_1.txt", ios::out | ios::binary);
    for (int i = 0; i < 999; i++)
    {
        cin >> *(temp + i);
        if (*(temp + i) != '#')
        {
            ofile.write((char *)(temp + i), sizeof(char));
        }
        if (*(temp + i) == '#')
        {
            ofile.put('\n');
            i = 99999;
        }
    }
    ofile.close();
    return 0;
}
