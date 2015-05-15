#include <iostream>
#include "Persona.h"
#include "Relacion.h"
#include <vector>

void addPersona(std::string nombre, int edad, std::vector<Persona *> & personas);
void generarRelacion(int pos1, int pos2, int meses, std::vector<Persona *> & personas, std::vector<Relacion *> & relaciones);
void mostrarRelaciones(std::vector<Relacion *> & relaciones);
void sinRelaciones(std::vector<Persona *> & personas);
void masRelaciones(std::vector<Persona *> & personas);
void masEstable(std::vector<Persona *> & personas);

int main()
{
	std::vector<Relacion *> relaciones;
	std::vector<Persona *> personas;
	
	addPersona("Alfredo Campos", 19, personas);
	addPersona("Juan Perez", 18, personas);
	addPersona("Marco Lopez", 25, personas);
	addPersona("Laura Jimenez", 23, personas);
	addPersona("Lucia Rodriguez", 25, personas);
	addPersona("Maria Enriquez", 19, personas);
	addPersona("Clara Casas", 22, personas);
	addPersona("Elizabeth Dominguez", 21, personas);
	
	generarRelacion(0, 4, 2, personas, relaciones);
	generarRelacion(0, 3, 10, personas, relaciones);
	generarRelacion(1, 5, 5, personas, relaciones);
	generarRelacion(2, 5, 1, personas, relaciones);
	
	mostrarRelaciones(relaciones);
	sinRelaciones(personas);
	masRelaciones(personas);
	masEstable(personas);
	
	return 0;
}

void addPersona(std::string nombre, int edad, std::vector<Persona *> & personas)
{
	Persona * p = new Persona(nombre,edad);
	personas.push_back(p);
}

void generarRelacion(int pos1, int pos2, int meses, std::vector<Persona *> & personas, std::vector<Relacion *> & relaciones)
{
	Relacion * r = new Relacion(personas[pos1], personas[pos2], meses);
	relaciones.push_back(r);
}

void mostrarRelaciones(std::vector<Relacion *> & relaciones)
{
	std::cout << "Relaciones" << std::endl;
	for(auto i : relaciones)
	{
		std::cout << *i;
	}
}

void sinRelaciones(std::vector<Persona *> & personas)
{
	std::cout << "Persona sin relaciones" << std::endl;
	
	for(auto i : personas)
	{
		if(i->getRelaciones()->size() == 0)
		{
			std::cout << *i << std::endl;
		}
	}
}

void masRelaciones(std::vector<Persona *> & personas)
{
	Persona * max = personas[0];
	
	for(auto p : personas)
	{
		if(p->getRelaciones()->size() > max->getRelaciones()->size())
		{
			max = p;
		}
	}
	
	std::cout << "Persona con mas relaciones: " << std::endl;
	std::cout << *max << std::endl;
}

void masEstable(std::vector<Persona *> & personas)
{
	Persona * estable = personas[0];
	for(auto p : personas)
	{
		if(p->getPromedio() > estable->getPromedio())
		{
			estable = p;
		}
	}
	std::cout << "Persona mas estable: " << std::endl;
	std::cout << *estable;
	std::cout << "Promedio de duración de una relacion: " << estable->getPromedio() << " meses" << std::endl << std::endl;
}