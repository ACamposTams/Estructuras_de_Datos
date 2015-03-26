#include <iostream>

class Computadora
{
    public:
    Computadora() {}
    Computadora(std::string, int, std::string);
    
    std::string getNombre();
    void setNombre(std::string);
    
    int getId();
    void setId(int);
    
    std::string getMensajeReciente();
    void setMensajeReciente(std::string);
    
    protected:
    std::string nombre;
    int id;
    std::string mensajeReciente;
    
    friend std::ostream & operator <<(std::ostream &, Computadora &);
};

Computadora::Computadora(std::string nombre, int id, std::string mensajeReciente)
{
    this->nombre = nombre;
    this->id = id;
    this->mensajeReciente = mensajeReciente;
}

std::ostream & operator <<(std::ostream & os , Computadora & compu)
{
    os << compu.nombre << "   " << compu.id << "  " << compu.mensajeReciente;
    return os;
}

std::string Computadora::getNombre()
{
    return nombre;
}

void Computadora::setNombre(std::string name)
{
    this->nombre = name;
}
    
int Computadora::getId()
{
    return id;
}

void Computadora::setId(int clave)
{
    this-> id == clave;
}

std::string Computadora::getMensajeReciente()
{
    return mensajeReciente;
}

void Computadora::setMensajeReciente(std::string mensaje)
{
    this->mensajeReciente = mensaje;
}