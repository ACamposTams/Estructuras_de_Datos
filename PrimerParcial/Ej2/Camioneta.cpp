#include "Camioneta.h"

Camioneta::Camioneta() : Camioneta("Sin marca", "Sin modelo",0,0,"Sin traccion")
{
    
}

Camioneta::Camioneta(std::string c, std::string m, int mod, int k, std::string t) : codigo(c), marca(m), modelo(mod), kilometraje(k), traccion(t)
{
    
}