#include <iostream>
#include "CircularLinkedList.h"

template <class T>
class DCL_List : public CircularLinkedList<T> {
    
    public:
    DCL_List() { }
    ~DCL_List();

    void insert(T,int) override;
    void insert(Node<T> *, int) override;
    Node<T> * remove(int) override;
    void clear() override;
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, DCL_List<Tn> *&);
    
};

template <class T>
DCL_List<T>::~DCL_List()
{
    this-> clear();
}

template <class T>
void DCL_List<T>::clear()
{
    Node<T> * tmp = this->_first;
    
    while (this->_first != this->_last) {
        this->_first = this->_first->getNext();
        this->_first->setPrevious(tmp->getPrevious());
        tmp->setNext(nullptr);
        tmp->setPrevious(nullptr);
        delete tmp;
    }
    
    if (this->_last)
    {
        this->_last->setNext(nullptr);
        this->_last->setPrevious(nullptr);
        delete this->_last;
    }
    
    this->_first = this->_last = nullptr;
    
    this->_size = 0;
}

template <class T>
void DCL_List<T>::insert(T element,int position)
{
    Node<T> * newnode = new Node<T>(element);

	insert(newnode, position);
}

template <class T>
void DCL_List<T>::insert(Node<T> * nuevo, int pos)
{
    if (pos < 0 || pos > this->_size) {
        return;
    }
    
    /* Insertar al _first de la lista */
    if (pos == 0)
    {
        if(this->_size==0)
        {
            this->_first = this->_last = nuevo;
            this->_first->setNext(nuevo);
            this->_first->setPrevious(nuevo);
        }
        else
        {
        nuevo->setNext(this->_first);
        nuevo->setPrevious(this->_last);
        this->_first->setPrevious(nuevo);
        this->_last->setNext(nuevo);
        this->_first = nuevo;
        }
    }
    else if (pos == (this->_size - 1)) 
    {
        nuevo->setNext(this->_last);
        nuevo->setPrevious(this->_last->getPrevious());
        this->_last->getPrevious()->setNext(nuevo);
        this->_last->setPrevious(nuevo);
        
    }
    else if(pos == this->_size)
    {
        nuevo->setPrevious(this->_last);
        nuevo->setNext(this->_first);
        this->_last->setNext(nuevo);
        this->_first->setPrevious(nuevo);
        this->_last = nuevo;
    }
    else
    { /* Insertar en cualquier otra posición */
        Node<T> * anterior = this->at(pos)->getPrevious();
        nuevo->setNext(anterior->getNext());
        nuevo->setPrevious(anterior);
        anterior->getNext()->setPrevious(nuevo);
        anterior->setNext(nuevo);
    }
    
    ++this->_size;
}

template <class T>
Node<T> * DCL_List<T>:: remove(int pos)
{
    if (pos < 0 || pos >= this->_size) {
        return nullptr;
    }
    
    Node<T> * borrado = nullptr;
    
    /* Borra al _first */
    if (pos == 0) {
        borrado = this->_first;
        
        if (this->_size == 1) {
            this->_first->setNext(nullptr);
            this->_first->setPrevious(nullptr);
            this->_first = this->_last = nullptr;
        }
        else {
            this->_first = this->_first->getNext();
            this->_last->setNext(this->_first);
            this->_first->setPrevious(this->_last);
        }
    }
    else { /* Borrar en cualquier otra posición */
        Node<T> * prev = this->at(pos)->getPrevious();
        
        if (prev->getNext() == this->_last) {
            this->_last = prev;
            borrado = this->_last->getNext();
            this->_last->setNext(this->_first);
            this->_first->setPrevious(this->_last);
            borrado->setNext(nullptr);
            borrado->setPrevious(nullptr);
        }
        else
        {
            borrado = prev->getNext();
            borrado->getPrevious()->setNext(borrado->getNext());
            borrado->getNext()->setPrevious(borrado->getPrevious());
            borrado->setNext(nullptr);
            borrado->setPrevious(nullptr);
        }
    }
    --this->_size;
    return borrado;
}

template <class T>
std::ostream & operator <<(std::ostream & os, DCL_List<T> *& lista)
{

    for (auto p : *lista)
    {
        os << p << " ";
    }
    
    return os;
}
