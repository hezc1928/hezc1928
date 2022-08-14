#include <iostream>
using namespace std;
int main()
{
    int a[5][3] = {0};
    int rowsum[5] = {0};
    int temp(0);
    cout << "input 15 numbers for a 5*3 matrix " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            rowsum[i] += a[i][j];
        }
        cout << "next row" << endl;
    }
    for (int j = 0; j < 3; j++)
    {
        cin >> a[4][j];
        rowsum[4] += a[4][j];
    }
    for (int l = 0; l < 5; l++)
    {
        for (int k = 0; k < 4 - l; k++)
        {
            if (rowsum[k] < rowsum[k + 1])
            {
                temp = rowsum[k];
                rowsum[k] = rowsum[k + 1];
                rowsum[k + 1] = temp;
                temp = 0;
            }
        }
    }
    cout << "每行的和从大到小排序为" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << rowsum[i] << " ";
    }
    return 0;
}
