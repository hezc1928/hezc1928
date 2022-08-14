#include <iostream>
#include <cstring>
#include <fstream>
#define M(N) a*N + 1
using namespace std;
int main()
{
    int a = 3, n = 4;
    for (int i = 0; i < 10; i++)
    {
        cout << M(i) << endl;
    }
    return 0;
}