#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char *temp;
    bool flag = 0;
    temp = new char[50]{};
    int container[10] = {0};
    int numnum[50];
    cout << "input some characters" << endl;
    ofstream number("E:\\cpp_project\\TJU_cpp\\tests\\9\\9_6.txt", ios::out | ios::binary);
    cin.getline(temp, 50);
    for (int i = 0; i < 50 && *(temp + i) != '\0'; i++)
    {
        if ((*(temp + i) >= 48 && *(temp + i) <= 57))
        {

            numnum[i] = *(temp + i) - 48;
            container[numnum[i]]++;
            flag = 1;
        }
    }
    if (flag)
    {
        cout << "The numbers are: " << endl;
        for (int i = 9; i > -1; i--)
        {
            for (int j = 0; j < container[i]; j++)
            {
                cout << i << " ";
                number.put(i+48);
            }
        }
    }
    else
    {
        cout << "There is no number in these characters!" << endl;
    }
    number.close();
    return 0;
}
