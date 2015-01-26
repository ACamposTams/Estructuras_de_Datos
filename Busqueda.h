#include <iostream>

template <class T> // o <<class T>>
class Busqueda
{
  public:
  
  static bool busquedaSecuencial(T [], T, int );
  static bool busquedaBinaria(T [], T, int);
};

template <typename T>
bool Busqueda<T>::busquedaSecuencial(T v[], T valor, int size)
{
    bool existe = false;
    int i = 0;
    
    if (size <= 0)
    {
        return false;
    }
    
    while (!existe && i<size)
    {
        if (v[i++] == valor)
        {
            existe = true;
        }
    }
    return existe;
}