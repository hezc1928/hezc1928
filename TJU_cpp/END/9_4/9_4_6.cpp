#include <iostream>
using namespace std;
void fun_max(int w[], int n, int &max, int &pos)
{
    for (int i = 0; i < n; i++)
    {
        if (w[i] > max)
        {
            max = w[i];
            pos = i;
        }
    }
}
int main()
{
    const int n = 20;
    int max(0), pos(0);
    int w[20] = {1, 2, 3, 4, 5, 6, 7, 8, 241, 46, 2};
    fun_max(w, n, max, pos);
    cout << "max " << max << endl;
    cout << "pos " << pos << endl;
    return 0;
}