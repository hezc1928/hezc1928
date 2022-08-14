#include <iostream>
using namespace std;
int perfect(int m)
{
    int sum(0);
    for (int i = 1; i < m; i++)
    {
        if (m % i == 0)
        {
            sum += i;
        }
    }
    if (sum == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    for (int i = 1; i < 1001; i++)
    {
        if (perfect(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}