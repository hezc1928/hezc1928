#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int b = 1;
    int dig[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ofstream factor("9_4.txt", ios::out);
    for (int i = 1; i < 11; i++)
    {
        b *= i;
        int a = b;
        int j = 0;
        while (a)
        {
            dig[j] = a % 10 + 48;
            a /= 10;
            j++;
        }
        for (int k = 0; k < j; k++)
        {
            factor.write((char *)&dig[j - k - 1], 1);
        }
        factor.put('\n');
    }
    factor.close();
    cout << "Ð´Èë³É¹¦" << endl;
    return 0;
}
