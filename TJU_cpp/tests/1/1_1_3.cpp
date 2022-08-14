#include <iostream>
using namespace std;
int main()
{
    int radius;
    const float pi = 3.14;
    cout << "input an intergal" << endl;
    cin >> radius;
    cout << "the area is " << radius * radius * pi << endl;
    cout << "the circumference is " << 2 * radius * pi << endl;
    return 0;
}
