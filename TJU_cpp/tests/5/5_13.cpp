#include <iostream>
using namespace std;
int function(int n, int k);
int main()
{
    int n(0);
    int k(0);
    cout << "pls input the num : ";
    cin >> n;
    cout << "pls input the digit: ";
    cin >> k;
    cout << "the " << k << " digit of number " << n << " is " << function(n, k) << endl;
    return 0;
}
int function(int n, int k)
{
    int *dig;
    dig = new int[k]{0};
    int j(0);
    if (k < 0)
    {
        return 0;
    }
    else
    {
        while (n)
        {
            dig[j] = n % 10;
            n /= 10;
            j++;
        }
    }
    if (k <= j)
    {
        int aaaa = dig[k - 1];
        delete[] dig;
        return aaaa;
    }
    else
    {
        return 0;
    }
}
