#include "DCL_List.h"
#include <string.h>
#include <fstream>

void insertLine(DCL_List<DCL_List<std::string>*> *);
void deleteLine(DCL_List<DCL_List<std::string>*> *);
void insertWords(DCL_List<DCL_List<std::string>*> *);
void deleteWords(DCL_List<DCL_List<std::string>*> *);
void beggining(DCL_List<DCL_List<std::string>*> *);
void end(DCL_List<DCL_List<std::string>*> *);
void openFile(DCL_List<DCL_List<std::string>*> *);
void saveFile(DCL_List<DCL_List<std::string>*> *);
void showWriting(DCL_List<DCL_List<std::string>*> *);

DCL_List<std::string> * rowMaker (std::string);

typedef void (*t_seleccion) (DCL_List<DCL_List<std::string>*> *);

int main()
{ 
    DCL_List<DCL_List<std::string>*> * editor = new DCL_List<DCL_List<std::string>*>(); 
    
    int seleccion;
    
    while (seleccion!=10)
    {
        std::cout<<std::endl<<"Acciones Disponibles"<<std::endl;
        std::cout<<"Recuerde que para que el programa funcione debe de tener un archivo de texto llamado example.txt dentro de la carpeta"<<std::endl;
        std::cout<<"1.Abrir el Archivo \n2.Guardar el Archivo \n3.Insertar una Línea \n4.Borra< una Línea \n5.Insertar una Palabra \n6.Borra una Palabra \n7.Ir al Inicio \n8.Ir al Final \n9.Imprimir lo Escrito \n10.Salir" << std::endl;
        
        std::cin>>seleccion;
        std::cin.clear();
        
        t_seleccion selecciones[9];
        
        if (seleccion<10)
        {
            selecciones[0] = openFile;
            selecciones[1] = saveFile;
            selecciones[2] = insertLine;
            selecciones[3] = deleteLine;
            selecciones[4] = insertWords;
            selecciones[5] = deleteWords;
            selecciones[6] = beggining;
            selecciones[7] = end;
            selecciones[8] = showWriting;
            selecciones[seleccion-1](editor);
        }
    }
    
    delete editor;

    return 1;
}

void insertLine(DCL_List<DCL_List<std::string>*> *editor)
{
    std::string line;
    
    std::cin.ignore();
    std::cout << "Ingresa la línea que quieres insertar en el archivo" << std::endl;
    std::getline(std::cin,line);
    
    
    editor->insert(rowMaker(line),editor->size());
}

void deleteLine(DCL_List<DCL_List<std::string>*> * editor)
{
    int linea;
    
    std::cout << "Elige la línea que deseas borrar" << std::endl;
    std::cin>> linea;
    
    editor->remove(linea-1);
}

void beggining(DCL_List<DCL_List<std::string>*> * editor)
{
    int posicion;
    
    std::cout<<"Determine en que renglón quiere situarse al inicio" << std::endl;
    std::cin >> posicion;
    
    if (posicion > editor->size())
    {
        std::cout << "Ese renglón no existe" << std::endl;
    }
    else
    {
        std::cout << "El primer valor de ese renglón es: " << editor->at(posicion-1)->getInfo()->at(0)->getInfo() << std::endl;
    }
}

void end(DCL_List<DCL_List<std::string>*> * editor)
{
    int posicion;
    
    std::cout<<"Determine en que renglón quiere situarse al final" << std::endl;
    std::cin >> posicion;
    
    if (posicion > editor->size())
    {
        std::cout << "Ese renglón no existe" << std::endl;
    }
    else
    {
        int maximo = editor->at(posicion-1)->getInfo()->size();
        std::cout << "El último valor de ese renglón es: " << editor->at(posicion-1)->getInfo()->at(maximo-1)->getInfo() << std::endl;
    }
}

