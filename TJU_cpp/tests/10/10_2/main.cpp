#include <iostream>
#include "SeqList.h"
#include "Chain.h"
using namespace std;
int main()
{
    return 0;
}
bool SeqList::Find(int i, char &x)
{
    if (i < 0 || i > length - 1)
    {
        return false;
    }
    x = element[i];
    return true;
}
int SeqList::Search(const char &x)
{
    for(int i = 0; i < length; i++)
    {
        if(element[i] == x)
        {
            return i;
        }
    }
    return -1;
}
bool SeqList::Insert(int i, const char& x)
{
    if (i < 0 || i > length)
    {
        return false;
    }
    if (length == Maxsize)
    {
        return false;
    }
    for(int k = length - 1; k >= i; k--)
    {
        element[k+1] = element[k];
    }
    element[i] = x;
    length++;
    return true;
}
bool SeqList::Delete(int i,char &x)
{
    if(Find(i,x))
       {
           for(int k = i; k < length - 1; k++)
            {
                element[k] = element[k+1];
            }
            length--;
            return true;
       }
       else
       {
           return false;
       }
}
void SeqList::output(ostream &out)const
{
    for(int i=0;i<length;i++)
    {
        out<<element[i]<<" ";
    }
}
ostream& operator<< (ostream &out,const SeqList &x)
{
    x.output(out);
    return out;
}
bool Chain::Find(int i,char &x)
{
    if (i < 0 || i > length - 1)
    {
        return false;
    }
    Node *p = head->next;
    int k=0;
    while (k<i)
    {
        p=p->next;
        k++;
    }
    x=p->data;
    return true;
}
int Chain::Search(const char &x)
{
    Node *p = head ->next;
    int i=0;
    while(p!=0)
    {
        if(p->data == x)
        {
            return i;
        }
        p=p->next;
        i++;
    }
    return -1;
}
bool Chain::Insert(int i,const char &x)
{
    if (i < 0 || i > length)
    {
        return false;
    }
    Node *p= head;
    int k=0;
    while(k<=i-1)
    {
        p=p->next;
        k++;
    }
    Node *q;
    q=new Node;
    q->data = x;
    q->next=p->next;
    p->next = q;
    length++;
    return true;
}
bool Chain::Delete(int i, char &x)
{
    if (i < 0 || i > length - 1)
    {
        return false;
    }
    Node *p = head;
    for(int k = 0; k < i; k++)
    {
        p=p->next;
    }
    Node *q = p -> next;
    x = q -> data;
    p -> next = q -> next;
    delete q;
    length--;
    return true;
}
void Chain::ClearList()
{
    Node *p = head -> next, *q;
    while(p != 0)
    {
        q = p;
        p = p -> next;
        delete q;
    }
    head -> next = 0;
    length = 0;
}
void Chain::output(ostream &out)const
{
    Node *p = head -> next;
    while(p != 0)
    {
        out << p -> data << " ";
        p = p -> next;
    }
}
ostream& operator<< (ostream &out,const Chain &x)
{
    x.output(out);
    return out;
}
