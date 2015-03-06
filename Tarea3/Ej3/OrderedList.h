#ifndef ___EP__OrdereList__
#define ___EP__OrderedList__

#include "LinkedList.h"
#include "Node.h"

template <class T>
class OrderedList : public LinkedList<T>
{
    public:
    void insert(T, int);
	void insert(Node<T> *, int);
};

template <class T>
void OrderedList<T>::insert(T element, int position)
{
    Node<T> * newnode = new Node<T>(element);
	insert(newnode, position);
}

template <class T>
void OrderedList<T>::insert(Node<T> * newnode, int position)
{
    if (this->empty() || position <= 0)
	{
		newnode->setNext(this->_first);
		this->_first = newnode;
	}

	else
	{
		if (position > this->_size) { position = this->_size; }

		Node<T> * tmp = this->at(position - 1);

		newnode->setNext(tmp->getNext());
		tmp->setNext(newnode);
	}
	
	int minimo = 0;
    T temp;
    T aux;
    this->_size++;
    int n = this->_size;
    
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        
        for(int j = i + 1; j < n; j++)
        {
            if ((this->at(minimo)->getInfo()) > (this->at(j)->getInfo()) )
                minimo = j;
        }
        
        temp = this->at(minimo)->getInfo();
        aux  = this->at(i)->getInfo();
        
        this->at(minimo)->setInfo(aux);
        this->at(i)->setInfo(temp);
    }
}
#endif