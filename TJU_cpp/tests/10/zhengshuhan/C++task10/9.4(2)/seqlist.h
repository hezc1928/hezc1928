#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

 class SeqList{
public:
    SeqList(int m=10);
	~SeqList(){
	    delete []element;
	    }
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
    void ClearList(){
        length = 0;
        }
    void output(ostream &out)const;
    friend ostream& operator <<(ostream &out,const SeqList &x);
    void Del(const char&item);
private:
	int Maxsize;
	int length;
	char *element;
 };
SeqList::SeqList(int m){
    element = new char [m];
    Maxsize = m;
    length = 0;
}
bool SeqList::Find(int i, char &x){
	if(i<0||i>length - 1)
        return false;
	x=element[i];
	return true;
}
bool SeqList::Insert(int i, const char &x){
    if(i<0||i>length)
        return false;
    if(length > Maxsize)
        return false;
    for( int j = length - 1 ; j >= i ; j --)
        element [j+1] = element [j];
    element [i] = x;
    length ++;
    return true;
}
bool SeqList::Delete(int i,char &x){
	if(Find(i,x)){
		for(int k=i;k<length-1;k++)
			element[k]=element[k+1];
		length--;
		return true;
	}
	else
		return false;
}
void SeqList::output(ostream &out) const{
	for(int i=0;i<length;i++)
		out<<element[i];
}

ostream& operator<<(ostream &out, const SeqList &x){
	x.output(out);
	return out;
}



#endif // SEQLIST_H_INCLUDED
