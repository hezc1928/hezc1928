#include <iostream>
using namespace std;
int main()
{
    cout << "请输入一个自然数" << endl;
    int n = 1;
    int h = 0;
    int i = 0;
    int cube = 0;
    while (n != 0)
    {
        cin >> n;
        i = 0;
        cube = n * n * n;
        if (n > 0)
        {
            while (i < cube)
            {
                for (int j = 0; j < n; j++)
                {
                    h = h + 2 * i + 2 * j + 1;
                }
                if (cube == h)
                {
                    cout << cube << " = " << n << " ^ 3 = ";
                    for (int k = 0; k < n - 1; k++)
                    {
                        cout << 2 * i + 1 + 2 * k << "+";
                    }
                    cout << 2 * i - 1 + 2 * n << " 成立\n" << "请再输入一个自然数" << endl;
                }
                else
                {
                    h = 2 * i;
                }
                i++;
                h = 0;
            }
        }
        else if (n < 0)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "你输入了0，退出程序" << endl;
            break;
        }
    }
}
