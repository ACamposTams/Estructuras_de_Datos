#include <iostream>
#include <vector>
#include "Producto.h"
 
class Contenedor
{
    private:
 	std::string nombre;
 	std::vector<Producto> productos;
  public:
 	Contenedor() { }
 	Contenedor(std::string);
 	~Contenedor() {}
 	
  	std::string getNombre();
  	void setNombre(std::string n);
  	
  	void insert(Producto);
  	float getTotal() const;
  	
  	friend std::ostream & operator << (std::ostream &, const Contenedor &);
  	
  };
  
  Contenedor::Contenedor(std::string n) : nombre(n)
  {
      
  }
  
  std::string Contenedor::getNombre() 
  { 
      return nombre; 
  }
  	
  void Contenedor::setNombre(std::string n) 
  { 
      this-> nombre = n; 
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
  
  
  std::ostream & operator << (std::ostream & os, const Contenedor & contenedor)
  {
  	os << "Nombre: " << contenedor.nombre << std::endl;
  	for(auto i : contenedor.productos)
  	{
  		os << i;
  	}
  	os << "Total del contenedor: $" << contenedor.getTotal() << std::endl << std::endl;
  	return os;
  } 