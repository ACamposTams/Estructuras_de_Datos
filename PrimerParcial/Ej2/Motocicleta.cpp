#include "Motocicleta.h"

Motocicleta::Motocicleta() : Motocicleta("Sin marca", "Sin modelo",0,0,0)
{
    
}

Motocicleta::Motocicleta(std::string c, std::string m, int mod, int k, int cil) : codigo(c), marca(m), modelo(mod), kilometraje(k), cilindraje(cil)
{
    
}