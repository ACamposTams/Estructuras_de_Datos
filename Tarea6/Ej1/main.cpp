 #include <iostream>
 #include <stack>
 #include <vector>
 #include "Contenedor.h"
 
 bool insertarProducto(Producto,int,int, std::vector<std::stack<Contenedor>> &,int,int);
 bool insertarContenedor(Contenedor,int, std::vector<std::stack<Contenedor>> &,int,int);
 void imprimir(std::vector<std::stack<Contenedor>>);
 
 int main()
 {
 	
 	int m = 4;
 	int	n = 4;
 	
 	std::vector<std::stack<Contenedor>> almacen(m);
 	
 	Contenedor A("A");
 	Contenedor B("B");
 	Contenedor C("C");
 	Contenedor D("D");
 	
 	insertarContenedor(A,0, almacen,m,n);
 	insertarContenedor(B,1, almacen,m,n);
  insertarContenedor(C,2, almacen,m,n);
  insertarContenedor(D,3, almacen,m,n);
  	
  	Producto libro("Libros", 19, 10);
  	Producto revista("Revistas", 10, 5);
  	Producto tele("Televisiones", 5, 70);
  	Producto compu("Computadoras", 2, 1200);
  	Producto celular("Celulares", 4, 800);
  	Producto horno("Hornos", 40, 900);
  	
  
  	insertarProducto(libro,0, 0, almacen,m,n);
  	insertarProducto(revista,1, 0, almacen,m,n);
  	insertarProducto(tele,0, 0, almacen,m,n);
  	insertarProducto(compu,2, 0, almacen,m,n);
  	insertarProducto(celular,0, 1, almacen,m,n);
  	insertarProducto(horno,1, 0, almacen,m,n);
  	
  	imprimir(almacen);
  	
  	return 0;
  }
  
  bool insertarProducto(Producto producto, int pila, int numcontenedor, std::vector<std::stack<Contenedor>> & almacen, int m, int n)
  {	
  	if(pila >= m||pila < 0||numcontenedor >= n||numcontenedor < 0)
  	{
  		return false;
  	}
  	else if(almacen[pila].size() <= numcontenedor)
  	{
  		return false;
  	}
  	else
  	{
  		std::stack<Contenedor> aux;
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
  
  void imprimir(std::vector<std::stack<Contenedor>> almacen)
  {
  	float total = 0;
  	float pila = 0;
  	int r = 0;
  	for(auto i : almacen)
  	{
  		std::cout << std::endl << "Contendio de la Pila " << r+1 << std::endl;
  		int j = 0;
  		while(!i.empty())
  		{
  			std::cout << "Contenido del Contenedor " << j+1 << std::endl;
  			std::cout << i.top();
  			total = total + i.top().getTotal();
  			pila = pila + i.top().getTotal();
  			i.pop();
  			++j;
  		}
  		std::cout << "Total de la pila: $" << pila << std::endl;
  		pila = 0;
  		++r;
  	}
  	std::cout << "Total del almacen: $" << total << std::endl;
  }
  
  bool insertarContenedor(Contenedor contenedor, int pila, std::vector<std::stack<Contenedor>> & almacen, int m , int n)
  {
  	if(pila >= m||pila < 0||almacen[pila].size() >= m)
  	{
  		return false;
  	}
  	else
  	{
  		almacen[pila].push(contenedor);
  		return true;
  	}
  } 