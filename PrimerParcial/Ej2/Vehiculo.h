#include <iostream>

class Vehiculo
{
    protected:
    std::string codigo;
    std::string marca;
    int modelo;
    int kilometraje;
    
    public:
    Vehiculo(std::string,std::string,int modelo,int kilometraje);
};