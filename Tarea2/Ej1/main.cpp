#include <iostream>
#include "Libro.h"

void agregarLibro(int,Libro [],int);
bool eliminarLibro(int,Libro []);
int buscar(Libro [], Libro , int ,bool busca (Libro,Libro));
void publicadosAntes(int,Libro[]);
void publicadosDespues(int,Libro[]);
void publicadosEntre(int,Libro[]);
void mostrarAutor(int,Libro[]);
void mostrarEditorial(int,Libro[]);

int main (int argc, const char * argv[])
{
    int cantLibros = 10;
    int indice = cantLibros;
    
    Libro biblioteca[cantLibros];
    
    int opcion=1;
    while (opcion!=0)
    {
        std::cout <<"Bienvenido a la Biblioteca Virtual, por favor elige una opción: \n";
        std::cout <<"1. Agregar Libro \n";
        std::cout <<"2. Eliminar Libro \n";
        std::cout <<"3. Mostrar Libros Publicados de Acuerdo al Año\n";
        std::cout <<"4. Mostrar Libros por Autor \n";
        std::cout <<"5. Mostrar Libros por Editorial \n";
        std::cout <<"0. Salir \n";
        std::cin>>opcion;
        switch (opcion)
        {
            case 1:
            agregarLibro(cantLibros,biblioteca,indice);
            indice--;
            break;
            case 2:
            {
               if(eliminarLibro(cantLibros,biblioteca))
               {
                   indice++;
               } 
            }
            break;
            case 3:
            {
                int opcion2;
                while(opcion2!=0)
                {
                    std::cout <<"Selecciona el tipo de impresión: \n";
                    std::cout <<"1. Publicados Antes de la Fecha \n";
                    std::cout <<"2. Publicados Después de la Fecha \n";
                    std::cout <<"3. Publicados en un periodo de tiempo \n";
                    std::cout <<"0.Regresar \n";
                    std::cin>>opcion2;
                    switch (opcion2)
                    {
                        case 1:
                        publicadosAntes(cantLibros,biblioteca);
                        break;
                        case 2:
                        publicadosDespues(cantLibros,biblioteca);
                        break;
                        case 3:
                        publicadosEntre(cantLibros,biblioteca);
                        break;
                        case 0:
                        break;
                    }
                }
            }
            break;
            case 4:
            mostrarAutor(cantLibros,biblioteca);
            break;
            case 5:
            mostrarEditorial(cantLibros,biblioteca);
            break;
            case 0:
            std::cout<<"Hasta Luego \n";
            break;
        }
    }
    
  return 1;
}

void agregarLibro (int cantidad,Libro b[], int indice)
{
    
    if(indice==0)
    {
        std::cout<<"La biblioteca esta llena, borra algún libro para agregar uno nuevo" << std::endl;
    }
    else
    {
    std::string titulo;
    std::string autor;
    int paginas;
    int edicion;
    std::string editorial;
    int anio;
    
    std::cout<<"Agrega el Título del Libro"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,titulo);
    std::cout<<"Agrega el Autor del Libro"<<std::endl;
    std::cin.clear();
    std::getline(std::cin,autor);
    std::cout<<"Agrega el Número de Páginas del Libro"<<std::endl;
    std::cin>>paginas;
    std::cout<<"Agrega la Edición del Libro"<<std::endl;
    std::cin>>edicion;
    std::cout<<"Agrega la Editorial del Libro"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,editorial);
    std::cout<<"Agrega el Año de Publicación del Libro"<<std::endl;
    std::cin>>anio;
    
    b[cantidad-indice] = Libro(titulo,autor,paginas,edicion,editorial,anio);
    }
}

