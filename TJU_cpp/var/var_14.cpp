#include <iostream>
using namespace std;
int date[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    int y, m, d, yd;
    int *p, i, *j;
    cout << "输入年、月、日：";
    cin >> y >> m >> d;
    p = date[0];
    i = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
    yd = d;
    if (i)
        p += 13;
    j = p + m;
    while (p < j)
    {
        yd += *p;
        p++;
    }
    cout << y << "年" << m << "月" << d << "日是该年的第";
    cout << yd << "天" << endl;
}
//这个程序bug很多，"1年23月43日是该年的第682天"这种东西都能给出来，挺离谱的