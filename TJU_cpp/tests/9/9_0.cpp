#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // char *s1 = "ABCDE", *s2 = "123456";
    // ofstream outfile("data2.txt");
    // outfile.write(s2, 3).put('*').write(s1, 7);
    // char s[30] = "C++ IO stream";
    // outfile.seekp(6, ios::beg);
    // outfile << s;
    int a[4] = {65, 67, 97, 98}, i;
    ofstream ofile("data1.txt", ios::out | ios::binary);
    for (int i = 0; i < 4; i++)
    {
        ofile.write((char *)&a[i], sizeof(int));
    }
    ofile.close();
    return 0;
}