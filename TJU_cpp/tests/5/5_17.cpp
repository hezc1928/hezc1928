#include <iostream>
using namespace std;
void HigherThan85(int (*score)[30]);
void LowerThan60(int (*score)[30]);
void NumOverAvr(int (*score)[30]);
void OrderHighToLow(int (*score)[30]);
int main()
{
    int start[30] = {1, 1, 1, 1, 60, 60, 60, 60, 60, 60, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 50, 50, 50, 50, 50, 50, 90, 90, 90, 90};
    // 每个学生有两个参数，学号和成绩，对应放到一个二维数组里，初始化后是一个对角阵，其余位置是-1，之后，每个学生总是保持在第i行，但是改变成绩排列可以改变学生成绩列数。用数组pos记录。
    int score[30][30]{0};
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == j)
            {
                *(*(score + i) + j) = *(start + i);
            }
            else
            {
                *(*(score + i) + j) = -1;
            }
        }
    }
    HigherThan85(score);
    LowerThan60(score);
    NumOverAvr(score);
    OrderHighToLow(score);
}
void HigherThan85(int (*score)[30])
{
    cout << "HIGHER" << endl;
    for (int i = 0; i < 30; i++)
    {
        if (*(*(score + i) + i) > 85)
        {
            cout << "the " << i + 1 << " student has score " << *(*(score + i) + i) << " higher than 85" << endl;
        }
    }
}
void LowerThan60(int (*score)[30])
{
    cout << "LOWER" << endl;
    for (int i = 0; i < 30; i++)
    {
        if (*(*(score + i) + i) < 60)
        {
            cout << "the " << i + 1 << " student has score " << *(*(score + i) + i) << "  lower than 60" << endl;
        }
    }
}
void NumOverAvr(int (*score)[30])
{
    cout << "AVR" << endl;
    int average(0);
    for (int i = 0; i < 30; i++)
    {
        average += *(*(score + i) + i);
    }
    average /= 30;
    int j(0);
    for (int i = 0; i < 30; i++)
    {
        if (*(*(score + i) + i) >= average)
        {
            j++;
        }
    }
    cout << "there are " << j << " students' score higher than average score " << average << endl;
}
void OrderHighToLow(int (*score)[30])
{

    cout << "ORDER" << endl;
    int temp(0);
    int pos[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    for (int j = 0; j < 30; j++)
    {
        for (int k = 0; k < 29 - j; k++)
        {
            if (*(*(score + k) + *(pos + k)) < *(*(score + k + 1) + *(pos + k + 1)))
            {
                *(*(score + k + 1) + *(pos + k)) = *(*(score + k) + *(pos + k));
                *(*(score + k) + *(pos + k)) = -1;
                *(*(score + k) + *(pos + k + 1)) = *(*(score + k + 1) + *(pos + k + 1));
                *(*(score + k + 1) + *(pos + k + 1)) = -1;
                temp = *(pos + k);
                *(pos + k) = *(pos + k + 1);
                *(pos + k + 1) = temp;
                temp = 0;
            }
        }
    }
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (*(*(score + i) + j) != -1)
            {
                cout << "学号 " << *(pos + i) + 1 << " 成绩是 " << *(*(score + i) + j) << endl;
            }
        }
    }
}
