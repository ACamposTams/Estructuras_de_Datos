#pragma once
#include <iostream>
#include <vector>
#include "Relacion.h"

class Relacion;

class Persona
{
private:
	std::string nombre;
	int edad;
	std::vector<Relacion *> relaciones;
	
public:
	Persona() {}
	Persona(std::string n, int e) : nombre(n), edad(e) {}
	~Persona();
	
	std::string getNombre();
	void setNombre(std::string);
	
	int getEdad();
	void setEdad(int);
	
	std::vector<Relacion *> * getRelaciones();
	void addRelacion(Relacion * relacion);
	
	float getPromedio();
	void porcentajeRelacion() const;
	
	friend std::ostream & operator << (std::ostream & os, const Persona & persona);
};
