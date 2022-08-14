#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    for (x = 0; x <= 100; x++)
    {
        for (y = 0; y <= 100; y++)
        {
            for (z = 0; z <= 100; z++)
            {
                if (5 * x + 3 * y + z / 3 == 100 && x + y + z == 100 && z % 3 == 0)
                {
                    cout << " 公鸡 " << x << " 只，母鸡 " << y << " 只，小鸡 " << z << " 只 " << endl;
                    x = 100;
                    y = 100;
                    z = 100;
                }
            }
        }
    }
    return 0;
}
