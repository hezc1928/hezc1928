#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void function(int a);
class F
{
private:
    int *c;
    int nn;

public:
    F(int *b, int num);
    void swap(int *a, int bottom, int top)
    {
        int temp;
        for (int i = bottom; i <= bottom + (top - bottom) / 2; i++)
        {
            temp = a[i];
            a[i] = a[top - i + bottom];
            a[top - i + bottom] = temp;
        }
    }
    void cal(int *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
        cout << "&&&&&&&&&&&&&&" << endl;
        int max = 0;
        int max_pos = 0;
        if (n == 1)
        {
            return;
        }
        for (int i = n - 1; i > -1; i--)
        {
            if (a[i] > max)
            {
                max = a[i];
                max_pos = i;
            }
        }
        cout << "max = " << max << endl;
        cout << "max_pos = " << max_pos << endl;
        swap(a, max_pos, n - 1);
        swap(a, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
        cout << "********" << endl;
        a++;
        cal(a, n - 1);
    }
    ~F();
};

F::F(int *b, int num)
{
    nn = num;
    c = new int[nn];
    for (int i = 0; i < nn; i++)
    {
        c[i] = b[i];
    }
}

F::~F()
{
    delete[] c;
}

int main()
{
    int a[5] = {1, 53, 9823, 23, 6};
    int n;
    n = 5;
    F test(a, n);
    test.cal(a, n);
    test.swap(a, 0, 4);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}