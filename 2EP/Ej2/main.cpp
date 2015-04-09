#include "LinkedList.h"

int main()
{
    LinkedList<int> * L = new LinkedList<int>();
    LinkedList<int> * R = new LinkedList<int>();
    
    L->insert(5,0);
    L->insert(5,4);
    L->insert(5,5);
    L->insert(1,6);
    L->insert(1,8);
    L->insert(1,9);
    L->insert(1,10);
    
    std::cout << *L << std::endl;
    
    int k = 0;
    int repite = 0;
    
    for(int j = 0; j<L->size();++j)
    {
        int valor = L->at(j)->getInfo();
        bool existe = false;
        int i = j+1;
        
        while (!existe && i<L->size())
        {
            repite = 0;
            if (L->at(i)->getInfo() == valor)
            {
                if (R->empty())
                {
                    R->insert(valor,k);
                    k++;
                }
                else
                {
                    for(int a = 0; a < R->size(); ++a)
                    {
                        if (valor == R->at(a)->getInfo())
                        {
                            repite = 1;
                        }
                    }
                    
                    if (repite == 0)
                    {
                        R->insert(valor,k);
                        k++;
                    }
                }
            }
            i++;
            existe = true;
        }
    }
    
    std::cout << *R;

}