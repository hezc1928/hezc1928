#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int temp = 0;
    int j = 0;
    int dig[5] = {-1, -1, -1, -1, -1};
    cout << "input a" << endl;
    for (int i = 0; i < 1; i++)
    {
        cin >> a;
        if (a >= 100 && a <= 10000)
        {
            while (a)
            {
                dig[j] = a % 10;
                a /= 10;
                j++;
            }
        }
        else
        {
            cout << "please input again " << endl;
            i--;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 3 - j; k++)
        {
            if (dig[k] > dig[k + 1])
            {
                temp = dig[k];
                dig[k] = dig[k + 1];
                dig[k + 1] = temp;
                temp = 0;
            }
        }
    }
    for (int k = 0; k < 5; k++)
    {
        if (dig[4 - k] >= 0)
        {
            cout << dig[4 - k] << endl;
        }
    }
}
