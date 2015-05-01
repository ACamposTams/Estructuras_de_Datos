#include <iostream>
#include <vector>
#include "Producto.h"
using namespace std;

class Contenedor
{
private:
	string nombre;
	vector<Producto> productos;
public:
	Contenedor() { }
	Contenedor(string);
	virtual ~Contenedor() {}
	
	string getNombre();
	void setNombre(string n);
	
	void insert(Producto);
	float getTotal() const;
	
	friend ostream & operator << (ostream &, const Contenedor &);
	
};

Contenedor::Contenedor(string n) : nombre(n)
{
    
}

string Contenedor::getNombre() 
{ 
    return nombre; 
}
	
void Contenedor::setNombre(string n) 
{ 
    this->nombre = n; 
}

void Contenedor::insert(Producto producto)
{
	productos.push_back(producto);
}

float Contenedor::getTotal() const
{
	float total = 0;
	for(auto i : productos)
	{
		total = total + i.getTotal();
	}
	
	return total;
}


ostream & operator << (ostream & os, const Contenedor & contenedor)
{
	os << "Nombre: " << contenedor.nombre << endl;
	for(auto i : contenedor.productos)
	{
		 os << i;
	}
	os << "Total del contenedor: $" << contenedor.getTotal() << endl << endl;
	return os;
}