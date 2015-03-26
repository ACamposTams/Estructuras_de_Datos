#include "CircularLinkedList.h"
#include "Computadora.h"
#include "Node.h"

template <class T>
void agregarCompu(CircularLinkedList<T> *);
template <class T>
void removerCompu(CircularLinkedList<T> *);
template <class T>
void enviarMensaje(CircularLinkedList<T> *);
template <class T>
void startToken(CircularLinkedList<T> *);
template <class T>
void enviarToken(int destinatario, std::string mensaje, CircularLinkedList<T> * red);
template <class T>
void imprime(CircularLinkedList<T> *);

typedef void (*t_seleccion) (CircularLinkedList<Computadora> *);

int main()
{
    CircularLinkedList<Computadora> * Ring = new CircularLinkedList<Computadora>();
    
    int seleccion;
    
    while (seleccion!=5)
    {
        std::cout<<std::endl << "Acciones Disponibles" << std::endl;
        std::cout << "1.Añadir una Computadora \n2.Eliminar una Computadora \n3.Enviar Mensaje \n4.Mostrar Todas las Computadoras en la Red \n5.Salir"<<std::endl;
        std::cout << "Seleccione una opción" << std::endl;
        
        std::cin >> seleccion;
        std::cin.clear();
        
        t_seleccion selecciones[4];
        
        if (seleccion<5)
        {
            selecciones[0] = agregarCompu;
            selecciones[1] = removerCompu;
            selecciones[2] = enviarMensaje;
            selecciones[3] = imprime;
            selecciones[seleccion-1](Ring);
        }
    }
    
    delete Ring;
    
    return 1;
}

template <class T>
void agregarCompu(CircularLinkedList<T> * red)
{
    std::string name;
    
    std::cout << "Agrega el Nombre que Tendrá la Máquina" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,name);
    
    Computadora nueva(name,(red->size())+1,"No hay mensajes recientes");
    
    red->insert(nueva,red->size());
    
    if(red->size()>=2)
    {
        startToken(red);
    }
}

template <class T>
void removerCompu(CircularLinkedList<T> * red)
{
    if (red->empty())
    {
        std::cout << "No hay computadoras en la red" << std::endl;
    }
    else
    {
        std::cout << "Computadora" << " " << "Id" << std::endl;
        std::cout << * red << std::endl;
        int id;
        
        std::cout << "Ingresa el id de la máquina que deseas eliminar" << std::endl;
        std::cin >> id;
        
        if (id>red->size())
        {
            std::cout << "Esa computadora no se encuentra en esta red" << std::endl;
        }
        else
        {
            for (int i = id; i < red->size(); ++i)
            {
                Computadora copia (red->at(i)->getInfo().getNombre(),i,red->at(i)->getInfo().getMensajeReciente());
                red->at(i)->setInfo(copia);
            }
            red->remove(id-1);
        }
    }
}

template <class T>
void enviarMensaje(CircularLinkedList<T> * red)
{
    std::string mensaje;

    std::cout << "Escribe el mensaje a enviar, y después señala el destinatario según su id" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,mensaje);
    
    int destinatario;
    
    std::cin.clear();
    std::cout << "Destinatario" << std::endl;
    std::cin >> destinatario;
    std::cin.clear();
    
    if (destinatario <= red->size())
    {
        enviarToken(destinatario,mensaje,red);
    }
    else
    {
        std::cout << "Ese equipo no existe en la red" << std::endl;
    }
}

template <class T>
void startToken(CircularLinkedList<T> * red)
{
    Node<T> * token;
    token = red->first();
    
    for (int i=0; i<20;++i)
    {
        token = token->getNext();
    }
}

template <class T>
void enviarToken(int destinatario, std::string mensaje, CircularLinkedList<T> * red)
{
   
   Node<T> * token;
   token = red->first();
   
   while (token->getInfo().getId() != destinatario)
   {
       token = token->getNext();
   }

   Computadora copia (token->getInfo().getNombre(),token->getInfo().getId(),mensaje);
   
   red->at(token->getInfo().getId()-1)->setInfo(copia);
   
   std::cout << "El mensaje se ha enviado correctamente" << std::endl;
}

template <class T>
void imprime(CircularLinkedList<T> * red)
{
    if(red->empty())
    {
        std::cout << "No hay computadoras en la red" << std::endl;
    }
    else
    {
        std::cout << "Nombre " << "Id " << "Mensaje Reciente" << std::endl;
        std::cout << * red << std::endl;
    }
}