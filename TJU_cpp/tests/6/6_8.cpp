#include <iostream>
using namespace std;
class array
{
private:
    int *a;  //ָ��̬����
    int num; //����Ԫ�ظ���
public:
    array(int n = 5) //����Ԫ�ظ���Ϊn�Ķ�̬����,ȱʡ
    {
        num = n > 0 ? n : 5;
        a = new int[num];
        cout << "�����¶���ɹ�" << endl;
    }
    array(const array &r) //AddArray�᷵��һ����ֵ����Ҫ��һ��const ��������
    {
        num = r.num;
        a = new int[num];
        for (int i = 0; i < r.num; i++)
        {
            *(a + i) = *(r.a + i);
        }
        cout << "�����¶���ɹ�" << endl;
    }
    array(array &r) //��һ�������������ֵ����һ�����������,�����к�������
    {
        num = r.num;
        a = new int[num];
        for (int i = 0; i < r.num; i++)
        {
            *(a + i) = *(r.a + i);
        }
        cout << "�����¶���ɹ�" << endl;
    }
    void InPut() //��������Ԫ�ص�ֵ
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
    void OutPut() //�������Ԫ�ص�ֵ
    {

        for (int i = 0; i < num; i++)
        {
            cout << *(a + i) << " ";
        }
        cout << endl;
    }
    ~array() //�ͷŶ�̬����ռ�
    {
        cout << "�������" << endl;
    }
    friend array AddArray(array &a1, array &a2); //��Ԫ������������������
};
array AddArray(array &a1, array &a2)
{
    int temp;
    for (int i = 0; i < a1.num; i++)
    {
        *(a2.a + i) = *(a1.a + i) + *(a2.a + i); //����a1������a
        cout << *(a2.a + i) << " ";
    }
    cout << endl;
    return a2;
}
int main()
{
    int length = 10;

    array a1(length); //��������Ϊ10��array

    for (int i = 0; i < length; i++) //һ����ʼ������
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
