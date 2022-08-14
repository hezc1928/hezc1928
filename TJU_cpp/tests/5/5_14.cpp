#include <iostream>
using namespace std;
void avr(int (*a)[4]);
int main()
{
    int array[5][4];
    cout << "input 20 numbers for a 5*4 matrix " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> array[i][j];
        }
        cout << "next row" << endl;
    }
    for (int j = 0; j < 4; j++)
    {
        cin >> array[4][j];
    }
    avr(array);
    return 0;
}
void avr(int (*a)[4])
{
    double avr[5] = {};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            avr[i] += a[i][j];
        }        avr[i] /= 4;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "the " << i + 1 << " row's average value is " << avr[i] << endl;
    }
}
