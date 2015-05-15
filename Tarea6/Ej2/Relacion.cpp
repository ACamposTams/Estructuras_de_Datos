#include "Relacion.h"

Relacion::Relacion(Persona * p, Persona * s, int m) : primera(p), segunda(s), meses(m)
{
	primera->addRelacion(this);
	segunda->addRelacion(this);
}

Relacion::~Relacion()
{
	primera = nullptr;
	segunda = nullptr;
}

Persona * Relacion::getPrimera()
{ 
	return primera; 
}

void Relacion::setPrimera(Persona * p)
{ 
	primera = p;
}
	
Persona * Relacion::getSegunda() 
{ 
	return segunda;
}

void Relacion::setSegunda(Persona * s)
{ 
	segunda = s;
}
	
int Relacion::getMeses()
{ 
	return meses;
}

void Relacion::setMeses(int m)
{ 
	meses = m;
}

std::ostream & operator << (std::ostream & os, const Relacion & relacion)
{
	os << "Relación de " << relacion.meses << " meses ";
	os << "entre " << relacion.primera->getNombre() << " y " << relacion.segunda->getNombre() << " " << std::endl;
	os << std::endl;
	return os;
}