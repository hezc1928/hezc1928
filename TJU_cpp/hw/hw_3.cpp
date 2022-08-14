#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int m;
    cout << "size of data";
    cin >> m;
    int *p;
    p = new int[m];
    if (p == NULL)
    {
        cout << "failed to new\n";
        exit(1);
    }
    cout << "input the data\n";
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    float s = 0.0;
    for (int i = 0; i < m; i++)
    {
        s += p[i];
    }
    cout << "average = " << s / m << endl;
    delete[] p;
    return 0;
}