#include <iostream>

class Persona
{
    public:
    Persona();
    Persona(std::string,std::string,std::string,int,int,int);
    ~Persona();
    
    void setNombre(std::string);
    std::string getNombre();
    
    void setPadre(std::string);
    std::string getPadre();
    
    void setEstado(std::string);
    std::string getEstado();
    
    void setAnio(int);
    int getAnio();
    
    void setMes(int);
    int getMes();
    
    void setDia(int);
    int getDia();
    
    private:
    std::string nombre;
    std::string padre;
    std::string estado;
    int anio;
    int mes;
    int dia;
    
    friend std::ostream & operator <<(std::ostream &, Persona &);
};

Persona::Persona()
{
    
}

Persona::Persona(std::string n,std::string p, std::string e, int a, int m, int d) : nombre(n),padre(p),estado(e),anio(a),mes(m),dia(d)
{
    
}

Persona::~Persona()
{
    
}

void Persona::setNombre(std::string n)
{
    this->nombre = n;
}

std::string Persona::getNombre()
{
    return nombre;
}
    
void Persona::setPadre(std::string p)
{
    this->padre = p;
}

std::string Persona::getPadre()
{
    return padre;
}
    
void Persona::setEstado(std::string e)
{
    this->estado = e;
}

std::string Persona::getEstado()
{
    return estado;
}

void Persona::setAnio(int a)
{
    this->anio = a;
}

int Persona::getAnio()
{
    return anio;
}

void Persona::setMes(int m)
{
    this->mes = m;
}

int Persona::getMes()
{
    return mes;
}

void Persona::setDia(int d)
{
    this->dia = d;
}

int Persona::getDia()
{
    return dia;
}

std::ostream & operator <<(std::ostream & os, Persona & persona)
{	
    if (persona.estado == "Vivo")
    {
        os << persona.nombre << " hijo de " << persona.padre << " Estado: " << persona.estado << std::endl;
        return os;
    }
    else
    {
        os << persona.nombre << " hijo de " << persona.padre << " Estado: " << persona.estado << " en " << persona.anio << "-" << persona.mes << "-" << persona.dia << std::endl;
        return os;
    }
}
