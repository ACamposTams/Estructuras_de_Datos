#include <iostream>

template <class T>
class Node 
{
private:
    T info;
    Node<T> * next;
    Node<T> * previous;
    
public:
    Node();
    Node(T info);
    
    T getInfo();
    void setInfo(T value);
    
    Node<T> * getNext();
    void setNext(Node<T> * value);
    Node<T> * getPrevious();
    void setPrevious(Node<T> * value);
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, Node<Tn> &);
    
    /* Probando los iteradores */
    Node<T> & operator ++(int);
    
};

template <class T>
Node<T>::Node()
{
    this->next = nullptr;
    this->previous = nullptr;
}

template <class T>
Node<T>::Node(T info)
{
    this->info = info;
    this->next = nullptr;
    this->previous = nullptr;
}

template <class T>
T Node<T>::getInfo()
{
    return info;
}

template <class T>
void Node<T>::setInfo(T value)
{
    info = value;
}

template <class T>
Node<T> * Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T> * value)
{
    next = value;
}

template <class T>
Node<T>* Node<T>::getPrevious()
{
    return previous;
}

template <class T>
void Node<T>::setPrevious(Node<T> * value)
{
    previous = value;
}

template <class T>
std::ostream & operator <<(std::ostream & os, Node<T> & Node)
{
    os << Node.info << " ";
    
    return os;
}

template <class T>
Node<T> & Node<T>::operator ++(int i)
{
    return next;
}
