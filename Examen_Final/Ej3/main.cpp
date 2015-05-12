#include <iostream>
#include "BinaryTree.h"

char armaArbol(BNode<char>*,std::string,std::string);

int main()
{
    
    std::string preOrden = "GEAIBMCLDFKJH";
    std::string enOrden = "IABEGLDCFMKHJ";
    
    BinaryTree<char> arbol;
    
    BNode<char> * raiz = new BNode<char> (preOrden[0]);
    
    arbol.setRoot(raiz);
    
    armaArbol(raiz,preOrden,enOrden);
    
    arbol.preOrder();
    
    return 0;
}

char armaArbol (BNode<char> * node, std::string pre, std::string en)
{
    int posPre;
    int posEn;
    
    if (node) 
    {            
        for (int i = 0; i < pre.size(); ++i)
        {
            if (pre[i] == node->getInfo())
            {
                posPre = i;
            }
        }
        
        for (int j = 0; j < en.size(); ++j)
        {
            if (en[j] == node->getInfo())
            {
                posEn = j;
            }
        }
        
        std::string left;
        std::string right;
        
        for (int i = 0; i < posEn; ++i)
        {
            left = left + en[i];
        }
        
        for (int i = posEn+1; i < en.size(); ++i)
        {
            right = right + en[i];
        }
        
        BNode<char> * leftie = new BNode<char>(pre[posPre+1]);
        node->setLeft(leftie);
        
        //armaArbol(leftie,pre,left);
        
        //armaArbol(node,pre,right);
    }
}