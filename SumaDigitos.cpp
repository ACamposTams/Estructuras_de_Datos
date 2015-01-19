#include <iostream>

int sumaDigitos (int);

int main()
{
    int a = 123;
    
    std::cout << sumaDigitos(a);
    
    return 0;
}

int sumaDigitos(int numero)
{
    int residuo = numero % 10;
    numero = numero/10;
    
    if (numero == 0)
    {
        return residuo;
    }
    else
    {
        return residuo + sumaDigitos(numero);
    }
}