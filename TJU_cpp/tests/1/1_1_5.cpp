#include <iostream>
using namespace std;
int main()
{
    int a;
    int a1, a2, a3;
    cin >> a;
    a3 = a % 10;
    a2 = (a-a3)/10%10;
    a1 = (a - a % 100) / 100;
    cout << a3 << "\n"
         << a2 << "\n"
         << a1 << endl;
    return 0;
}
