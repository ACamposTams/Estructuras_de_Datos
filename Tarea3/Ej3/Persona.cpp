#include "Persona.h"

Persona::Persona()
{

}
	
Persona::Persona(std::string n, std::string a, int e, std::string b) : nombre(n), apellidos(a), edad(e), birth(b)
{
	
}
	
void  Persona::setNombre(std::string n)
{
	this-> nombre = n;
}

std::string Persona::getNombre()
{
	return nombre;
}

void Persona::setApellidos(std::string a)
{
	this-> apellidos = a;
}
	
std::string Persona::getApellidos()
{
	return apellidos;
}

void Persona::setEdad(int e)
{
	this-> edad = e;
}

int Persona::getEdad()
{
	return edad;
}

void Persona::setBirth(std::string b)
{
	this-> birth = b;
}
	
std::string Persona::getBirth()
{
	return birth;
}

bool Persona::operator > (const Persona & persona)
{
    return apellidos > persona.apellidos;
}

std::ostream & operator << (std::ostream & os, Persona & persona)
{
	os << persona.getNombre() << " " << persona.getApellidos() << " " << persona.getEdad() << " " << persona.getBirth();
	return os;
}

bool Persona::operator==(Persona & persona)
{
    return (nombre == persona.nombre && apellidos == persona.apellidos); 
}
