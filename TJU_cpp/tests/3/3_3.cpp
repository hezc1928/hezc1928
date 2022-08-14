#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int temp = 0;
    for (int i = 0; i < 1; i++)
    {               
        cin >> a;
        if (a >= 100 && a < 1000)
        {
            int b[3] = {0};
            b[0] = a / 100;
            b[1] = (a - b[0] * 100) / 10;
            b[2] = a % 10;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 2 - j; k++)
                {
                    if (b[k] > b[k + 1])
                    {
                        temp = b[k];
                        b[k] = b[k + 1];
                        b[k + 1] = temp;
                        temp = 0;
                    }
                }
            }
            cout << b[0] << b[1] << b[2];
        }
        else if (a >= 1000 && a < 10000)
        {
            int b[4];
            b[0] = a / 1000;
            b[1] = (a - b[0] * 1000) / 100;
            b[2] = (a - b[0] * 1000 - b[1] * 100) / 10;
            b[3] = a % 10;
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 3 - j; k++)
                {
                    if (b[k] > b[k + 1])
                    {
                        temp = b[k];
                        b[k] = b[k + 1];
                        b[k + 1] = temp;
                        temp = 0;
                    }
                }
            }
            cout << b[0] << b[1] << b[2] << b[3];
        }
        else if (a == 10000)
        {
            cout << "00001" << endl;
        }
        else
        {
            cout << "please input again " << endl;
            i--;
        }
    }
}
