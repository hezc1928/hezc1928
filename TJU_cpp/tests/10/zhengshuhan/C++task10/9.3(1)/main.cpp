#include "seqlist.h"
#include "chain.h"
#include <iostream>
using namespace std;
void SeqListtoChain(SeqList &A,Chain &B){
    char x;
    B.ClearList();
    int i=0;
    while(i<A.Length()){
        A.Find(i,x);
        B.Insert(i,x);
        i++;
    }
}
int main(){
    char str[]="C++FORTRANPASCALBASIC";
    SeqList L(100);
    int i=0;
    for( ;str[i]!=0;i++)
    if(L.Insert(i,str[i])==false){
        cout<<"error\n";
        break;
    }
    cout<<L<<endl;
    Chain C;
    SeqListtoChain(L,C);
    cout<<C<<endl;
    return 0;
}
