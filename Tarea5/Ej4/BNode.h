#include <iostream>
#include "LinkedList.h"

template <class T>
class BNode {
        
    BNode<T> * parent = nullptr;
    LinkedList<BNode<T>*> * sons = new LinkedList<BNode<T>*>();
        
    T info;
        
    public:
        
        /* Constructores */
        BNode() { }
        BNode(const T & _info) : info (_info) { }
        BNode(const BNode<T> & );
        
        /* Destructor */
        virtual ~BNode();
        
        T getInfo() const { return info; }
        void setInfo(const T & value) { info = value; }
        
        BNode<T> * getParent() const { return parent; }
        void setParent(BNode<T> * value) { parent = value; }
        
        LinkedList<BNode *> * getSons() const { return sons; }
        void setSons(BNode<T> * value) { sons->insertBack(value); }
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, BNode<Tn>  & node);
    };
    
    template <class T>
    BNode<T>::BNode(const BNode<T> & other)
    {
        info = other.info;
        parent = other.parent;
        sons = other.sons;
    }
    
    template <class T>
    BNode<T>::~BNode()
    {
        parent = nullptr;
        delete sons;
    }
    
    
    template <typename Tn>
    std::ostream & operator << (std::ostream & os, BNode<Tn>  & node)
    {
        os << node.info;
        
        return os;
    }