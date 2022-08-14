#include <iostream>
using namespace std;
int main()
{
    char c[80]={0};
    cout << "input a string" << endl;
    cin >> c;
    int na(0), ni(0);
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == 'a')
        {
            na++;
        }
        if (c[i] == 'i')
        {
            ni++;
        }
    }
    // for (int j = 0; c[j] != '\0'; j++)
    // {
    //     cout << c[j];
    // }
    cout << endl;
    cout << na << " a's" << endl;
    cout << ni << " i's" << endl;
    cout << "you inputed " << c << endl;
}
