#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= j; k++)
            {

                if (216 == i * j * k)
                {
                    cout << i << " * " << j << " * " << k << " = " << i * j * k << " " << endl;
                    //goto part2;
                }
            }
        }
    }
part2:
    cout << "part2" << endl;
    return 0;
}