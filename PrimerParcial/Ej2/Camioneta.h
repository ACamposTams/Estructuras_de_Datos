#include <iostream>

class Camioneta
{
    public:
    Camioneta();
    Camioneta(std::string, std::string, int, int, std::string);
    
    protected:
    std::string traccion;
    std::string codigo;
    std::string marca;
    int modelo;
    int kilometraje;
};