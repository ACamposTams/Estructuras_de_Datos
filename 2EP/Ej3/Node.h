#include <iostream>
#pragma once
template <class T>
class Node
{
	T info;
	Node<T> * next = nullptr;
	Node <T> * previous = nullptr;

	public:
	Node() {}
	~Node() { next = nullptr; previous = nullptr; }
	Node(T _info) : info(_info) {}

	T getInfo() const { return info; }
	void setInfo(T value) { info = value; }

	Node<T> * getNext() const { return next; }
	void setNext(Node<T> * value) { next = value; }
	
	Node<T> * getPrevious() const { return previous;}
	void setPrevious(Node<T> * value) {previous = value;}

	template <class Tn>
	friend std::ostream & operator << (std::ostream & os, Node<Tn>  & node);
};

template <class Tn>
std::ostream & operator << (std::ostream & os, Node<Tn>  & node)
{
	os << node.info;

	return os;
}