void insertWords(DCL_List<DCL_List<std::string>*> *editor)
{
    int posicion;
    std::cout << "Determine en que renglón quiere agregar una palabra nueva" << std::endl;
    std::cin >> posicion;
    
    if (posicion <= editor->size())
    {
        std::cout << *editor->at(posicion-1)->getInfo() << std::endl;
        int zona;
        std::cout << "Determine la posicon en la que quiere agregar la palabra o palabras, tome en cuenta que la primer palabra es la posición 1" << std::endl;
        std::cin >> zona;
        
        int opcion;
        std::cout << "Determine si quiere que se agreguen las nuevas palabras antes o después de la palabra \n1.Antes \n2.Después"<<std::endl;
        std::cin >> opcion;
        
        if (opcion == 1)
        {
            std::string line;
            std::cout << "Ingresa la línea que quieres insertar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin,line);
            
            DCL_List<std::string> * renglon = rowMaker(line);
            
            for(int j = 0; j<renglon->size(); ++j)
            {
                std::string mensaje = renglon->at((renglon->size())-j-1)->getInfo();
                editor->at(posicion-1)->getInfo()->insert(mensaje,zona-1);
            }

        }
        else if (opcion == 2)
        {
            std::string line;
            std::cout << "Ingresa la línea que quieres insertar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin,line);
            
            DCL_List<std::string> * renglon = rowMaker(line);
            
            for(int j = 0; j<renglon->size(); ++j)
            {
                std::string mensaje = renglon->at((renglon->size())-j-1)->getInfo();
                editor->at(posicion-1)->getInfo()->insert(mensaje,zona);
            }
        }
        else
        {
            std::cout << "Esa opcion no es válida" << std::endl;
        }
    }
    else
    {
        std::cout << "Ese renglón no existe" << std::endl;
    }
}

void deleteWords(DCL_List<DCL_List<std::string>*> * editor)
{
    int posicion;
    std::cout << "Determine en que renglón quiere eliminar una palabra nuevao más palabras" << std::endl;
    std::cin >> posicion;
    
    if (posicion <= editor->size())
    {
        std::cout << *editor->at(posicion-1)->getInfo() << std::endl;
        int zona;
        std::cout << "Determine la posicion a partir de la que quiere borrar la palabra o palabras, tome en cuenta que la primer palabra es la posición 1" << std::endl;
        std::cin >> zona;
        
        int opcion;
        std::cout << "Determine si quiere que se borre antes o después de la palabra \n1.Antes \n2.Después"<<std::endl;
        std::cin >> opcion;
        
        if (opcion == 1)
        {
            int eliminaciones;
            std::cout << "Escriba cuantas palabras desea eliminar antes de la palabra elegida" << std::endl;
            std::cin >> eliminaciones;
            
            int size = editor->size();
            
            zona--;

            for (int i = 1; i<=eliminaciones; ++i)
                {
                    editor->at(posicion-1)->getInfo()->remove(zona-eliminaciones);
                }
            
        }
        else if (opcion == 2)
        {
            int eliminaciones;
            std::cout << "Escriba cuantas palabras desea eliminar después de la palabra elegida" << std::endl;
            std::cin >> eliminaciones;
            
            for (int i = 1; i<=eliminaciones; ++i)
            {
                editor->at(posicion-1)->getInfo()->remove(zona);
            }
        }
        else
        {
            std::cout << "Esa opcion no es válida" << std::endl;
        }
    }
    else
    {
        std::cout << "Ese renglón no existe" << std::endl;
    }
}

void openFile(DCL_List<DCL_List<std::string>*> * editor)
{
    std::fstream file;
    file.open ("example.txt");
    
    if (file.is_open())
    {
        std::cout << "Archivo cargado" << std::endl;
        std::string line;
        
        int j = 0;
        
        while (getline(file,line))
        {
            DCL_List<std::string> * renglon = rowMaker(line);
            editor->insert(renglon,editor->size());
        }
    }
    else
    {
        std::cout << "No se encuentra el archivo" << std::endl;
    }
    
    file.close();
    
}

DCL_List<std::string> * rowMaker (std::string line)
{
    int i = 0;
    char charAux = line[i];
    DCL_List<std::string> * renglon = new DCL_List<std::string>();
    std::string temp;
    while (charAux) {
        if (charAux == ' ') {
            renglon->insertBack(temp);
            temp = "";
        }
        else
            temp += charAux;
        charAux = line[++i];
    }
    renglon->insertBack(temp);

    return renglon;
}
void saveFile (DCL_List<DCL_List<std::string>*> * editor)
{
    std::fstream file;
    file.open ("example.txt");
    file.clear();

    for (int i = 0; i < editor->size(); ++i)
    {
        for (int j = 0; j < editor->at(i)->getInfo()->size();++j)
        {
            file << editor->at(i)->getInfo()->at(j)->getInfo() << " ";
        }
        file << std::endl;
    }
    
    file.close();
}

void showWriting(DCL_List<DCL_List<std::string>*> * editor)
{
    for (int i = 0; i<editor->size(); ++i)
    {
         std::cout << * editor->at(i) << std::endl;
    }
}