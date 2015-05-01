#include <iostream>
#include <stack>
#include <vector>
#include "Contenedor.h"

using namespace std;

int const m = 4;
int const	n = 4;

bool insertarProducto(int pila, unsigned int numcontenedor, vector<stack<Contenedor>> & almacen, Producto producto);
bool insertarContenedor(int pila, vector<stack<Contenedor>> & almacen, Contenedor contenedor);
void imprimir(vector<stack<Contenedor>> almacen);

int main()
{
	
	vector<stack<Contenedor>> almacen(m);

	insertarContenedor(0, almacen, Contenedor("A"));
	insertarContenedor(1, almacen, Contenedor("B"));
	insertarContenedor(2, almacen, Contenedor("C"));
	insertarContenedor(3, almacen, Contenedor("D"));

	insertarProducto(0, 0, almacen, Producto("Libros", 19, 10));
	insertarProducto(1, 0, almacen, Producto("Revistas", 10, 5));
	insertarProducto(0, 0, almacen, Producto("Televisiones", 5, 70));
	insertarProducto(2, 0, almacen, Producto("Computadoras", 2, 1200));
	insertarProducto(0, 1, almacen, Producto("Celulares", 4, 800));
	insertarProducto(1, 0, almacen, Producto("Juegos", 40, 900));
	
	imprimir(almacen);
	
	return 0;
}

bool insertarProducto(int pila, unsigned int numcontenedor, vector<stack<Contenedor>> & almacen, Producto producto)
{	
	if(pila >= m || pila < 0 || numcontenedor >= n || numcontenedor < 0)
	{
		return false;
	}
	else if(almacen[pila].size() <= numcontenedor)
	{
		return false;
	}
	else
	{
		stack<Contenedor> aux;
		for(int i = 0; i < numcontenedor; ++i)
		{
			aux.push(almacen[pila].top());
			almacen[pila].pop();
		}
		almacen[pila].top().insert(producto);
		
		while(!aux.empty())
		{
			almacen[pila].push(aux.top());
			aux.pop();
		}
		
		return true;
	}
	
}

bool insertarContenedor(int pila, vector<stack<Contenedor>> & almacen, Contenedor contenedor)
{
	if(pila >= m || pila < 0 || almacen[pila].size() >= m)
	{
		return false;
	}
	else
	{
		almacen[pila].push(contenedor);
		return true;
	}
}

void imprimir(vector<stack<Contenedor>> almacen)
{
	float total = 0;
	float pila = 0;
	int r = 0;
	for(auto i : almacen)
	{
		cout << endl << "Contendio de la Pila " << r+1 << endl;
		int j = 0;
		while(!i.empty())
		{
			cout << "Contenido del Contenedor " << j+1 << endl;
			cout << i.top();
			total = total + i.top().getTotal();
			pila = pila + i.top().getTotal();
			i.pop();
			++j;
		}
		cout << "Total de la pila: $" << pila << endl;
		pila = 0;
		++r;
	}
	cout << "Total del almacen: $" << total << endl;

}