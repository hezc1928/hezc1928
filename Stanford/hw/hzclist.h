#pragma once
#include <iostream>
#include <cassert>
using namespace std;
template <class _N>
class Node
{
public:
    _N data;
    Node<_N> *next;
    Node<_N> *prev;
    Node(const _N &d, Node<_N> *n = nullptr, Node<_N> *p = nullptr)
    {
        data = d;
        next = n;
        prev = p;
    }
};
//迭代器
template <class T, class Ref, class Ptr>
class hzclist_iterator
{
public:
    typedef Node<T> Node; //这一步记得说明一下
    typedef hzclist_iterator<T, T &, T *> iterator;
    typedef hzclist_iterator<T, const T &, const T *> const_iterator;
    typedef hzclist_iterator<T, Ref, Ptr> Self;
    Node *_node;
    hzclist_iterator(Node *n) : _node(n) {}
    hzclist_iterator() : _node(nullptr) {}
    Ref operator*() { return _node->data; }
    Self *operator->() { return &(operator*()); }
    //双向迭代器
    Self &operator++()
    {
        _node = _node->next;
        return *this;
    }
    Self operator++(int)
    {
        Self tmp = *this;
        ++*this;
        return tmp;
    }
    Self &operator--()
    {
        _node = _node->prev;
        return *this;
    }
    Self operator--(int)
    {
        Self tmp = *this;
        --*this;
        return tmp;
    }
    bool operator!=(const Self &rhs) { return _node != rhs._node; } //不等于运算符
    bool operator==(const Self &rhs) { return _node == rhs._node; } //相等运算符
    hzclist_iterator operator=(const Self &rhs)                     //赋值运算符重载
    {
        _node = rhs._node;
        return *this;
    }
};
// list类
template <class _E>
class hzclist
{
public:
    typedef Node<_E> Node; //这句可以不写，但之后所有Node都要写成Node<_E>
    typedef size_t size_type;
    typedef hzclist_iterator<_E, _E &, _E *> iterator;
    typedef hzclist_iterator<_E, const _E &, const _E *> const_iterator;
    const size_type size() const { return _M_len; }
    hzclist() : _M_len(0) //构造函数
    {
        head = new Node(0);
        head->next = head;
        head->prev = head;
    }
    hzclist(int n, const _E &value = _E()) //批量构造函数
    {
        head = new Node(0);
        head->next = head;
        head->prev = head;
        while (n--)
        {
            push_back(value);
        }
    }
    hzclist(const hzclist<_E> &l) //拷贝构造函数 需要支持深拷贝，即指针也要跟着走
    {
        head = new Node(0);
        head->next = head;
        head->prev = head;
        hzclist<_E>::const_iterator it = l.cbegin();
        while (it != l.cend())
        {
            this->push_back(*it);
            ++it;
        }
    }
    ~hzclist()
    {
        Clear();
        delete head;
        head = nullptr;
        //全部清空并删除头结点
    }
    iterator begin() { return iterator(head->next); }
    iterator end() { return iterator(head); }
    const_iterator cbegin() const { return const_iterator(head->next); }
    const_iterator cend() const { return const_iterator(head); }
    //全部清空
    void Clear()
    {
        Node *p = head->next;
        while (p != head)
        {
            Node *tmp = p;
            p = p->next;
            delete tmp;
        }
        _M_len = 0;
        head->next = head;
        head->prev = head;
    }
    void swap(hzclist<_E> &l)
    {
        //交换两个list的头结点
        Node *tmp = head;
        head = l.head;
        l.head = tmp;
    }
    //插入操作
    iterator insert(iterator pos, const _E &x)
    {
        //时间复杂度为O(1)
        Node *cur = pos._node;
        Node *prev = cur->prev;
        Node *newNode = new Node(x);
        newNode->next = cur;
        cur->prev = newNode;
        prev->next = newNode;
        newNode->prev = prev;
        _M_len++;
        return iterator(newNode);
    }
    //删除操作
    iterator erase(iterator pos)
    {
        //时间复杂度为O(1)
        assert(pos != end());
        Node *cur = pos._node;
        Node *prev = cur->prev;
        prev->next = cur->next;
        cur->next->prev = prev;
        delete cur;
        _M_len--;
        return iterator(prev->next);
    }
    //在特殊位置的插入删除操作直接调用erase和insert
    void pop_back()
    {
        erase(--end());
    }
    void pop_front()
    {
        erase(begin());
    }
    void push_front(const _E &x)
    {
        insert(begin(), x);
    }
    void push_back(const _E &x)
    {
        insert(end(), x);
    }
    //取特殊位置的值，分为常引用和普通引用
    _E &front()
    {
        assert(!empty());
        return head->next->data;
    }
    const _E &front() const
    {
        assert(!empty());
        return head->next->data;
    }
    _E &back()
    {
        assert(!empty());
        return head->prev->data;
    }
    const _E &back() const
    {
        assert(!empty());
        return head->prev->data;
    }
    //平时操作insert和erase会维护一个_M_len的变量，所以这里能达到O(1)
    size_t Size()
    {
        return _M_len;
    }
    bool empty()
    {
        return begin() == end();
        // return  _M_len == 0;//这样写也行
    }

private:
    Node *head;
    size_type _M_len;
};
template <class _Tp> //两个list相加，直接把list进行拼接
hzclist<_Tp> &operator+(hzclist<_Tp> &l1, hzclist<_Tp> &l2)
{
    hzclist<int> l3;
    for (auto i = l1.begin(); i != l1.end(); i++)
    {
        l3.push_back(*i);
    }
    for (auto i = l2.begin(); i != l2.end(); i++)
    {
        l3.push_back(*i);
    }
    return l3;
}
template <class _Tp> //重载流运算符
ostream &operator<<(ostream &out, hzclist<_Tp> &l)
{
    for (auto i = l.begin(); i != l.end(); i++)
    {
        out << *i << " ";
    }
    return out;
}