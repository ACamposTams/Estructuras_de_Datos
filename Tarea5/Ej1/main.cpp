#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

template <class T>
void extrae(BNode<T> * node,Stack<T>*);
template <class T>
void arbolNuevo(BNode<T> * node,Stack<T> * pila,Queue<T> *);
template <class T>
void insertar(BNode<T> *,BNode<T> *, Queue<T> *);

int main()
{
    BinaryTree<int> numeros;
    
    BNode<int> * uno = new BNode<int>(1);
    numeros.insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros.insert(uno, dos);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros.insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros.insert(dos, cuatro);
    
    BNode<int> * cinco = new BNode<int>(5);
    numeros.insert(dos, cinco);
    
    BNode<int> * seis = new BNode<int>(6);
    numeros.insert(tres,seis);
    
    BNode<int> * siete = new BNode<int>(7);
    numeros.insert(tres,siete);
    
    BNode<int> * ocho = new BNode<int>(8);
    numeros.insert(cuatro,ocho);
    
    std::cout << " ---- Árbol Original en preOrden ----" << std::endl;
    numeros.preOrder();
    std::cout << std::endl;
    
    Stack<int> * pila = new Stack<int>();
    Queue<int> * aux = new Queue<int>();
    
    BinaryTree<int> nuevo;
    
    arbolNuevo(numeros.getRoot(),pila,aux);
    
    BNode<int> * raiz = new BNode<int>(aux->dequeue()->getInfo());
    nuevo.insert(nullptr,raiz);
    
    insertar(numeros.getRoot(),nuevo.getRoot(),aux);
    
    std::cout << " ---- Árbol Sumado en preOrden ----" << std::endl;
    nuevo.preOrder();
    std::cout << std::endl;
    
    delete pila;
    delete aux;
}

template <class T>
void extrae(BNode<T> * node,Stack<T> * pila)
{
        if (node) 
        {
            pila->push(node->getInfo());
            extrae(node->getLeft(),pila);
            extrae(node->getRight(),pila);
        }
}

template <class T>
void insertar(BNode<T> * node,BNode<T> * nuevo, Queue<T> * aux)
{
    if (node->getLeft()) 
        {
            if(nuevo->getLeft())
            {
                if(node->getRight())
                {
                BNode<int> * temp = new BNode<int>(aux->dequeue()->getInfo());
                nuevo->setRight(temp);
                
                if(node->getRight()->getLeft())
                {
                    insertar(node->getRight(),nuevo->getRight(),aux);
                }
                }
                
            }
            else
            {
                BNode<int> * temp = new BNode<int>(aux->dequeue()->getInfo());
                nuevo->setLeft(temp);
                
                insertar(node->getLeft(),nuevo->getLeft(),aux);
                insertar(node,nuevo,aux);
            }
        }
}

template <class T>
void arbolNuevo(BNode<T> * node,Stack<T> * pila,Queue<T> * aux)
{
    if(node)
    {
        extrae(node,pila);
        
        int suma = 0;
        
        int tamanio = pila->size();
        
        for (int i = 0; i < tamanio;++i)
        {
            suma = suma + pila->pop()->getInfo();
        }
        
        aux->enqueue(suma);
        
        arbolNuevo(node->getLeft(),pila,aux);
        arbolNuevo(node->getRight(),pila,aux);
    }
}
