#include <iostream>
using namespace std;
void statistics(char *ff, int a[4])
{
    for (int i = 0; i < 80 && ff[i] != '\0'; i++)
    {
        if (ff[i] >= 65 && ff[i] <= 90)
        {
            a[0]++;
        }
        else if (ff[i] >= 97 && ff[i] <= 122)
        {
            a[1]++;
        }
        else if (ff[i] >= 48 && ff[i] <= 57)
        {
            a[2]++;
        }
        else
        {
            a[3]++;
        }
    }
    cout << "Captial letters " << a[0] << endl;
    cout << "letter " << a[1] << endl;
    cout << "Numbers " << a[2] << endl;
    cout << "other characters " << a[3] - 1 << endl; //È¥³ý#ºÅ
}
int main()
{
    char *chch;
    int num[4] = {0, 0, 0, 0};
    chch = new char[80];
    cout << "input characters, end by #" << endl;
    for (int i = 0; i < 80 && chch[i - 1] != '#'; i++)
    {
        cin >> chch[i];
    }
    statistics(chch, num);
    return 0;
}