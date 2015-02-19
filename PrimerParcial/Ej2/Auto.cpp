#include "Auto.h"

Auto::Auto() : Auto("Sin marca", "Sin modelo",0,0)
{
    
}

Auto::Auto(std::string c, std::string m, int mod, int k) : codigo(c), marca(m), modelo(mod), kilometraje(k)
{
    
}