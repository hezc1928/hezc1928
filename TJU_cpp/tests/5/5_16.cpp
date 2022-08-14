#include <iostream>
using namespace std;
int aaa(0);
char *transfer(int n, int r, char *output);
int main()
{
    int n(0), r(0);
    char *output;
    cout << "input the number to be transferd: ";
    cin >> n;
    cout << "select a system of numeration: ";
    cin >> r;
    transfer(n, r, output);
    int size(0);
    cout << "after transfer we got: ";
    for (int j = 0; j < aaa; j++)
    {
        cout << output[aaa - j - 1];
    }
    return 0;
}
char *transfer(int n, int r, char *output)
{
    int dig[99]; //99位数字很大了，就这么用吧
    while (n)
    {
        dig[aaa] = n % r;
        n /= r;
        aaa++;
    }
    for (int i = 0; i < aaa; i++)
    {
        if (dig[i] >= 10 && dig[i] <= 15)
        {
            output[i] = dig[i] + 87;
        }
        else
        {
            output[i] = dig[i] + 48;
        }
    }
    return output;
}