#include <iostream>
#include "Ordenamiento.h"
#include <cstdlib>

int main()
{
    int size = 1000;
    
    std::string data[size];
    
    for(int i=0;i<size;++i)
    {
        int cadena = 10+rand()%15;
        std::string caracter = "";
        for (int j=0; j<cadena;++j)
        {
            caracter += (char)(rand()%26+'a');
        }
        data[i] = caracter;
    }
    
    int opcion=1;
    while (opcion!=0)
    {
        std::cout <<"Selecciona el tipo de Ordenamiento \n";
        std::cout <<"1. Ordeamiento por Burbuja \n";
        std::cout <<"2. Ordenamiento por Inserción \n";
        std::cout <<"3. Ordenamiento por Selección \n";
        std::cout <<"0. Salir \n";
        std::cin>>opcion;
        switch (opcion)
        {
            case 1:
            {
                int opcion2 = 1;
                while (opcion2!=0)
                    {
                        std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                        std::cout <<"1.Ascendente \n";
                        std::cout <<"2. Descendente \n";
                        std::cout <<"0. Regresar \n";
                        std::cin>>opcion2;
                        switch (opcion2)
                        {
                            case 1:
                            Ordenamiento<std::string>::burbuja(data,size,[](std::string a, std::string b){return a>b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
                            }
                            break;
                            case 2:
                            Ordenamiento<std::string>::burbuja(data,size,[](std::string a, std::string b){return a<b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
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
                int opcion2 = 1;
                while (opcion2!=0)
                    {
                        std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                        std::cout <<"1.Ascendente \n";
                        std::cout <<"2. Descendente \n";
                        std::cout <<"0. Regresar \n";
                        std::cin>>opcion2;
                        switch (opcion2)
                        {
                            case 1:
                            Ordenamiento<std::string>::insercion(data,size,[](std::string a, std::string b){return a>b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
                            }
                            break;
                            case 2:
                            Ordenamiento<std::string>::insercion(data,size,[](std::string a, std::string b){return a<b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
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
                int opcion2 = 1;
                while (opcion2!=0)
                    {
                        std::cout <<"Selecciona la Dirección del Ordenamiento \n";
                        std::cout <<"1.Ascendente \n";
                        std::cout <<"2. Descendente \n";
                        std::cout <<"0. Regresar \n";
                        std::cin>>opcion2;
                        switch (opcion2)
                        {
                            case 1:
                            Ordenamiento<std::string>::seleccion(data,size,[](std::string a, std::string b){return a>b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
                            }
                            break;
                            case 2:
                            Ordenamiento<std::string>::seleccion(data,size,[](std::string a, std::string b){return a<b;});
                            for(int i=0; i<size;++i)
                            {
                                std::cout << data[i] << std::endl;
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