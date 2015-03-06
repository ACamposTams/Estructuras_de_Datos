#include <iostream>
#pragma once
template <class T>
class Node
{
	T info;
	Node<T> * next = nullptr;

	public:
	Node() {}
	~Node() { next = nullptr; }
	Node(T _info) : info(_info) {}

	T getInfo() const { return info; }
	void setInfo(T value) { info = value; }

	Node<T> * getNext() const { return next; }
	void setNext(Node<T> * value) { next = value; }

	template <class Tn>
	friend std::ostream & operator << (std::ostream & os, Node<Tn>  & node);
};

template <class Tn>
std::ostream & operator << (std::ostream & os, Node<Tn>  & node)
{
	os << node.info;

	return os;
}