bool eliminarLibro (int cantidad,Libro b[])
{
    std::string titulo;
    std::cout << "Ingresa el título que buscas eliminar" << std::endl;
    std::cin >> titulo;
    
    int posicion = buscar(b,Libro(titulo,"no importa",0,0,"no importa",0),cantidad,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                              std::string segundo = b.getTitulo(); return primero==segundo;});
    
    if (posicion != 0)
    {
        std::cout << "Seguro que quieres borrar:" << std::endl;
        b->imprimirLibro(b,posicion-1);
        int decision;
        std::cout << "1. Si" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cin >> decision;
        if (decision == 1)
        {
            if(posicion-1 == cantidad)
            {
                b[posicion-1] = Libro();
            }
            else
            {
                for (int i=posicion-1; i<=cantidad-2;++i)
                {
                    b[i] = b[i+1];
                }
            }
        }
        else
        {
            std::cout << "No borrado" << std::endl;
            return false;
        }
    }
    return true;
}

int buscar(Libro v[], Libro valor, int size, bool busca (Libro,Libro))
{
    int lugar = 0;
    int i = 0;
    
    if (size <= 0)
    {
        return lugar;
    }
    
    while (lugar==0 && i<size)
    {
        if (busca(v[i++],valor))
        {
            lugar = i;
        }
    }
    return lugar;
}

void publicadosAntes(int size, Libro b[])
{
    int anio;
    std::cout << "Ingresa el año:" << std::endl;
    std::cin >> anio;
    
    Libro valor("No importa","No importa",0,0,"No importa",anio);
    
    int i = 0;
    
    if (size <= 0)
    {
        std::cout << "No se encuentra libros antes de ese año" << std::endl;
    }
    
    while (i<size)
    {
        if (b[i++] < valor)
        {
            b->imprimirLibro(b,i-1);
        }
    }
    
}

void publicadosDespues(int size, Libro b[])
{
    int anio;
    std::cout << "Ingresa el año:" << std::endl;
    std::cin >> anio;
    
   Libro valor("No importa","No importa",0,0,"No importa",anio);
    
    int i = 0;
    
    if (size <= 0)
    {
        std::cout << "No se encuentra libros despues de ese año" << std::endl;
    }
    
    while (i<size)
    {
        if (b[i++] > valor)
        {
            b->imprimirLibro(b,i-1);
        }
    }
}
void publicadosEntre(int size, Libro b[])
{
    int anio1;
    int anio2;
    std::cout << "Ingresa el primer año:" << std::endl;
    std::cin >> anio1;
    std::cout << "Ingresa el segundo año:" << std::endl;
    std::cin >> anio2;
    
    Libro valor("No importa","No importa",0,0,"No importa",anio1);
    Libro valor2("No importa","No importa",0,0,"No importa",anio2);
    
    int i = 0;
    
    if (size <= 0)
    {
        std::cout << "No se encuentra libros en ese rango" << std::endl;
    }
    
    while (i<size)
    {
        if (b[i++] >= valor && b[i++] <= valor2)
        {
            b->imprimirLibro(b,i-1);
        }
    }
}

void mostrarAutor(int size, Libro b[])
{
    std::string escritor;
    std::cout << "Ingresa el autor que buscas" << std::endl;
    std::cin>>escritor;
    
    Libro prueba("no importa",escritor,0,0,"no importa",0);
    
    int posicion = buscar(b,Libro("no importa",escritor,0,0,"no importa",0),size,[](Libro a, Libro b){ std::string primero = a.getAutor(); 
                                                                              std::string segundo = b.getAutor(); return primero==segundo;});
    b->imprimirLibro(b,posicion-1);
}

void mostrarEditorial(int size, Libro b[])
{
    std::string escritor;
    std::cout << "Ingresa el autor que buscas" << std::endl;
    std::cin>>escritor;
    
    Libro prueba("no importa",escritor,0,0,"no importa",0);
    
    int posicion = buscar(b,Libro("no importa","no importa",0,0,escritor,0),size,[](Libro a, Libro b){ std::string primero = a.getEditorial(); 
                                                                              std::string segundo = b.getEditorial(); return primero==segundo;});
    b->imprimirLibro(b,posicion-1);
}