#include <iostream>
using namespace std;
int main()
{
    float n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (n > 0)
        {
            cout << n + 1 << endl;
        }
        else
        {
            cout << n * n << endl;
        }
    }
    return 0;
}
