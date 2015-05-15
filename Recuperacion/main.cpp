#include <iostream>
#include "Libro.h"
#include <stack>
#include <vector>

const int N = 3;
const int M = 10;
const int K = 4;

void insertarLibros(std::vector<std::vector<Libro>>, std::vector<Libro>);

int main()
{
    std::vector<std::vector<Libro>> Mueble;
    
    Libro A ("Moby Dick",5,false);
    Libro B ("Tom Sawyer",8,false);
    Libro C ("Don Quijote",14,false);
    Libro D ("Homero",20,false);
    Libro E ("E",3,false);
    Libro F ("F",5,false);
    Libro G ("G",7,false);
    Libro H ("H",8,false);
    Libro I ("I",9,false);
    Libro J ("J",10,false);
    
    std::vector<Libro> Disponibles;
    
    Disponibles.push_back(A);
    Disponibles.push_back(B);
    Disponibles.push_back(C);
    Disponibles.push_back(D);
    Disponibles.push_back(E);
    Disponibles.push_back(F);
    Disponibles.push_back(G);
    Disponibles.push_back(H);
    Disponibles.push_back(I);
    Disponibles.push_back(J);
    
    int prolijidad;
    int minimo = Disponibles[0].getSize();
    
    for (int i = 0; i < N; ++i)
    {
        std::vector<Libro> Estante;
        
        int l = 1;

        for (auto j:Disponibles)
            {
                if (j.getSize() <= minimo && j.getGuardado()==false && l<=K)
                {
                    j.setGuardado();
                    Estante.push_back(j);
                    minimo = j.getSize();
                    l++;
                }
            }
        
        Mueble.push_back(Estante);
    }
    
    for (auto i:Mueble)
    {
        std::cout << "Estante" << std::endl;
        
        for (auto j:i)
        {
            std::cout << j;
        }
    }
    
}
