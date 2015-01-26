#include <iostream>

class Libro
{
    private:
    std::string titulo;
    int anio;
    std::string isbn;
    
    public:
    Libro();
    Libro(std::string, int, std::string);
    
    friend ostream & operator << (std::ostream &, Libro &);

};