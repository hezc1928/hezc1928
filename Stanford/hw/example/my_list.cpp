#include<string>
#include<iostream>
#include<iterator>
#include<vector>
#include"my_list.h"
using namespace std;
int main() {
    // initialize with a initializer_list
    my_list<int> m={1,5,8};
    // push back and front some values
    m.push_back(1);
    m.push_back(2);
    m.push_front(100);
    
    // test the normal loop using iterator
    cout <<"for loop using const_iterator:"<<endl;
    for(auto it=m.cbegin(); it!=m.cend(); it++)
        cout << *it<<" ";
    cout << endl;

    // test the for-each loop can work 
    cout <<"for-each loop result:"<<endl;
    for(int a:m)
        cout << a <<" ";
    cout << endl;
    
    // test modifying values in the list
    cout <<"modify the first value:"<<endl;
    my_list<int>::iterator it = m.begin();
    *it = -1;
    copy(m.begin(), m.end(), ostream_iterator<int>(cout, ","));
    cout <<endl;
    
    // test erasing values in the list
    cout <<"delet the second value:"<<endl;
    m.erase(m.begin()++);
    copy(m.begin(), m.end(), ostream_iterator<int>(cout, ","));
    cout <<endl;

    // test copying values to a vector
    cout <<"copy values to a vector, the content in the vector:"<<endl;
    vector<int> v(m.size(),0);
    copy(m.begin(), m.end(), v.begin());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "--"));
    cout << endl;

    // misc test
    cout << "list size: "<< m.size()<<endl;
    cout << "back value: "<<m.back()<<endl;
    cout << "front value: "<<m.front()<<endl;
    cout << "is empty: "<<m.empty()<<endl;

    m.clear();
    cout <<"after clearing all values, the size: " << m.size()<<endl;
    cout <<"after clearing all values, is empty: " << m.empty()<<endl;
    
    // before exiting main, the ~my_list<int> will be executed.
}