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
    
    BNode<int> * nueve = new BNode<int>(9);
    numeros.insert(siete,nueve);
    
    std::cout << " ---- Árbol Original en preOrden ----" << std::endl;
    numeros.preOrder();
    std::cout << std::endl;
    
    bool simetric = numeros.simetria(numeros.getRoot()->getLeft(),numeros.getRoot()->getRight());
    
    if (simetric)
    {
        std::cout << "El árbol es simétrico" << std::endl;
    }
    else
    {
        std::cout << "El árbol no es simétrico" << std::endl;
    }
}