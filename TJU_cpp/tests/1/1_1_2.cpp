#include <iostream>
using namespace std;
int main()
{
    float a, b;
    float c;
    cin >> a;
    cin >> b;
    c = a < b ? a : b;
    cout << c << endl;
    return 0;
}