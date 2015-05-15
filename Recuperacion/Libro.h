#include <iostream>

class Libro
{
    private:
    std::string titulo;
    int altura;
    bool guardado;
    
    public:
    Libro();
    Libro(std::string t, int a, bool) : titulo(t), altura(a) { guardado = false;}
    friend std::ostream & operator << (std::ostream & os, const Libro & libro);
    int getSize();
    bool getGuardado();
    void setGuardado();
    
};

std::ostream & operator << (std::ostream & os, const Libro & libro)
{
	os << "Titulo: " << libro.titulo << std::endl;
	
	return os;
}

int Libro::getSize()
{
    return altura;
}

bool Libro::getGuardado()
{
    return guardado;
}

void Libro::setGuardado()
{
    this->guardado = true;
}
