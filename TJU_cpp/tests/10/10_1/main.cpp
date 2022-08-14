#include <iostream>
#include "E:\cpp_project\TJU_cpp\tests\10\10_1\include\SeqList.h"
#include "E:\cpp_project\TJU_cpp\tests\10\10_1\include\Chain.h"
using namespace std;
void SeqListtoChain(SeqList &A, Chain &B);
void Reverse(Chain &A, Chain &B);
void DeleteItem(SeqList &A, char x)
{
    int len;
    char temp;
    len = A.Length();
    for (int i = 0; i < len; i++)
    {
        A.Find(i, temp);
        if (temp == x)
        {
            A.Delete(i, temp);
            i--;
        }
        temp = 0;
    }
}
void DeleteItem(Chain &A, char x)
{
    int len;
    char temp;
    temp = x;
    len = A.Length();
    for (int i = 0; i < len; i++)
    {
        A.Find(i, temp);
        if (temp == x)
        {
            A.Delete(i, temp);
            i--;
        }
        temp = 0;
    }
}
int main()
{
    char str[] = "hezc1hezc2hezc3eeeee";
    cout << "str is " << str << endl;
    SeqList L(100);
    Chain BB;
    Chain CC;
    //start
    for (int i = 0; str[i] != 0; i++)
    {
        if (L.Insert(i, str[i]) == false)
        {
            cout << "failed to create!";
            break;
        }
    }
    //1
    SeqListtoChain(L, BB);
    cout << "SeqListtoChain:" << endl;
    cout << BB << endl;
    //2
    Reverse(BB, CC);
    cout << "Reverse:" << endl;
    cout << CC << endl;
    //3.1
    L.ClearList();
    for (int i = 0; str[i] != 0; i++)
    {
        if (L.Insert(i, str[i]) == false)
        {
            cout << "failed to create!";
            break;
        }
    }
    cout << "The previous SeqList:" << endl;
    cout << L << endl;
    DeleteItem(L, 'e');
    cout << "The deleted SeqList:" << endl;
    cout << L << endl;
    //3.2
    CC.ClearList();
    for (int i = 0; str[i] != 0; i++)
    {
        if (CC.Insert(i, str[i]) == false)
        {
            cout << "failed to create!";
            break;
        }
    }
    cout << "The previous Chain:" << endl;
    cout << CC << endl;
    DeleteItem(CC, 'e');
    cout << "The deleted Chain:" << endl;
    cout << CC << endl;
    //4
    CC.rInsert('x');
    cout << "rInsert:" << endl;
    cout << CC << endl;
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
    for (int i = 0; i < length; i++)
    {
        if (element[i] == x)
        {
            return i;
        }
    }
    return -1;
}
bool SeqList::Insert(int i, const char &x)
{
    if (i < 0 || i > length)
    {
        return false;
    }
    if (length == Maxsize)
    {
        return false;
    }
    for (int k = length - 1; k >= i; k--)
    {
        element[k + 1] = element[k];
    }
    element[i] = x;
    length++;
    return true;
}
bool SeqList::Delete(int i, char &x)
{
    if (Find(i, x))
    {
        for (int k = i; k < length - 1; k++)
        {
            element[k] = element[k + 1];
        }
        length--;
        return true;
    }
    else
    {
        return false;
    }
}
void SeqList::output(ostream &out) const
{
    for (int i = 0; i < length; i++)
    {
        out << element[i] << " ";
    }
}
ostream &operator<<(ostream &out, const SeqList &x)
{
    x.output(out);
    return out;
}
bool Chain::Find(int i, char &x)
{
    if (i < 0 || i > length - 1)
    {
        return false;
    }
    Node *p = head->next;
    int k = 0;
    while (k < i)
    {
        p = p->next;
        k++;
    }
    x = p->data;
    return true;
}
int Chain::Search(const char &x)
{
    Node *p = head->next;
    int i = 0;
    while (p != 0)
    {
        if (p->data == x)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}
bool Chain::Insert(int i, const char &x)
{
    if (i < 0 || i > length)
    {
        return false;
    }
    Node *p = head;
    int k = 0;
    while (k <= i - 1)
    {
        p = p->next;
        k++;
    }
    Node *q;
    q = new Node;
    q->data = x;
    q->next = p->next;
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
    for (int k = 0; k < i; k++)
    {
        p = p->next;
    }
    Node *q = p->next;
    x = q->data;
    p->next = q->next;
    delete q;
    length--;
    return true;
}
void Chain::ClearList()
{
    Node *p = head->next, *q;
    while (p != 0)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head->next = 0;
    length = 0;
}
void Chain::output(ostream &out) const
{
    Node *p = head->next;
    while (p != 0)
    {
        out << p->data << " ";
        p = p->next;
    }
}
ostream &operator<<(ostream &out, const Chain &x)
{
    x.output(out);
    return out;
}
void SeqListtoChain(SeqList &A, Chain &B)
{
    char x;
    B.ClearList();
    int i = 0;
    while (i < A.Length())
    {
        A.Find(i, x);
        B.Insert(i, x);
        i++;
    }
}
void Reverse(Chain &A, Chain &B)
{
    B.ClearList();
    char x;
    int len;
    len = A.Length();
    for (int i = 0; i < len; i++)
    {
        A.Find(len - i - 1, x);
        B.Insert(i, x);
    }
    A.ClearList();
}
bool Chain::rInsert(const char &x)
{
    //Insert(length, x);
    Node *p = head;
    int k = 0;
    while (k <= length-1)
    {
        p = p->next;
        k++;
    }
    Node *q;
    q = new Node;
    q->data = x;
    q->next = p->next;
    p->next = q;
    length++;
    return true;
}
