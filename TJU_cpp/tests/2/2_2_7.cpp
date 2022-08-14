#include <iostream>
using namespace std;
int main()
{
    int a1 = 0;
    int a2 = 1;
    int a3 = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " " << a3;
            a1 = a3;
            a3 = a1 + a2;
            cout << " " << a3;
            a2 = a3;
            a3 = a1 + a2;
        }
        cout << endl;
    }
    return 0;
}
