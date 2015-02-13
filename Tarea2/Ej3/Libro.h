#include <iostream>
#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    int anio_pub;
    int edicion;
    std::string editorial;
    int num_pag;
    
public:
    Libro();
    Libro(std::string, std::string, int, int, std::string, int);
    void imprimirLibro(Libro[],int);
    
    int getAnio_pub();
    std::string getTitulo();
    int getEdicion();
    
    bool operator==(Libro &);
    bool operator<(Libro &);
    bool operator>(Libro &);
    bool operator !=(Libro &);

    
    friend std::ostream & operator <<(std::ostream &, Libro &);
    
};