//���ֱ���ΪGBK
#include <iostream>
#include "hzclist.h"
#include <cstring>
using std::cout;
using std::endl;
using std::to_string;
using namespace std;

template <class _N>
void int_list(hzclist<_N> &l1)
{
    auto li = l1.begin(); //������
    l1.push_back(1);
    l1.push_front(12);
    for (int i = 1; i < 5; i++)
    {
        l1.insert(li, i); //��ÿһλ�ֱ�ֵ
    }
    cout << "l1: " << l1 << endl;

    cout << "\n********************\nl1��3λ��ֵΪ6:\n\n";
    for (int i = 0; i < 3; i++)
    {
        li++;
    }
    *li = 6; //���Ե�������ֵ���ѵ�3λ��ֵΪ6
    cout << "l1: " << l1 << endl;
    cout << "\n********************\nl2�Ŀ�������:\n\n";
    hzclist<int> l2(l1); //�������캯��
    cout << "l2: " << l2 << endl;
}
template <class _N>
void is_empty_hzclist(hzclist<_N> &l1)
{
    cout << "size of l1:" << l1.size() << endl;
    if (l1.empty())
    {
        cout << "l1 is empty" << endl;
    }
    else
    {
        cout << "l1 is not empty" << endl;
    }
}
void char_list()
{
    char s[5] = "hezc"; //��������Ԫ�ز���
    hzclist<char> l2;
    for (int i = 0; i < 5; i++)
    {
        l2.insert(l2.end(), s[i]);
    }
    cout << l2 << endl;
    cout << "size = " << l2.size() << endl;
    l2.Clear();
}
template <class _N>
void bid_test(hzclist<_N> &l1)
{
    auto li = l1.begin();
    for (int i = 1; i < 3; i++)
    {
        li++;
    }
    cout << "l1: " << l1 << endl;
    cout << "li: " << *li << endl;
    cout << "operator--: "
         << "li: " << *(li--) << endl;
    cout << "li: " << *li << endl;
    cout << "--operator: "
         << "li: " << *--li << endl;
    cout << "li: " << *li << endl;
}
template <class _N>
void del_test(hzclist<_N> &l1, int pos)
{
    cout << "before: " << endl;
    cout << "l1: " << l1 << endl;
    auto li = l1.begin();
    for (int i = 1; i < pos; i++)
    {
        li++;
    }
    l1.erase(li); //ɾ��posλ
    cout << "after: " << endl;
    cout << "l1: " << l1 << endl;
}
template <class _N>
void const_test(hzclist<_N> &l1)
{
    auto lci = l1.cbegin(); // const������
    while (lci != l1.cend())
    {
        // *lci = 10; //�����Զ�const��������ֵ�����������ע�ͻᱨ��
        cout << "const_iterator��ֵ�� " << *lci << endl;
        lci++;
    }
}
int main()
{
    cout << "\n********************\n�½�һ���ձ�l1\n";
    hzclist<int> l1; //�½�
    cout << "\n********************\nl1�Ƿ�Ϊ��:\n\n";
    is_empty_hzclist(l1); //�Ƿ�Ϊ��
    cout << "\n********************\nl1�ĸ�ֵ:\n\n";
    int_list(l1); //�����ʼֵ�����ÿ������캯��
    cout << "\n********************\nl1�Ƿ�Ϊ��: \n\n";
    is_empty_hzclist(l1); //�ٴ�ȷ�Ϲ�ģ
    cout << "\n********************\n����һ��������List: \n\n";
    hzclist<int> l3(5, 1);
    cout << "l3:" << l3 << endl;
    cout << "size = " << l3.size() << endl;
    l3.Clear();
    cout << "\n********************\n����һ��char���͵�List: \n\n";
    char_list(); //�������͵ĳ�ʼ��
    cout << "\n********************\n������λ��ɾ���ڵ�: \n\n";
    del_test(l1, 3); //ɾ���������ڵ�
    cout << "\n********************\n��������˫���: \n\n";
    bid_test(l1); //������˫����֤
    cout << "\n********************\nconst�����������޸�ָ��λ�õ�Ԫ��: \n\n";
    const_test(l1); // const������
    l1.Clear();     //���
    return 0;
}