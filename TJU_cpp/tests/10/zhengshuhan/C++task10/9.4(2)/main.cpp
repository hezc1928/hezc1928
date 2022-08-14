#include "seqlist.h"
#include "chain.h"
#include <iostream>
using namespace std;
void delchar(SeqList &A,char y){
    char x;
    int i=0;
    while(i<A.Length()){
        A.Find(i,x);
        if(x==y) A.Delete(i,x);
        else i++;
    }
}
void delchar(Chain &B,char y){
    char x;
    int i=0;
    while(i<B.Length()){
        B.Find(i,x);
        if(x==y) B.Delete(i,x);
        else i++;
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
    char item='A';
    delchar(L,item);
    cout<<L<<endl;
    Chain L2;
    i=0;
    for( ;str[i]!=0;i++)
    if(L2.Insert(i,str[i])==false){
        cout<<"error\n";
        break;
    }
    cout<<L2<<endl;
    delchar(L2,item);
    cout<<L2<<endl;
    return 0;
}
