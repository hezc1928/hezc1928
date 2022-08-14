#include <iostream>
using namespace std;
int main()
{
    int a[3][3] = {0};
    cout << "input 9 numbers for a 3*3 matrix " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
        cout << "next row" << endl;
    }
        for (int j = 0; j < 3; j++)
    {
        cin >> a[2][j];
    }
    cout << "sum of main diag is " << a[0][0] + a[2][2] + a[1][1] << endl;
    cout << "sum of minor diag is " << a[2][0] + a[0][2] + a[1][1] << endl;
}
