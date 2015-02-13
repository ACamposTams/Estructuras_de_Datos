//solo ordena en base al anio
#include <iostream>
#include "Libro.h"
#include "Ordenamiento.h"

int main (int argc, const char * argv[])
{
    int cantLibros = 10;
    int indice = cantLibros;
    
    Libro biblioteca[cantLibros];
    
    biblioteca[0] = Libro("Cien Años de Soledad","Gabriel García Márquez",200,1,"Sudamerica",1967);
    biblioteca[1] = Libro("EL Laberinto de la Soledas","Octavio Paz",200,3,"Fondo de Cultura",1950);
    biblioteca[2] = Libro("Rayuela","Julio Cortázar",200,2,"Sudamerica",1963);
    biblioteca[3] = Libro("Pedro Páramo","Juan Rulfo",200,1,"Fondo de Cultura",1955);
    biblioteca[4] = Libro("La Ciudad y los Perros","Mario Vargas Llosa",200,5,"Alfaguara",1962);
    biblioteca[5] = Libro("Don Quijote de la Mancha","Miguel de Cervantes Saavedra",200,1,"Juan de la Cuesta",1605);
    biblioteca[6] = Libro("La Divina Comedia","Dante Alighieri",200,2,"Alfaguara",1555);
    biblioteca[7] = Libro("El Amor en los Tiempos del Cólera","Gabriel García Márquez",200,3,"Sudamerica",1985);
    biblioteca[8] = Libro("To Kill a Mockingbird","Harper Lee",200,10,"Lippincot",1960);
    biblioteca[9] = Libro("Lord of the Flies","William Golding",200,4,"Faber and Faber",1954);
    
    int opcion=1;
    while (opcion!=0)
    {
        std::cout <<"Bienvenido a la Biblioteca Virtual, por favor elige una opción: \n";
        std::cout <<"1. Ordenar por Titulo \n";
        std::cout <<"2. Ordenar por Año \n";
        std::cout <<"3. Ordenar por Edición\n";
        std::cout <<"0. Salir \n";
        std::cin>>opcion;
        switch (opcion)
        {
            case 1:
            {
                int opcion1=1;
                while (opcion1!=0)
                {
                    std::cout <<"Selecciona el tipo de Ordenamiento \n";
                    std::cout <<"1. Ordeamiento por Burbuja \n";
                    std::cout <<"2. Ordenamiento por Inserción \n";
                    std::cout <<"3. Ordenamiento por Selección \n";
                    std::cout <<"0. Regresar \n";
                    std::cin>>opcion1;
                    switch (opcion1)
                    {
                        case 1:
                        {
                            int opcion11 = 1;
                            while (opcion11!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1.Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion11;
                                switch (opcion11)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                                
                            }
                        }
                        break;
                        case 2:
                        {
                            int opcion12 = 1;
                            while (opcion12!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1.Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion12;
                                switch (opcion12)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                        Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 3:
                        {
                            int opcion13 = 1;
                            while (opcion13!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1.Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion13;
                                switch (opcion13)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                        Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ std::string primero = a.getTitulo(); 
                                                                                                                 std::string segundo = b.getTitulo(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 0:
                        break;
                    }
                }
            }
            break;
            case 2:
            {
                int opcion2=1;
                while (opcion2!=0)
                {
                    std::cout <<"Selecciona el tipo de Ordenamiento \n";
                    std::cout <<"1. Ordeamiento por Burbuja \n";
                    std::cout <<"2. Ordenamiento por Inserción \n";
                    std::cout <<"3. Ordenamiento por Selección \n";
                    std::cout <<"0. Regresar \n";
                    std::cin>>opcion2;
                    switch (opcion2)
                    {
                        case 1:
                        {
                            int opcion21 = 1;
                            while (opcion21!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion21;
                                switch (opcion21)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                 int segundo = b.getAnio_pub(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                int segundo = b.getAnio_pub(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 2:
                        {
                            int opcion22 = 1;
                            while (opcion22!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion22;
                                switch (opcion22)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                 int segundo = b.getAnio_pub(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                int segundo = b.getAnio_pub(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 3:
                        {
                            int opcion23 = 1;
                            while (opcion23!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion23;
                                switch (opcion23)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                 int segundo = b.getAnio_pub(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getAnio_pub(); 
                                                                                                                int segundo = b.getAnio_pub(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 0:
                        break;
                    }
                }
            }
            break;
            case 3:
            {
                int opcion3=1;
                while (opcion3!=0)
                {
                    std::cout <<"Selecciona el tipo de Ordenamiento \n";
                    std::cout <<"1. Ordeamiento por Burbuja \n";
                    std::cout <<"2. Ordenamiento por Inserción \n";
                    std::cout <<"3. Ordenamiento por Selección \n";
                    std::cout <<"0. Regresar \n";
                    std::cin>>opcion3;
                    switch (opcion3)
                    {
                        case 1:
                        {
                            int opcion31 = 1;
                            while (opcion31!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion31;
                                switch (opcion31)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                 int segundo = b.getEdicion(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::burbuja(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                int segundo = b.getEdicion(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 2:
                        {
                            int opcion32 = 1;
                            while (opcion32!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion32;
                                switch (opcion32)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                 int segundo = b.getEdicion(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::insercion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                int segundo = b.getEdicion(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 3:
                        {
                            int opcion33 = 1;
                            while (opcion33!=0)
                            {
                                std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                                std::cout <<"1. Ascendente \n";
                                std::cout <<"2. Descendente \n";
                                std::cout <<"0. Regresar \n";
                                std::cin>>opcion33;
                                switch (opcion33)
                                {
                                    case 1:
                                    {
                                        Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                 int segundo = b.getEdicion(); return primero>segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 2:
                                    {
                                       Ordenamiento<Libro>::seleccion(biblioteca,cantLibros,[](Libro a, Libro b){ int primero = a.getEdicion(); 
                                                                                                                  int segundo = b.getEdicion(); return primero<segundo;});
                                        for (int i=0; i<cantLibros; ++i)
                                        {
                                            biblioteca->imprimirLibro(biblioteca,i);
                                        }
                                    }
                                    break;
                                    case 0:
                                    break;
                                }
                            }
                        }
                        break;
                        case 0:
                        break;
                    }
                }
            }
            case 0:
            break;
        }
    }
}
            