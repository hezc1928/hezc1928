
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    int s = 0;
    int temp = 1;
    int val = 1;
    for (int i = 1; i < 10; i++)
    {
        if (temp == 0)
        {
            break;
        }
        val *= 5;
        temp = 26318 / val;
        s += temp;
        cout << "5^" << i << " = " << val << endl;
        cout << "26318/("
             << "5^" << i << ")=" << temp << endl;
    }
    cout << "s:" << s << endl;
    return 0;
}