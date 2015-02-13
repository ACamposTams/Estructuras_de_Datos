#include "Libro.h"

Libro::Libro() : Libro("Sin título", "Sin autor",0,0, "Sin Editorial",0)
{
    
}

Libro::Libro(std::string t, std::string a, int num, int edic, std::string edit, int anio) : titulo(t), autor(a), num_pag(num), edicion(edic), editorial(edit), anio_pub(anio)
{
    
}

bool Libro::operator==(Libro & libro)
{
    return titulo == libro.titulo;
}

bool Libro::operator<(Libro & libro)
{
    return anio_pub < libro.anio_pub;
}

bool Libro::operator>(Libro & libro)
{
    return anio_pub > libro.anio_pub;
}

std::ostream & operator <<(std::ostream & os, Libro & libro)
{
    os << libro.titulo << " " << libro.autor << " " << libro.num_pag << " " << libro.edicion << " " << libro.editorial << " " << libro.anio_pub<< std::endl;
    
    return os;
}

void Libro::imprimirLibro(Libro biblioteca[], int posicion)
{
    std::cout << biblioteca[posicion] << " ";
}

int Libro::getAnio_pub()
{
    return anio_pub;
}

std::string Libro::getTitulo()
{
    return titulo;
}

int Libro::getEdicion()
{
    return edicion;
}