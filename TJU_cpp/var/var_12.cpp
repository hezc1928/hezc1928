#include <iostream>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";        
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";        
    }
    cout << endl;
    p = a + 3;
    cout << *p << endl;
    cout << p - a << endl;
    
}