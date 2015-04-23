#include "BinaryTree.h"
#include "Persona.h"

void insertarPersona(BNode<Persona> *);
void visualizarDescendientes(BNode<Persona> *);
void indicarFallecimiento(BNode<Persona> *);
void buscarAncestros(BNode<Persona> *);
BNode<Persona> * buscarPersona (BNode<Persona> *,std::string);
void getDescendents(BNode<Persona> *);
void visualizaHermanos(BNode<Persona> *);
void buscaPrimos(BNode<Persona> *);
void buscarVivos(BNode<Persona> *);
void buscarFecha(BNode<Persona> *);
void fechaFallecidos(BNode<Persona> *,int,int,int);

typedef void (*seleccion) (BNode<Persona> *);

int main()
{
    BinaryTree<Persona> familia;
    Persona inicial("0","0","0",0,0,0);
    BNode<Persona> * inicio = new BNode<Persona>(inicial);
    familia.setRoot(inicio);
    
    int opcion;
    
    while(opcion!=8)
    {
        std::cout<<std::endl << "Acciones Disponibles" << std::endl;
        std::cout << "1.Añadir una Persona al Árbol (Procura ingresar primero la persona más vieja de la familia) \n2.Visualiza los Descendientes de una Persona \n3.Visualiza los Hermanos y Primos Hermanos de una Persona \n4.Visualiza los Ancestros de una Persona \n5.Establece un Miembro del Árbol como Fallecido \n6.Visualiza los Miembros que Fallecieron antes de una Fecha \n7.Visualiza los Miembros que aún están Vivos \n8.Salir" << std::endl;
        std::cout << "Seleccione una opción" << std::endl;
        
        std::cin >> opcion;
        
        seleccion opciones[7];
        
        if (opcion<8)
        {
            opciones[0] = insertarPersona;
            opciones[1] = visualizarDescendientes;
            opciones[2] = visualizaHermanos;
            opciones[3] = buscarAncestros;
            opciones[4] = indicarFallecimiento;
            opciones[5] = buscarFecha;
            opciones[6] = buscarVivos;

            opciones[opcion -1](familia.getRoot());
        }
    }
    
    return 0;
}

void insertarPersona(BNode<Persona> * raiz)
{
    std::string nuevoNombre;
    
    std::cout << "¿Cuál es el nombre de la persona que quieres agregar?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,nuevoNombre);
    
    std::string nuevoPadre;
    
    std::cout << "¿Cuál es el nombre del padre de la persona que quieres agregar?" << std::endl;
    std::getline(std::cin,nuevoPadre);
    
    int vida;
    
    std::cout << "¿La persona sigue viva?" << std::endl;
    std::cout << "1.Si \n2.No" << std::endl;
    std::cin >> vida;
    
    Persona nueva(nuevoNombre,nuevoPadre," ",0,0,0);
    
    if (vida == 1)
    {
        nueva.setEstado("Vivo");
    }
    else
    {
        nueva.setEstado("Fallecido");
        
        int year;
        std::cout<<"¿En que año falleció la persona? Ingreselo en formato completo (1994,2010)" << std::endl;
        std::cin >> year;
        
        int month;
        std::cout<<"¿En que mes falleció la persona?" << std::endl;
        std::cin >> month;
        
        int day;
        std::cout<<"¿En que día falleció la persona?" << std::endl;
        std::cin >> day;
        
        nueva.setAnio(year);
        nueva.setMes(month);
        nueva.setDia(day);
    }
    
    BNode<Persona> * nuevo = new BNode<Persona>(nueva);
    
    if (raiz->getInfo().getNombre() == "0")
    {
        raiz->setInfo(nueva);
    }
    else
    {
        if(buscarPersona(raiz,nuevoPadre))
        {
            if (!buscarPersona(raiz,nuevoPadre)->getLeft())
            {
                buscarPersona(raiz,nuevoPadre)->setLeft(nuevo);
                nuevo->setParent(buscarPersona(raiz,nuevoPadre));
            }
            else
            {
                buscarPersona(raiz,nuevoPadre)->setRight(nuevo);
                nuevo->setParent(buscarPersona(raiz,nuevoPadre));
            }
        }
        else
        {
            std::cout << "Esa persona no pertenece a la familia y no puede ser agregada" << std::endl;
        }
    }
}

