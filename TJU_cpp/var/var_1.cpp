#include <iostream>
using namespace std;
int main()
{
    int array[10] = {65, 87, 90, 80, 84, 85, 53, 46, 95, 70};
    int sum(0), average;
    for (int i = 0; i < 10; i++)
        sum += array[i];
    average = sum / 10;
    cout << "�ܺ�=" << sum << endl;
    cout << "ƽ��ֵ=" << average << endl;
    /*�������������⣬void��int main��һ�����Լ�����������룬����GBK��ȡ��*/
}
