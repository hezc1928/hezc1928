#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char *temp;
    temp = new char[999]{};
    ofstream letter("E:\\cpp_project\\TJU_cpp\\tests\\9\\9_3_1.txt", ios::out | ios::binary);
    ofstream number("E:\\cpp_project\\TJU_cpp\\tests\\9\\9_3_2.txt", ios::out | ios::binary);
    cout << "输入一串字符并以#作为结尾" << endl;
    for (int i = 0; i >=0; i++)
    {
        cin >> *(temp + i);
        if ((*(temp + i) >= 65 && *(temp + i) <= 90) || (*(temp + i) >= 97 && *(temp + i) <= 122))
        {
            letter.write((char *)(temp + i), sizeof(char));
        }
        if ((*(temp + i) >= 48 && *(temp + i) <= 57))
        {
            number.write((char *)(temp + i), sizeof(char));
        }
        if (*(temp + i) == '#')
        {
            i = -2;
        }
    }
    cout << temp;
    letter.close();
    number.close();
    cout << endl;
    cout << "write successfully" << endl;
    return 0;
}
