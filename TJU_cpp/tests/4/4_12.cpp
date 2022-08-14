#include <iostream>
using namespace std;
int size(0);
template <class T>
T paixu(T *str)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                double temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "排序后的数组： ";
    for (int i = 0; i < size; i++)
    {
        cout << str[i] << ", ";
    }
    return 0;
}
int main()
{
    char type = '\0';
    int *integral;
    char *character;
    double *ddd;
    cout << "Please input the size: ";
    cin >> size;
    cout << "select: integral (i), character (c), double (b)" << endl;
    cin >> type;
    switch (type)
    {
    case 'i':
        cout << "Please input: ";
        integral = new int[size];
        for (int k = 0; k < size; k++)
        {
            cin >> *(integral + k);
        }
        paixu(integral);
        delete[] integral;
        break;
    case 'c':
        cout << "Please input: ";
        character = new char[size];
        for (int k = 0; k < size; k++)
        {
            cin >> *(character + k);
        }
        paixu(character);
        delete[] character;
        break;
    case 'd':
        cout << "Please input: ";
        ddd = new double[size];
        for (int k = 0; k < size; k++)
        {
            cin >> *(ddd + k);
        }
        paixu(ddd);
        delete[] ddd;
        break;
    }
}
