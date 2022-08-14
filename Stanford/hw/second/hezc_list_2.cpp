#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include "hezc_list_2.h"
using namespace std;
int main()
{
    my_list<int> list_1 = {11, 12, 13, 14, 15};
    cout << "************\nprint list_1:" << endl;
    list_1.print();

    my_list<int> list_2 = list_1;
    cout << "************\nprint list_2:" << endl;
    list_2.print();

    my_list<int> list_3;
    list_3 = list_1;
    cout << "************\nprint list_3:" << endl;
    list_3.print();
    list_3 = list_3;
    cout << "************\nprint list_3:" << endl;
    list_3.print();

    my_list<int> list_4 = move(list_1);
    cout << "************\nprint list_4:" << endl;
    list_4.print();

    my_list<int> list_5;
    list_5 = move(list_1); // list_1 can not be used
    cout << "************\nprint list_5:" << endl;
    list_5.print();
    list_5 = move(list_2);
    cout << "************\nprint list_5:" << endl;
    list_5.print();
    list_5 = move(list_5);
    cout << "************\nprint list_5:" << endl;
    list_5.print();
}