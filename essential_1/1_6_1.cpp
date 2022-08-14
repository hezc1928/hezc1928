#include <string>
#include <iostream>
using namespace std;
int main(){
    int a;
    int * b;
    b=&a;
    cout<<b;
    int * c;
    c=b;
    int d[100];
    int * e;
    e=&d[0];
    for (int i=0; i<100;i++){
        *e = 0;
        e++;
    }

return 0;
}