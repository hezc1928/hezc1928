#include <iostream>
using namespace std;
int main()
{
    int score = 0;
    cout << "��������ĳɼ�"<< endl;
    cin >> score;
    cout << "��ĳɼ�";
    if (score>=90 && score<=100)
    {
        cout <<"������"<< endl;
    }
    else if (score>=80 && score<90)
    {
        cout <<"������"<< endl;
    }
    else if (score>=70 && score<80)
    {
        cout <<"��һ��"<< endl;
    }
    else if (score>=60 && score<70)
    {
        cout <<"�Ǽ���"<< endl;
    }
    else if (score>=0 && score<60)
    {
        cout <<"�ǲ�����"<< endl;
    }
    else if (score<0)
    {
        cout <<"̫����"<< endl;
    }
    else
    {
        cout << "����100����" << endl;
    }
    return 0;
}
