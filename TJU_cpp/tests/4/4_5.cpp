#include <iostream>
using namespace std;
float sta(char *a, int n);
int main()
{
    char *a;
    int n(0);
    cout << "input the size" << endl;
    cin >> n;
    cout << "input the data" << endl;
    a = new char[n];
    cin >> a;
    cout << sta(a, n) * 100 << " %" << endl;
    delete[] a;
    return 0;
}
float sta(char *a, int n)
{
    float count(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 48; j < 58; j++)
        {
            if (a[i] == j)
            {
                count++;
            }
        }
    }
    return count / n;
}