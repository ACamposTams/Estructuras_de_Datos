#include <iostream>
#include "Stack.h"
#include <string>

template <class T>
void expresion (Stack<T> *);

int main()
{
    Stack<char> * pila = new Stack<char>();
    
    expresion(pila);
    
    delete pila;
    
    return 0;
}

template <class T>
void expresion (Stack<T> * pila)
{
    std::string funcion;
    int estado = 0;
    
    std::cout << "Ingresa la expresión matemática" << std::endl;
    
    std::getline(std::cin,funcion);
    
    for(int i = 0; i<funcion.size();++i)
    {
        pila->push(funcion[i]);
    }
    
    int size = pila->size();
    
    for (int i = 0; i < size; ++i)
    {
         T compara = pila->pop()->getInfo();
         
         if (compara==*"(")
         {
             estado++;
         }
         
         else if (compara==*")")
         {
             estado--;
         }
    }
    
    if (estado!=0)
    {
        std::cout << "La ecuación no está balanceada" << std::endl;
    }
    else
    {
        std::cout << "La ecuación está balanceada" << std::endl;
    }
}