void indicarFallecimiento(BNode<Persona> * raiz)
{
    std::string fallecido;
    
    std::cout << "¿Cuál es el nombre de la persona fallecida?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,fallecido);
    
    if (buscarPersona(raiz,fallecido))
    {
        BNode<Persona> * persona = buscarPersona(raiz,fallecido);
        if (persona->getInfo().getEstado() == "Fallecido")
    {
        std::cout << "Esa persona ya está marcada como fallecida" << std::endl;
    }
    else
    {
        int year;
        int month;
        int day;
        
        std::cout<<"¿En que año falleció la persona? Ingreselo en formato completo (1994,2010)" << std::endl;
        std::cin >> year;
        
        std::cout<<"¿En que mes falleció la persona?" << std::endl;
        std::cin >> month;

        std::cout<<"¿En que día falleció la persona?" << std::endl;
        std::cin >> day;
        
        Persona copia(persona->getInfo().getNombre(),persona->getInfo().getPadre(),"Fallecido",year,month,day);
        persona->setInfo(copia);
    }
    }
    else
    {
        std::cout << "Esa persona no se encuentra en el árbol" << std::endl;
    }
}

BNode<Persona> * buscarPersona (BNode<Persona> * node,std::string persona)
{
    if(node)
    {
        if(node->getInfo().getNombre() == persona)
        {
            return node;
        }
        else
        {
            if(buscarPersona(node->getLeft(),persona))
            {
                return buscarPersona(node->getLeft(),persona) ;
            }
            else if(buscarPersona(node->getRight(),persona))
            {
                return buscarPersona(node->getRight(),persona);
            }
            else
            {
                return nullptr;
            }
        }
    }
}

void visualizarDescendientes(BNode<Persona> * raiz)
{
    std::string nombre;
    std::cout << "¿Cuál es el nombre de la persona cuyos descendientes quieres ver?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);
    
    if (buscarPersona(raiz,nombre))
    {
        std::cout << "Estos son los descendientes mostrados en preOrden" << std::endl;
        getDescendents((buscarPersona(raiz,nombre)));
    }
    else
    {
        std::cout << "Esa persona no se encuentra en el árbol" << std::endl;
    }
}

void getDescendents(BNode<Persona> * node)
{
    if(node)
    {
        std::cout << *node << std::endl;
        getDescendents(node->getLeft());
        getDescendents(node->getRight());
    }
}

void getAncestros(BNode<Persona> * node)
{
    if(node->getParent())
    {
        std::cout << *node->getParent() << std::endl;
        getAncestros(node->getParent());
    }
}

void buscarAncestros(BNode<Persona> * raiz)
{
    std::string sucesor;
    std::cout << "¿Cuál es el nombre de la persona cuyos ancestros quieres ver?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,sucesor);
    
    if (buscarPersona(raiz,sucesor))
    {
        std::cout << "Estos son los ancestros" << std::endl;
        getAncestros((buscarPersona(raiz,sucesor)));
    }
    else
    {
        std::cout << "Esa persona no se encuentra en el árbol" << std::endl;
    }
}

void visualizaHermanos(BNode<Persona> * raiz)
{
    std::string nombre;
    
    std::cout << "¿Cuál es el nombre de la persona cuyos hermano y primos hermanos quieres ver?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);
    
    if(buscarPersona(raiz,nombre))
    {
        buscaPrimos(buscarPersona(raiz,nombre));
    }
    else
    {
        std::cout << "Esa persona no se encuentra en el árbol" << std::endl;
    }
}

