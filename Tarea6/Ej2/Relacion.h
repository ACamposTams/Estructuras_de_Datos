#pragma once
#include <iostream>
#include "Persona.h"

class Persona;

class Relacion
{
private:
	Persona * primera;
	Persona * segunda;
	int meses;
	
public:
	Relacion() {}
	Relacion(Persona *, Persona *, int);
	~Relacion();
	
	Persona * getPrimera();
	void setPrimera(Persona *);
	
	Persona * getSegunda();
	void setSegunda(Persona *);
	
	int getMeses();
	void setMeses(int);
	
	friend std::ostream & operator << (std::ostream & os, const Relacion & relacion);
};