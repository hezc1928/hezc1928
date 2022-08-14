#include <iostream>
using namespace std;
int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << *(*a + 0) << *a[0] << a[0][0] << endl;
    cout << *(*(a + 1) + 0) << *(a[1] + 0) << a[1][0] << endl;
    cout << *(*(a + 2) + 1) << *(a[2] + 1) << a[2][1] << endl;
}