#include <iostream>

class Auto
{
    public:
    Auto();
    Auto(std::string, std::string, int, int);
    
    protected:
    std::string codigo;
    std::string marca;
    int modelo;
    int kilometraje;
};