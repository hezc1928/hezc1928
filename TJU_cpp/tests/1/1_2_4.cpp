#include <iostream>
using namespace std;
void dafen(float score = 0)
{
    if (score >= 90 && score <= 100)
    {
        cout << "你的成绩是A" << endl;
    }
    else if (score >= 80 && score < 90)
    {
        cout << "你的成绩是B" << endl;
    }
    else if (score >= 60 && score < 80)
    {
        cout << "你的成绩是C" << endl;
    }
    else if (score >= 0 && score < 60)
    {
        cout << "你的成绩是D" << endl;
    }
}
int main()
{
    float a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cout << "请输入第 " << i+1 << " 个成绩" << endl;
        cin >> a[i];
        if (a[i] < 0 || a[i] > 100)
        {
            i--;
            cout << "出错了，请重试" << endl;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cout << "学号 " << j << endl;
        dafen(a[j]);
    }
    return 0;
}
