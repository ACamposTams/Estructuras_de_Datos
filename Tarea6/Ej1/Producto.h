#include <iostream>
 
class Producto
{
 	private:
 	std::string nombre;
 	int cantidad;
 	float precio;
 	
 	public:
 	Producto(){}
 	~Producto() {}
 	Producto (std::string,int,float);
  	
  	void setNombre(std::string);
  	std::string getNombre();
  	
  	void setCantidad(int);
  	int getCantidad();
  	
  	void setPrecio(float);
  	float getPrecio();
  	
  	float getTotal();
  	
  	friend std::ostream & operator << (std::ostream &, const Producto &);
};
  
Producto::Producto(std::string n, int c, float p) : nombre(n), cantidad(c), precio(p) 
{
      
}
  
void Producto::setNombre(std::string name) 
{ 
 this->nombre = name; 
}
  
std::string Producto::getNombre() 
{ 
 return nombre; 
}
  
void Producto::setCantidad(int can)
{ 
 this->cantidad = can; 
}
  
  int Producto::getCantidad() 
  { 
      return cantidad; 
  }
  
  void Producto::setPrecio(float price) 
  { 
      this->precio = price; 
  }
  
  float Producto::getPrecio() 
  { 
  	return precio; 
  }
  
  
  float Producto::getTotal() 
  { 
  	return precio *cantidad; 
  }
  
  std::ostream & operator << (std::ostream & os, const Producto & producto)
  {
  	os << "Nombre del Producto: " << producto.nombre << std::endl << "Cantidad: " << producto.cantidad << std::endl << "Precio unitario: $" << producto.precio << std::endl << "Precio total: $" << producto.precio * producto.cantidad << std::endl << std::endl;
  	return os;
  }