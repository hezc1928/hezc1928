#include <iostream>
using namespace std;
int main()
{
    char str[80]="C++ Programming Today";
    int count(0), i(0);
    while (str[i]!='\0')
    {
        count++;
        i++;
        
    }
    cout << "×Ö·û¸öÊý=" << count << endl;
}