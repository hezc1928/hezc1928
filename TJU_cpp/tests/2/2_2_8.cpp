#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    int j = 0;
    char input = 'NULL';
    while (input != '#')
    {
        cout << "input the " << j + 1 << " character" << endl;
        cin >> input;
        switch (input)
        {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        case '#':
            break;
        default:
            break;
        }
        j++;
    }
    cout << a << " " << e << " " << i << " " << o << " " << u << " " << endl;
    cout << a + e + i + o + u << endl;
}
