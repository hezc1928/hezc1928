#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    char chch[5][99]{0};
    int *a;
    a = new int[5]{0};
    for (int i = 0; i < 5; i++)
    {
        cout << "input" << endl;
        for (int j = 0; chch[i][j - 1] != '#'; j++)
        {
            cin >> chch[i][j];
            a[i]++;
        }
    }

    /*
    for (int i = 0; ch1[i - 1] != '#'; i++)
    {
        cin >> ch1[i];
        a[0]++;
    }
    cout << "input" << endl;
    for (int i = 0; ch2[i - 1] != '#'; i++)
    {
        cin >> ch2[i];
        a[1]++;
    }
    cout << "input" << endl;
    for (int i = 0; ch3[i - 1] != '#'; i++)
    {
        cin >> ch3[i];
        a[2]++;
    }
    cout << "input" << endl;
    for (int i = 0; ch4[i - 1] != '#'; i++)
    {
        cin >> ch4[i];
        a[3]++;
    }
    cout << "input" << endl;
    for (int i = 0; ch5[i - 1] != '#'; i++)
    {
        cin >> ch5[i];
        a[4]++;
    }*/
    for (int i = 0; i < 5; i++)
    {
        cout << i << " " << a[i] - 1 << " -> ";
        cout << chch[i] << endl;
    }
    int temp(0);
    char chtemp[99];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                for (int k = 0; k < 99; k++)
                {
                    chtemp[k] = chch[i][k];
                    chch[i][k] = chch[j][k];
                    chch[j][k] = chtemp[k];
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << i << " " << a[i] - 1 << " -> ";
        cout << chch[i] << endl;
    }
    return 0;
}