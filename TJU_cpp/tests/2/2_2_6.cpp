#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n = 1;
    double v = 0;
    double pi = 0.0;
    double u = 1;
    double delta = 1.0e-6;
    while (u > delta || u < -delta)
    {
        if (n % 2 == 0)
        {
            v = -(2 * n - 1);
        }
        else
        {
            v = (2 * n - 1);
        }
        u = 1 / v;
        pi += u;
        n++;
    }
    cout << "pi=" << setprecision(7) << 4 * pi << endl;
    cout << "n=" << n << endl;
    return 0;
}
