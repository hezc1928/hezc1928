#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream inin("9_5.dat", ios::in | ios::binary);
    fstream outout("9_5_1.dat", ios::out | ios::in | ios::binary);
    int a[5][5];
    for (int m = 0; m < 5; m++)
    {
        for (int l = 0; l < 5; l++)
        {

            char row[20];
            for (int sss = 0; sss < 20; sss++)
            {
                row[sss] = NULL;
            }
            int j = 0;
            int answer = 0;
            for (int i = 0; i < 20; i++)
            {
                if (*(row + i - 1) != ',' && *(row + i - 1) != '\n')
                {
                    inin.get(*(row + i));
                }
                else
                {
                    j = i - 1;
                    i = 25;
                }
            }
            bool flag = 0;
            for (int i = 0; i < j; i++)
            {
                int temp = 0;
                float power = 1;
                temp = *(row + j - i - 1) - 48;
                for (int k = 0; k < i; k++)
                {
                    power *= 10;
                }
                if (temp < 0 || temp >= 10)
                {
                    flag = 1;
                }
                if (flag)
                {
                    power /= 10;
                }
                if (temp >= 0 && temp < 10)
                {
                    answer += temp * power;
                }
            }
            a[m][l] = answer;
        }
    }
    for (int l = 0; l < 5; l++)
    {
        for (int m = 0; m < 4; m++)
        {
            int dig[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 1; i < 11; i++)
            {
                int j = 0;
                while (a[m][l])
                {
                    dig[j] = a[m][l] % 10;
                    a[m][l] /= 10;
                    j++;
                }
                for (int k = 0; k < j; k++)
                {
                    outout.put(dig[j - k - 1] + 48);
                }
            }
            outout.put(',');
        }
            int dig[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 1; i < 11; i++)
            {
                int j = 0;
                while (a[4][l])
                {
                    dig[j] = a[4][l] % 10;
                    a[4][l] /= 10;
                    j++;
                }
                for (int k = 0; k < j; k++)
                {
                    outout.put(dig[j - k - 1] + 48);
                }
            }
        outout.put('\n');
    }

    cout << "Ð´Èë³É¹¦" << endl;
    return 0;
}
