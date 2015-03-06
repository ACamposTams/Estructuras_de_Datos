#include <iostream>
#include "OrderedList.h"
#include "Node.h"
#include "Persona.h"

template <class T>
void agregar(OrderedList<T> []);
template <class T>
void buscar(OrderedList<T> []);
template <class T>
void borrarUna(OrderedList<T> v[]);
template <class T>
void imprimir(OrderedList<T> v[]);
template <class T>
void borrarTodas (OrderedList<T> v[]);
template <class T>
void verSize (OrderedList<T> v[]);

typedef void (*t_seleccion) (OrderedList<Persona> []);

int main()
{
	OrderedList<Persona> * personas = new OrderedList<Persona>();
	
	int seleccion;
	
	while (seleccion!=7)
	{
		std::cout << std::endl << "Acciones Disponibles" << std::endl;
		std::cout <<"1.Añadir una persona\n2.Buscar una persona\n3.Borrar una persona\n4.Ver todas las personas\n5.Borrar todas las personas\n6.Ver la cantidad de personas\n7.Salir"<<std::endl;
		std::cout <<"Seleccione una opción" << std::endl;
		
		std::cin >> seleccion;
	
		t_seleccion selecciones[6];
		
		if (seleccion<7)
		{
			selecciones[0] = agregar;
			selecciones[1] = buscar;
			selecciones[2] = borrarUna;
			selecciones[3] = imprimir;
			selecciones[4] = borrarTodas;
			selecciones[5] = verSize;
			selecciones[seleccion-1](personas);
		}
	}
}

template <class T>
void agregar(OrderedList<T> v[])
{
	std::cout << "Ingresa el Nombre de la Persona" <<std::endl;
	std::string nombre;
	std::cin.ignore();
    std::getline(std::cin,nombre);
	
	std::cout << "Ingresa los Apellidos de la Persona" <<std::endl;
	std::string apellidos;
    std::getline(std::cin,apellidos);
	
	std::cout << "Ingresa la Edad de la Persona" <<std::endl;
	int edad;
	std::cin >> edad;
	
	std::cout << "Ingresa la Fecha de Nacimiento en formato dia/mes/año(XXXX) de la Persona" <<std::endl;
	std::string fecha;
	std::cin >> fecha;
	
	Persona persona(nombre,apellidos,edad,fecha);
	v->insert(persona,v->size());
}

template <class T>
void buscar(OrderedList<T> v[])
{
	
	std::cout << "Ingresa el Nombre de la Persona Buscas" <<std::endl;
	std::string nombre;
	std::cin.ignore();
    std::getline(std::cin,nombre);
	
	std::cout << "Ingresa los Apellidos de la Persona que Buscas" <<std::endl;
	std::string apellidos;
	std::getline(std::cin,apellidos);
	
	int existe = -1;
    int indice = 0;
    
    Persona valor(nombre,apellidos,0,"No importa");
    
    while (existe == -1 && indice < v->size()) 
    {
        if (v->at(indice)->getInfo() == valor) 
        {
            existe = indice;
        }
        
        indice ++;
    }
    
    if (existe!=-1)
    {
    	std::cout << "La persona que buscas es:" << std::endl;
    	std::cout << *v->at(existe) << std::endl;
    }
    else
    {
    	std::cout << "Esa persona no está registrada" << std::endl;
    }
}

template <class T>
void borrarUna(OrderedList<T> v[])
{
	std::cout << "Ingresa el Nombre de la Persona Quieres Borrar" <<std::endl;
	std::string nombre;
	std::cin.ignore();
    std::getline(std::cin,nombre);
	
	std::cout << "Ingresa los Apellidos de la Persona que Quieres Borrar" <<std::endl;
	std::string apellidos;
	std::getline(std::cin,apellidos);
	
	int existe = -1;
    int indice = 0;
    
    Persona valor(nombre,apellidos,0,"No importa");
    
    while (existe == -1 && indice < v->size()) 
    {
        if (v->at(indice)->getInfo() == valor) 
        {
            existe = indice;
        }
        
        indice ++;
    }
    
    if (existe!=-1)
    {
    	std::cout << "La persona que borraste es:" << std::endl;
    	std::cout << *v->at(existe) << std::endl;
    	v->remove(existe);
    }
    else
    {
    	std::cout << "Esa persona no está registrada" << std::endl;
    }
}

template <class T>
void imprimir(OrderedList<T> v[])
{
	if (!v->empty())
	{
		std::cout << "Estas son las personas registradas" << std::endl;
		std::cout << *v << std::endl;
	}
	else
	{
		std::cout << "No hay personas registradas" << std::endl;
	}
}

template <class T>
void borrarTodas (OrderedList<T> v[])
{
	v->clear();
	std::cout << "Lista borrada" << std::endl;
}

template <class T>
void verSize (OrderedList<T> v[])
{
	std::cout << "El tamaño de la lista es: " << v->size() << std::endl;
}