#include <iostream>
using namespace std;
int Find_value(int *p, int scale)
{
    int max(0);
    for (int i = 0; i < scale; i++)
    {
        if (p[i] > max)
        {
            max = p[i];
        }
    }
    return max;
}
int main()
{
    int a[20] = {5, 2, 5, 7, 3, 6, 5, 4, 2,999};
    int b[9] = {5, 2, 5, 7, 3, 6, 5, 4, 2};
    cout << Find_value(a, 20) << endl;
    //cout << Find_value(b) << endl;
    return 0;
}