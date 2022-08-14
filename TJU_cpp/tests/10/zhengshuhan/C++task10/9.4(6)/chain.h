#include <iostream>
using namespace std;

class Chain;
class Node{
    friend class Chain;
private:
    char data;
    Node *next;
};
class Chain{
public:
    Chain();
	~Chain();
    bool IsEmpty(){
        return length==0;
        }
	int Length(){
	    return length;
	    }
    bool Find(int i,char &x);
	int Search(const char &x);
    bool Insert(int i,const char &x);
    bool Delete(int i,char &x);
    void ClearList();
    void output(ostream &out)const;
    friend ostream& operator << (ostream &out,const Chain &x);
    void Del(const char &item);
    void rInsert(char &x);
private:
    Node *head;
    int length;
};
Chain::Chain(){
    head = new Node;
    head -> next = 0;
    length = 0 ;
}
Chain::~Chain(){
    ClearList();
    delete head;
}
bool Chain::Find(int i,char &x){
    if ( i < 0 || i > length) {
            return false;
    }
	Node *p = head -> next;
	int k = 0;
	while(k < i){
        p = p -> next;
        k ++;
	}
	x = p -> data;
	return true;
}
int Chain::Search(const char &x){
    Node *p = head -> next;
    int i = 0 ;
    while(p != 0){
        if(p -> data == x)
            return i;
        p = p -> next;
        i++;
    }
    return -1;
}
bool Chain::Insert(int i,const char &x){
    if( i < 0 || i > length)
        return false;
    Node *p = head;
    int k = 0;
    while(k <= i -1){
        p = p -> next;
        k++;
    }
    Node *q;
    q = new Node;
    q -> data = x;
    q -> next = p -> next;
    p -> next = q;
    length ++;
    return true;
}
bool Chain::Delete(int i ,char &x){
    if( i < 0 || i > length)
        return false;
    Node *p = head;
    for(int k = 0;k < i;k++)
        p = p -> next;
    Node *q = p -> next;
    x = q -> data;
    p -> next = q -> next;
    delete q;
    length --;
    return true;
}
void Chain::ClearList(){
    Node *p = head -> next,*q;
    while(p != 0){
        q = p;
        p = p -> next;
        delete q;
    }
    head -> next = 0;
    length = 0;
}
void Chain::output( ostream &out)const{
    Node *p = head -> next;
    while(p != 0){
        out << p -> data << " ";
        p = p -> next;
    }
}
ostream& operator<<(ostream &out, const Chain &x){
	x.output(out);
	return out;
}
void Chain::rInsert(char &y){
    Insert(length,y);
}

