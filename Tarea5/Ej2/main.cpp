#include "BinaryTree.h"

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
    
    BinaryTree<int> reflexion;
    
    BNode<int> * raiz = new BNode<int>(numeros.getRoot()->getInfo());
    reflexion.setRoot(raiz);
    
    reflexion.reflect(numeros.getRoot(),reflexion.getRoot());
    
    std::cout << " ---- Árbol Reflejado en preOrden ----" << std::endl;
    reflexion.preOrder();
    std::cout << std::endl;
}