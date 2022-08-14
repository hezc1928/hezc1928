#include <iostream>
using namespace std;
int main()
{
    int score = 0;
    cout << "请输入你的成绩"<< endl;
    cin >> score;
    cout << "你的成绩";
    if (score>=90 && score<=100)
    {
        cout <<"是优秀"<< endl;
    }
    else if (score>=80 && score<90)
    {
        cout <<"是良好"<< endl;
    }
    else if (score>=70 && score<80)
    {
        cout <<"是一般"<< endl;
    }
    else if (score>=60 && score<70)
    {
        cout <<"是及格"<< endl;
    }
    else if (score>=0 && score<60)
    {
        cout <<"是不及格"<< endl;
    }
    else if (score<0)
    {
        cout <<"太低了"<< endl;
    }
    else
    {
        cout << "超过100分了" << endl;
    }
    return 0;
}
