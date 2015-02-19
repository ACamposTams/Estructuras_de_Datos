#include <iostream>

int convierte (int);

int main (int argc, const char * argv[])
{
    int numero;
    std::cout << "Dame el número que buscas converir a hexadecimal" << std::endl;
    
    std::cout << "El número en hexadecimal es: " << convierte(numero);
    
    return 1;
}

int convierte(int numero)
{
    
    if (numero%16 < 16)
    {
        return numero%16;
    }
    else
    {
        int residuo = numero/16;
        return convierte(residuo);
    }
}