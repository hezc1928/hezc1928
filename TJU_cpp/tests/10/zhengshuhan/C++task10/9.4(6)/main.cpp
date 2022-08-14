#include <iostream>
#include "chain.h"
using namespace std;
int main(){
    char str[]="C++FORTRANPASCALBASIC";
    Chain L1;
    int i=0;
    for( ;str[i]!=0;i++)
    if(L1.Insert(i,str[i])==false){
        cout<<"error\n";
        break;
    }
    cout<<L1<<endl;
    char y='!';
    L1.rInsert(y);
    cout<<L1<<endl;
    return 0;
}
