#include <iostream>
using namespace std;
int main()
{
    int array[10] = {65, 87, 90, 80, 84, 85, 53, 46, 95, 70};
    int sum(0), average;
    for (int i = 0; i < 10; i++)
        sum += array[i];
    average = sum / 10;
    cout << "总和=" << sum << endl;
    cout << "平均值=" << average << endl;
    /*这里有两个问题，void和int main不一样，以及汉字输出编码，是以GBK读取的*/
}
