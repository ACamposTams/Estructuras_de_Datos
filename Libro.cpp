#include "Libro.h"

Libro::Libro()
{
    
}
Libro::Libro(std::string t, int ap, std::string i) : titulo(t),anio(ap),isbn(i)
{
    
}

std::ostream & operator << (std::ostream &, Libro &);
{
    os << libro.titulo << std::endl;
    
    return os;
}