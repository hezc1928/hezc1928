//汉字编码为GBK
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
    auto li = l1.begin(); //迭代器
    l1.push_back(1);
    l1.push_front(12);
    for (int i = 1; i < 5; i++)
    {
        l1.insert(li, i); //给每一位分别赋值
    }
    cout << "l1: " << l1 << endl;

    cout << "\n********************\nl1第3位赋值为6:\n\n";
    for (int i = 0; i < 3; i++)
    {
        li++;
    }
    *li = 6; //测试迭代器赋值，把第3位赋值为6
    cout << "l1: " << l1 << endl;
    cout << "\n********************\nl2的拷贝构造:\n\n";
    hzclist<int> l2(l1); //拷贝构造函数
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
    char s[5] = "hezc"; //其他类型元素测试
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
    l1.erase(li); //删除pos位
    cout << "after: " << endl;
    cout << "l1: " << l1 << endl;
}
template <class _N>
void const_test(hzclist<_N> &l1)
{
    auto lci = l1.cbegin(); // const迭代器
    while (lci != l1.cend())
    {
        // *lci = 10; //不可以对const迭代器赋值，这条语句解除注释会报错
        cout << "const_iterator的值是 " << *lci << endl;
        lci++;
    }
}
int main()
{
    cout << "\n********************\n新建一个空表l1\n";
    hzclist<int> l1; //新建
    cout << "\n********************\nl1是否为空:\n\n";
    is_empty_hzclist(l1); //是否为空
    cout << "\n********************\nl1的赋值:\n\n";
    int_list(l1); //加入初始值，调用拷贝构造函数
    cout << "\n********************\nl1是否为空: \n\n";
    is_empty_hzclist(l1); //再次确认规模
    cout << "\n********************\n创建一个批量的List: \n\n";
    hzclist<int> l3(5, 1);
    cout << "l3:" << l3 << endl;
    cout << "size = " << l3.size() << endl;
    l3.Clear();
    cout << "\n********************\n创建一个char类型的List: \n\n";
    char_list(); //其他类型的初始化
    cout << "\n********************\n在任意位置删除节点: \n\n";
    del_test(l1, 3); //删除第三个节点
    cout << "\n********************\n迭代器是双向的: \n\n";
    bid_test(l1); //迭代器双向验证
    cout << "\n********************\nconst迭代器不能修改指定位置的元素: \n\n";
    const_test(l1); // const迭代器
    l1.Clear();     //清空
    return 0;
}