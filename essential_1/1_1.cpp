#include <iostream>
#include <string>
using namespace std;

int main()
{    

cout << "Please enter your first name: ";
string user_name;
string family_name;
cin >> user_name;
cout << "Please enter your second name: ";
cin >> family_name;
cout << '\n';
cout << "Hello,";
cout << user_name;
cout << "`";
cout << family_name ;
cout << " and goodbye! \n";
return 0;

}