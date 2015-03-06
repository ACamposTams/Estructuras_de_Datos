#include <string>
#include <iostream>
#pragma once

class Persona
{

protected:
	std::string nombre;
	std::string apellidos;
	int edad;
	std::string birth;

public:
	Persona();
	Persona (std::string nombre, std::string apellidos, int edad, std::string birth);

	void setNombre(std::string);
	std::string getNombre();

	void setApellidos(std::string);
	std::string getApellidos();

	void setEdad(int);
	int getEdad();

	void setBirth(std::string);
	std::string getBirth();
	
	bool operator > (const Persona & persona);
	bool operator==(Persona & persona);
	
	friend std::ostream & operator << (std::ostream & os, Persona & persona);
};