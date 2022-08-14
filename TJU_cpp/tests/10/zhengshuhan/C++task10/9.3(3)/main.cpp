#include <iostream>
#include "chain.h"
using namespace std;
void Reverse1(Chain &A,Chain &B){
    B.ClearList();
    char x;
    int i,len;
    len=A.Length();
    for(i=0;i<len;i++){
        A.Find(len-i-1,x);
        B.Insert(i,x);
    }
    A.ClearList();
}
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
    Chain L2;
    Reverse1(L1,L2);
    cout<<L1<<endl;
    cout<<L2<<endl;
    return 0;
}
