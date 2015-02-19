#include <iostream>

class Motocicleta
{
    protected:
    int cilindraje;
    std::string codigo;
    std::string marca;
    int modelo;
    int kilometraje;
    
    public:
    Motocicleta();
    Motocicleta(std::string, std::string, int, int, int);
};