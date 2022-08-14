#include <iostream>
using namespace std;
int main()
{
    int m = 2;
    int i = 2;
    int z = 0;
    while (z < 100)
    {
        for (i = 2; i < m; i++)
            if (m % i == 0)
                break;
        if (i == m)
        {
            cout << m << " ";
            z++;
        }
        m++;
    }
    return 0;
}