void buscaPrimos(BNode<Persona> * persona)
{
    BNode<Persona> * padre;
    int continua = 0;
    
    while (continua!=1)
    {
        if (persona->getParent())
        {
            padre = persona->getParent();
            
             if (padre->getParent())
        {
            BNode<Persona> * abuelo = padre->getParent();
            
            if(padre->getLeft() && padre->getRight())
            {
                if(padre->getLeft()->getInfo().getNombre()==persona->getInfo().getNombre())
                {
                    std::cout << "El hermano de " << persona->getInfo().getNombre() << ": " << padre->getRight()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
                else if(padre->getRight()->getInfo().getNombre()==persona->getInfo().getNombre())
                {
                    std::cout << "El hermano de " << persona->getInfo().getNombre() << ": " << padre->getLeft()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
            }
            else
            {
                std::cout << "Esa persona no tiene hermanos" << std::endl;
            }
            
            BNode<Persona> * tio;
            
            if (abuelo->getLeft() && abuelo->getRight())
            {
                if (abuelo->getLeft()==padre)
                {
                    tio = abuelo->getRight();
                }
                else
                {
                    tio = abuelo->getLeft();
                }
                
                if(tio->getLeft() && tio->getRight())
                {
                    std::cout << "Primos de " << persona->getInfo().getNombre() << ": " << tio->getLeft()->getInfo().getNombre() << "," << tio->getRight()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
                else if (tio->getLeft())
                {
                    std::cout << "Primos de " << persona->getInfo().getNombre() << ": " << tio->getLeft()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
                else if (tio->getRight())
                {
                    std::cout << "Primos de " << persona->getInfo().getNombre() << ": " << tio->getRight()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
                else
                {
                    std::cout << "Este nodo no tiene primos" << std::endl;
                    continua = 1;
                }
            }
            else
            {
                std::cout << "El tío de esta persona no está registrado por lo que no se pueden buscar sus tíos" << std::endl;
                continua = 1;
            }
        }
        else
        {
            std::cout << "El abuelo de esta persona no está registrado por lo que no se podrán obtener sus primos" << std::endl;
            
            if(padre->getLeft() && padre->getRight())
            {
                if(padre->getLeft()->getInfo().getNombre()==persona->getInfo().getNombre())
                {
                    std::cout << "El hermano de " << persona->getInfo().getNombre() << ": " << padre->getRight()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
                else if(padre->getRight()->getInfo().getNombre()==persona->getInfo().getNombre())
                {
                    std::cout << "El hermano de " << persona->getInfo().getNombre() << ": " << padre->getLeft()->getInfo().getNombre() << std::endl;
                    continua = 1;
                }
            }
            else
            {
                std::cout << "Esa persona no tiene hermanos" << std::endl;
                continua = 1;
            }
        }
            
        }
        else
        {
            std::cout << "El padre de esta persona no está registrado en el árbol por lo que no se pueden buscar sus hermanos ni sus primos" << std::endl;
            continua = 1;
        }
    }
}

void buscarVivos(BNode<Persona> * persona)
{
    if(persona)
    {
        if(persona->getInfo().getEstado() == "Vivo")
        {
            std::cout << *persona << std::endl;
        }
        buscarVivos(persona->getLeft());
        buscarVivos(persona->getRight());
    }
}

void buscarFecha(BNode<Persona> * persona)
{
    int year;
    int month;
    int day;
    
    std::cout << "¿Antes de que año quiere buscar a las personas que fallecieron?" << std::endl;
    std::cin >> year;
    std::cout << "¿Antes de que mes quiere buscar a las personas que fallecieron?" << std::endl;
    std::cin >> month;
    std::cout << "¿Antes de que dia quiere buscar a las personas que fallecieron?" << std::endl;
    std::cin >> day;
    
    fechaFallecidos(persona,year,month,day);
}

void fechaFallecidos(BNode<Persona> * persona,int year,int month,int day)
{
    if(persona)
    {
        if (persona->getInfo().getAnio() < year)
        {
            if (persona->getInfo().getEstado() == "Fallecido")
            {
                std::cout << *persona << std::endl;
                fechaFallecidos(persona->getLeft(),year,month,day);
                fechaFallecidos(persona->getRight(),year,month,day);
            }
        }
        else if (persona->getInfo().getAnio() == year)
        {
            if (persona->getInfo().getMes() < month)
            {
                if (persona->getInfo().getEstado() == "Fallecido")
            {
                std::cout << *persona << std::endl;
                fechaFallecidos(persona->getLeft(),year,month,day);
                fechaFallecidos(persona->getRight(),year,month,day);
            }
            }
            else if (persona->getInfo().getMes() == month)
            {
                if (persona->getInfo().getDia() < day)
                {
                    if (persona->getInfo().getEstado() == "Fallecido")
                    {
                        std::cout << *persona << std::endl;
                        fechaFallecidos(persona->getLeft(),year,month,day);
                        fechaFallecidos(persona->getRight(),year,month,day);
                    }
                }
            }
        }
    }
}