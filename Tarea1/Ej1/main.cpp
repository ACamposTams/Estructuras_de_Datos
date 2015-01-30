#include <iostream>
#include <math.h>

#define N 10

int ordena(int matriz[N][N],int, int);
void imprimeMatriz(int matriz[N][N], int);

int main (int argc, const char * argv[])
{
    int matriz[N][N] = {0};
    
    ordena(matriz,0,0);
    
    imprimeMatriz(matriz,N);
    
    return 1;
}

int ordena(int matriz[N][N],int filas, int columnas)
{
    if (filas==N-1 && columnas==N-1)
    {
        matriz[filas][columnas] = pow(2,N-1);
    }
    else if (filas==N-1)
    {
        matriz[filas][columnas] = pow(2,columnas);
        ordena(matriz,filas,columnas+1);
    }
    else if (columnas==N-1)
    {
        matriz[filas][columnas] = pow(2,filas);
        ordena(matriz,filas+1,0);
    }
    else if (columnas==filas)
    {
        matriz[filas][columnas] = pow(2,filas);
        ordena(matriz,filas,columnas+1);
    }
    else if (columnas>filas)
    {
        matriz[filas][columnas] = pow(2,filas);
        ordena(matriz,filas,columnas+1);
    }
    else if (columnas<filas)
    {
        matriz[filas][columnas]= pow(2,columnas);
        ordena(matriz,filas,columnas+1);
    }
}

void imprimeMatriz(int m[N][N], int n)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

