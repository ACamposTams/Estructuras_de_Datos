#include <iostream>
using namespace std;

class Producto
{
	private:
	string nombre;
	int cantidad;
	float precio;
	
	public:
	Producto()  { }
	~Producto() {}
	Producto (string,int,float);
 	
 	void setNombre(string);
 	string getNombre();
 	
 	void setCantidad(int);
 	int getCantidad();
 	
 	void setPrecio(float);
 	float getPrecio();
 	
 	float getTotal();
 	
 	friend ostream & operator << (ostream &, const Producto &);
 };
 
 Producto::Producto(string n, int c, float p) : nombre(n), cantidad(c), precio(p) 
 {
     
 }
 
 void Producto::setNombre(string name) 
 { 
     this->nombre = name; 
 }
 
 string Producto::getNombre() 
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
 
 ostream & operator << (ostream & os, const Producto & producto)
 {
 	os << "Nombre del Producto: " << producto.nombre << endl << "Cantidad: " << producto.cantidad << endl << "Precio unitario: $" << producto.precio << endl << "Precio total: $" << producto.precio * producto.cantidad << endl << endl;
 	return os;
 } 
