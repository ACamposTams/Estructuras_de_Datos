#include <iostream>

#define N 4

void imprimeMatriz(int m[N][N], int n);
int salida(int lab[N][N], int filas, int columnas);
void guardarPos(int act1,int act2);
void regresar(int lab[N][N],int X, int Y);
int actX;
    int actY;

int main (int argc, const char * argv[])
{
    int matriz[N][N] = {0,-1,-1,-1,
                        0, 0, 0, 0,
                       -1,-1, 0,-1,
                       -1,-1, 0, 0};
    
    imprimeMatriz(matriz,N);
    
    std::cout << std::endl;
    
    salida(matriz,0,0);
    
    imprimeMatriz(matriz,N);
    
    return 1;
}

int salida(int lab[N][N],int filas, int columnas)
{
    
    lab[filas][columnas] = 1;
    
    if (filas==N-1 && columnas==N-1)
    {
        std::cout << "Fin" << std::endl;
    }
    else
    {
      if(filas == N-1)
      {
          if(lab[filas][columnas+1] == 0)
          {
            std::cout << "Derecha" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas,columnas+1);
          }
          else if(lab[filas][columnas-1] == 0)
          {
            std::cout << "Izquierda" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas,columnas-1);
          }
          else if(lab[filas-1][columnas] == 0)
          {
            std::cout << "Arriba" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas-1,columnas);
          }
      }
      
      if (columnas == N-1)
      {
          if(lab[filas+1][columnas] == 0)
        {
            std::cout << "Abajo" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas+1,columnas);
        }
        else if(lab[filas+1][columnas-1] == 0)
        {
            std::cout << "Regreso" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas+1,columnas-1);
        }
        else if(lab[filas][columnas-1] == 0)
        {
            std::cout << "Izquierda" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas,columnas-1);
        }
        else if(lab[filas-1][columnas] == 0)
        {
            std::cout << "Arriba" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas-1,columnas);
        }
      }
        if(lab[filas][columnas+1] == 0)
        {
            std::cout << "Derecha" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas,columnas+1);
        }
        else if(lab[filas+1][columnas] == 0)
        {
            std::cout << "Abajo" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas+1,columnas);
        }
        else if(lab[filas][columnas-1] == 0)
        {
            std::cout << "Izquierda" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas,columnas-1);
        }
        else if(lab[filas-1][columnas] == 0)
        {
            std::cout << "Arriba" << std::endl;
            lab[filas][columnas] = 1;
            salida(lab,filas-1,columnas);
        }
    }
}

void imprimeMatriz(int m[N][N], int n)
{
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
