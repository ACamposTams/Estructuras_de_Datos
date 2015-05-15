#include "Persona.h"

std::string Persona::getNombre() 
{ 
	return nombre; 
}
	
void Persona::setNombre(std::string n) 
{ 
	nombre = n;
}
	
int Persona::getEdad() 
{ 
	return edad;
}
	
void Persona::setEdad(int e) 
{ 
	edad = e;
}

std::vector<Relacion *> * Persona::getRelaciones() 
{ 
	return &relaciones;
}

void Persona::porcentajeRelacion() const
{
	float tiempo = 0;
	
	for(auto i : relaciones)
	{
		tiempo = tiempo + i->getMeses();
	}
	
	float pct = tiempo/(edad*12);
	
	std::cout << "Porcentaje de tiempo de vida en una relacion: " << pct*100 << "%" << std::endl;
}

Persona::~Persona()
{
	for(auto i : relaciones)
	{
		i = nullptr;
	}
}

std::ostream & operator << (std::ostream & os, const Persona & persona)
{
	os << "Nombre: " << persona.nombre << std::endl;
	os << "Edad: " << persona.edad << std::endl;
	os << "Relaciones: " << persona.relaciones.size() << std::endl;
	
	persona.porcentajeRelacion();
	
	return os;
}

void Persona::addRelacion(Relacion * relacion)
{
	relaciones.push_back(relacion);
}

float Persona::getPromedio()
{
	if(relaciones.size() == 0)
	{
		return 0;
	}
	else
	{
		float cantidad = 0;
		
		for(auto i : relaciones)
		{
			cantidad = cantidad + i->getMeses();
		}
		
		float promedio;
		promedio = cantidad/ relaciones.size();
		return promedio;
	}
}