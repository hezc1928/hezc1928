#include <iostream>
using namespace std;
int main()
{
    double data[3][4] = {{1.2, 1.5, 1.7, 1.9}, {2.0, 2.4, 2.6, 2.8}, {3.2, 3.6, 3.7, 3.8}};
    double sum;
    for (int i = 0; i < 3;i++)
    {
        sum = 0.0;
        for (int j = 0; j < 4;j++)
        {
            sum += data[i][j];
            cout << "µÚ" << i << "ÐÐºÍ£º" << sum << endl;
        }
    }
}