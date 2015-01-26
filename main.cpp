#include <iostream>
#include <cstdlib> // se puede poner #include <ctime>
#include "Busqueda.h"
#include "Libro.h"

template <typename T>
void imprimeArreglo(T [], int);

int main (int argc, const char * argv[])
{
    const int longitud = 10;
    int enteros [longitud];
    
    for (int i=0; i<longitud; ++i)
    {
        enteros[i] = rand() % 100; // numeros entre 0 y 99
    }
    
    imprimeArreglo<int>(enteros,longitud);
    
    std::cout <<"Ingresa el elemento a busca: ";
    
    int valor;
    
    std::cin >> valor;
    
    bool existe = Busqueda<int>::busquedaSecuencial(enteros,valor,longitud);
    
    if (existe)
    {
        std::cout << "El valor existe" << std::endl;
    }
    else
    {
        std::cout << "El valor no existe" << std::endl;
    }
    
    return 0;
    
    //Busca Libros
    
    const int nlibros = 3;
    Libro biblioteca[nlibros];
    
    biblioteca[0] = Libro();
    biblioteca[1] = Libro("Cien Años de Soledad",1968,"1234");
    biblioteca[2] = Libro("El Arte de la Guerra",1900,"2345");
    
    imprimeArreglo<Libro>(biblioteca,nlibros);
}

template <typename T>
void imprimeArreglo( T v[], int size)
{
    for (int i=0; i < size; ++i )
    {
        std::cout << v[i] << " ";
    }
    
    std::cout << std::endl;
}