#include <iostream>
using namespace std;
class array
{
private:
    int *a;  //指向动态数组
    int num; //数组元素个数
public:
    array(int n = 5) //创建元素个数为n的动态数组,缺省
    {
        num = n > 0 ? n : 5;
        a = new int[num];
        cout << "创建新对象成功" << endl;
    }
    array(const array &r) //AddArray会返回一个右值，需要加一个const 万能引用
    {
        num = r.num;
        a = new int[num];
        for (int i = 0; i < r.num; i++)
        {
            *(a + i) = *(r.a + i);
        }
        cout << "创建新对象成功" << endl;
    }
    array(array &r) //将一个已有数组对象值传给一个新数组对象,这里有函数重载
    {
        num = r.num;
        a = new int[num];
        for (int i = 0; i < r.num; i++)
        {
            *(a + i) = *(r.a + i);
        }
        cout << "创建新对象成功" << endl;
    }
    void InPut() //输入数组元素的值
    {
        for (int i = 0; i < num; i++)
        {
            cin >> *(a + i);
        }
    }
    void SetArray(int set, int i)
    {
        *(a + i) = set;
    }
    void OutPut() //输出数组元素的值
    {

        for (int i = 0; i < num; i++)
        {
            cout << *(a + i) << " ";
        }
        cout << endl;
    }
    ~array() //释放动态数组空间
    {
        cout << "析构完毕" << endl;
    }
    friend array AddArray(array &a1, array &a2); //友元函数完成两个数组相加
};
array AddArray(array &a1, array &a2)
{
    int temp;
    for (int i = 0; i < a1.num; i++)
    {
        *(a2.a + i) = *(a1.a + i) + *(a2.a + i); //操作a1的属性a
        cout << *(a2.a + i) << " ";
    }
    cout << endl;
    return a2;
}
int main()
{
    int length = 10;

    array a1(length); //创建长度为10的array

    for (int i = 0; i < length; i++) //一个初始化程序
    {
        a1.SetArray(i * i, i);
    }
    cout << "a1.OutPut" << endl;
    a1.OutPut();
    array a2(a1);
    //a2.InPut();
    cout << "a2.OutPut" << endl;
    a2.OutPut();
    cout << "AddArray" << endl;
    AddArray(a1, a2);
    cout << "a2.OutPut" << endl;
    a2.OutPut();
    array a3(AddArray(a1, a2));
    a3.OutPut();

    return 0;
}
