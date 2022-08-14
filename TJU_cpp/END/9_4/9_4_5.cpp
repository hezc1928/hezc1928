#include <iostream>
using namespace std;
char *InttoChar(int n)
{
    int t[6]{0};
    int k = 0;
    while (n != 0)
    {
        t[k++] = n % 10;
        n /= 10;
    }
    char *chch;
    chch = new char[2 * k - 1]{0};
    for (int i = 0; i < k; i++)
    {
        chch[2 * i] = t[k - i - 1] + 48;
        chch[2 * i + 1] = ' ';
    }
    return chch;
}
int LengthOfChar(char *chch)
{
    int n(0);
    for (int i = 0; i < 15; i++)
    {
        if (chch[i] >= 48 && chch[i] <= 57)
        {
            n++;
        }
    }

    return 2 * n - 1;
}
int main()
{
    int n = 41942;
    char *chch = InttoChar(n);
    cout << chch << endl;
    cout << LengthOfChar(chch);
    return 0;
}