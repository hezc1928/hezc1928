#include <iostream>
#include <cassert>
using namespace std;

// forward declaratio of node_ptr, used in class node.
template <typename T>
struct node_ptr;

// struct node
template <typename T>
struct node
{
    // default constructor
    node() : val(0), pre(nullptr), next(nullptr) {}
    // used for constructing a node containing value v
    node(T v) : val(v), pre(nullptr), next(nullptr) {}
    T val;
    node_ptr<T> pre;
    node_ptr<T> next;
};
// struct node_ptr representing a node pointer object.
// Reasons for needing this class:
// The iterator of my_list class is node<T>*, so we
// must implement ++ and * operator for type node<T>*. However,
// if we write a non-member function with the signature:
// node<T>* operator++(node<T>* );
// the compiler will raise an error.
template <typename T>
struct node_ptr
{
    node<T> *ptr;
    // constructor
    node_ptr(node<T> *p) : ptr(p) {}
    // assignment with a pointer of type node<T>*
    node_ptr &operator=(node<T> *p)
    {
        ptr = p;
        return *this;
    }
    // operator overload for comparison
    bool operator==(const node_ptr<T> &p) const { return ptr == p.ptr; }
    bool operator!=(const node_ptr<T> &p) const { return ptr != p.ptr; }
    // operator overload for increment
    node_ptr &operator++()
    {
        ptr = (ptr->next).ptr;
        return *this;
    }
    node_ptr &operator++(int)
    {
        ptr = (ptr->next).ptr;
        return *this;
    }
    // operator overload for dereference
    T &operator*() { return ptr->val; }
    // operator for ->
    // with this function, node_ptr can behave like normal <node>T*
    // for example, the code "node_ptr p; p->next" is valid
    // without this function, we must write statement like
    // "node_ptr p; p.ptr->next";
    node<T> *operator->() { return ptr; }
};
// with this struct defined, we directly use our
// list in the STL algorithm framework.
// we can write statement like:
// std::copy(l.begin(), l.end(), ostream_iterator<int>(std::cout,", "));
// std::copy(l.begin(), l.end(), vec.begin());
// without this, the above statement can not be compiled
// refer to
// https://stdcxx.apache.org/doc/stdlibug/16-3.html and
// https://stdcxx.apache.org/doc/stdlibug/16-4.html
// for more details.
template <typename T>
struct std::iterator_traits<node_ptr<T>>
{
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef node_ptr<T> pointer;
    typedef node_ptr<T> difference_type;
    typedef node<T> &reference;
};

// class my_list
template <typename T>
class my_list
{
private:
    // head pointer for my_list
    node_ptr<T> head;
    // tail pointer for my_list
    node_ptr<T> tail;
    // num of element in this list
    size_t ele_num;

public:
    // nested type
    using iterator = node_ptr<T>;
    using const_iterator = const node_ptr<T>;
    // default constructor
    // we construct a new node (dummy node) with no value in this node.
    // with dummy node, the end of list can be appropriately represented.
    my_list() : head(new node<T>()), tail(head), ele_num(0) {}
    // initializer list constructor
    // with this constructor, we can write like
    // my_list<int> = {1,2,3};
    my_list(initializer_list<T> il) : head(new node<T>()), tail(head), ele_num(0)
    {
        for (const T &v : il)
            this->push_back(v);
    }
    my_list(const my_list<T> &other) : my_list()
    {                                                                      //��Ϊ�˵��û������캯����
        for (node_ptr<T> it = other.head; it != other.tail; it = it->next) // it != nullptr
            this->push_back(*it);
        cout << "copy constructor" << endl;
    }
    my_list<T> &operator=(const my_list<T> &other)
    {
        if (&other == this)
        { //ע�����Ҹ�ֵ������
            cout << "copy assignment, but already equal!!!" << endl;
            return *this;
        }
        clear(); //������
        for (node_ptr<T> it = other.head; it != other.tail; it = it->next)
            this->push_back(*it);
        cout << "copy assignment" << endl;
        return *this;
    }
    my_list<T>(my_list<T> &&other) : my_list()
    { // std::move???
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        cout << "move constructor" << endl;
    }
    my_list<T> &operator=(my_list<T> &&other)
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        cout << "move assignment" << endl;
        return *this;
    }

    // deconstructor

    // note that, beside clear the whole list, we
    // must delete the dummy node.
    ~my_list()
    {
        clear();
        delete head.ptr;
        // for clearness, show the following msg when deconstructing list
        // cout << "the list has been destroyed."<<endl;
    }
    // head pointer and end pointer to the list
    iterator begin() { return head; }
    const_iterator cbegin() const { return head; }
    iterator end() { return tail; }
    const_iterator cend() const { return tail; }
    // insert values in the head and tail of the list
    void push_front(T v) { insert(begin(), v); }
    void push_back(T v) { insert(end(), v); }
    // get the front and back value in the list
    T &back()
    {
        assert(!empty());
        return *(tail->pre);
    }
    T &front()
    {
        assert(!empty());
        return *head;
    }
    // clear all the values in the list
    void clear()
    {
        if (empty())
            return;
        while (head != tail)
        {
            erase(head);
        }
    }
    size_t size() const { return ele_num; }
    bool empty() const { return head == tail; }

    // insert one element BEFORE it
    iterator insert(iterator it, const T &val)
    {
        // first inc the ele_num
        ele_num++;
        // we construct a new node to hold val;
        node_ptr<T> ele = new node<T>(val);
        // set the next and pre pointer for the new node
        ele->next = it;
        ele->pre = it->pre;

        // for it == head, we need to update the head pointer
        if (head == it)
        {
            head = ele;
        }
        // otherwise, we need to update the it->pre->next pointer
        else
        {
            it->pre->next = ele;
        }
        // last, we update the it->pre pointer
        it->pre = ele;
        return ele;
    }
    // remove the element pointed by it.
    iterator erase(iterator it)
    {
        assert(it != end());
        ele_num--;
        it->next->pre = it->pre;
        if (it == head)
        {
            head = it->next;
        }
        else
        {
            it->pre->next = it->next;
        }
        delete it.ptr;
        return it->next;
    }
};
