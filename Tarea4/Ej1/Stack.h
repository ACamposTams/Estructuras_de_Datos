#include "LinkedList.h"

template <class T>
class Stack : private LinkedList<T>
{
    public:
    
    Stack();
    virtual ~Stack();
    
    int size();
    bool empty();
    
    Node<T> * top();
    Node <T> * pop();
    void push(Node<T> *);
    void push(T);
    
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, Stack<Tn> &);
};

template <class T>
Stack<T>::Stack():LinkedList<T>()
{
    
}

template <class T>
Stack<T>::~Stack()
{
    this->clear();
}

template <class T>
int Stack<T>::size()
{
    return LinkedList<T>::size();
}

template <class T>
bool Stack<T>::empty()
{
    return LinkedList<T>::empty();
}

template <class T>
Node<T> * Stack<T>::top()
{
    this->first();
}
 
template <class T>   
Node <T> * Stack<T>::pop()
{
    return this->removeFront();
}
    
template <class T>
void Stack<T>::push(Node<T> * node)
{
    this->insertFront(node);
}
    
template <class T>
void Stack<T>::push(T value)
{
    this->insertFront(value);
}

template <class Tn>
std::ostream & operator <<(std::ostream & os, Stack<Tn> & stack)
{
    for (auto i:stack)
    {
        os << i << std::endl;
    }
    return os;
}