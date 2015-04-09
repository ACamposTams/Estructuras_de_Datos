#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <string>

int main()
{
    std::string expresion = "(({3}+({1,4,2}))*({1,2,3,4,5}*{4,3,2,5}*{2,3,4,5,6}+{}))+{}";
    
    Stack<char> * pila = new Stack<char>();
    Queue<char> * aux = new Queue<char>();
    
    int estado = 0;
    int conjunto = 0;
    
    for (int i = 0; i < expresion.size(); ++i)
    {
        if (expresion[i] == *"(")
        {
            estado = 1;
        }
        
        if (expresion[i] == *"{")
        {
            conjunto = 1;
        }
        
        if (expresion[i] == *"}")
        {
            conjunto = 0;
        }
        
        if (conjunto == 1)
        {
            aux->enqueue(expresion[i]);
        }
        
    }
    
}