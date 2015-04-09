#include "Stack.h"

int main()
{
    int valor = 255;
    
    Stack<int> * pila = new Stack<int>();
    
    while (valor/2 != 0 && valor!= 1)
    {
        int residuo = valor%2;
        pila->push(residuo);
        valor = valor/2;
    }
    
    pila->push(1);
    
    std::cout<<*pila;
    
    delete pila;
    
}