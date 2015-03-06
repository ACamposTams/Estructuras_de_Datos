#include <iostream>
#include "LinkedList.h"
#include "Node.h"

template <class T>
void laUnion (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[]);
template <class T>
void restaNM (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[]);
template <class T>
void restaMN (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[]);
template <class T>
void intersection (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[]);
template <class T>
void multi (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[]);

typedef void (*t_operacion) (LinkedList<int> [], LinkedList<int> [], LinkedList<int> []);

int main()
{
	int n;
	std::cout << "Ingresa la cantidad de números de la primera lista" << std::endl;
	std::cin >> n;
	
	LinkedList<int> * listaN = new LinkedList<int>();
	
	for (int i = 0; i<n ;++i)
	{
		int num;
		std::cout << "Ingresa el número " << i+1 << std::endl;
		std::cin >> num;
		listaN->insert(num,i);
	}

	int m;
	std::cout << "Ingresa la cantidad de números de la segunda lista" << std::endl;
	std::cin >> m;
	
	LinkedList<int> * listaM = new LinkedList<int>();
	
	for (int i = 0; i<m ;++i)
	{
		int num;
		std::cout << "Ingresa el número " << i+1 << std::endl;
		std::cin >> num;
		listaM->insert(num,i);
	}
	
	LinkedList<int> * listaP = new LinkedList<int>();
	
	std::cout << "Operaciones Disponibles" << std::endl;
	std::cout <<"1.Unión\n2.Resta N-M\n3.Resta M-N\n4.Intersección\n5.Multiplicación" << std::endl;
	std::cout <<"Seleccione una opción" << std::endl;
	
	int seleccion;
	
	std::cin>> seleccion;
	
	t_operacion operaciones[5];
	
	operaciones[0] = laUnion;
	operaciones[1] = restaNM;
	operaciones[2] = restaMN;
	operaciones[3] = intersection;
	operaciones[4] = multi;
	
	operaciones[seleccion-1](listaP,listaN,listaM);
	
	std::cout << "Lista N:" << *listaN << std::endl;
	std::cout << "Lista M:" << *listaM << std::endl;
	std::cout << "Lista P:" << *listaP << std::endl;

	delete listaM;
	delete listaN;
	delete listaP;
}

template <class T>
void laUnion (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[])
{
		for (int i = 0; i < n->size(); ++i)
		{
			p->insert(n->at(i)->getInfo(),i);
		}
		
		for (int i = 0; i < m->size(); ++i)
		{
			int repite = 0;
			
			for (int j = 0; j < p->size();++j)
			{
				if ((m->at(i)->getInfo())==(p->at(j)->getInfo()))
				{
					repite++;
				}
			}
			
			if (repite==0)
			{
				p->insert(m->at(i)->getInfo(),m->size()+i);
			}
		}
}

template <class T>
void restaNM (LinkedList<T> p[], LinkedList<T> primero[], LinkedList<T> segundo[])
{
	for (int i = 0; i < primero->size(); ++i)
		{
			int repite = 0;
			
			for (int j = 0; j < segundo->size();++j)
			{
				if ((primero->at(i)->getInfo())==(segundo->at(j)->getInfo()))
				{
					repite++;
				}
			}
			
			if (repite==0)
			{
				p->insert(primero->at(i)->getInfo(),i);
			}
		}
}

template <class T>
void restaMN (LinkedList<T> p[], LinkedList<T> primero[], LinkedList<T> segundo[])
{
	for (int i = 0; i < segundo->size(); ++i)
		{
			int repite = 0;
			
			for (int j = 0; j < primero->size();++j)
			{
				if ((segundo->at(i)->getInfo())==(primero->at(j)->getInfo()))
				{
					repite++;
				}
			}
			
			if (repite==0)
			{
				p->insert(segundo->at(i)->getInfo(),i);
			}
		}
}

template <class T>
void intersection (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[])
{
	for (int i = 0; i < m->size(); ++i)
		{
			int repite = 0;
			
			for (int j = 0; j < n->size();++j)
			{
				if ((m->at(i)->getInfo())==(n->at(j)->getInfo()))
				{
					repite++;
				}
			}
			
			if (repite!=0)
			{
				p->insert(m->at(i)->getInfo(),i);
			}
		}
}

template <class T>
void multi (LinkedList<T> p[], LinkedList<T> n[], LinkedList<T> m[])
{
	int pos=0;
	
	for (int i = 0; i < m->size(); ++i)
		{
			int repite = 0;
			
			for (int j = 0; j < n->size();++j)
			{
				int resultado = n->at(j)->getInfo() * m->at(i)->getInfo();
				
				p->insertBack(resultado);
			}
		}
}