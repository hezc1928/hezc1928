#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include "gfx_list.h"
using namespace std;

template <typename T>
void print(const my_list<T> &tlist)
{
    for (auto it = tlist.cbegin(); it != tlist.cend(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    my_list<int> list_1 = {11, 12, 13, 14, 15};
    cout << "***print list_1:" << endl;
    print(list_1);
    my_list<int> list_2 = list_1;
    cout << "***print list_2:" << endl;
    print(list_2);
    my_list<int> list_3;
    list_3 = list_1;
    cout << "***print list_3:" << endl;
    print(list_3); // list_3 == list_1
    list_3 = list_3;
    cout << "***print list_3:" << endl;
    print(list_3);
    my_list<int> list_4 = move(list_1);
    cout << "***print list_4:" << endl;
    print(list_4);
    my_list<int> list_5;
    list_5 = std::move(list_1); // error! Because list_1 can not use!!!
    cout << "***print list_5:" << endl;
    print(list_5); // error!!!
    list_5 = std::move(list_2);
    cout << "***print list_5:" << endl;
    print(list_5);
    list_5 = std::move(list_5);
    cout << "***print list_5:" << endl;
    print(list_5); //����Ҫ���ұ���
}
