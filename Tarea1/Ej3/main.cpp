#include <iostream>

#define N 3
#define M 4

int robot(int m[N][M],int, int);
void imprimeMatriz(int matriz[N][M]);

int main (int argc, const char * argv[])
{
    int matriz[N][M] = {0};
    
    imprimeMatriz(matriz);
    
    robot(matriz,0,0);
    
    std::cout << "Hay " << matriz[N-1][M-1] << " caminos en total" << std::endl;
    
    imprimeMatriz(matriz);
    
    return 1;
}

int robot(int m[N][M], int filas, int columnas)
{
    if(filas == N-1 && columnas == M-1)
    {
        m[N-1][M-1]++;
    }
    else if (filas>=N)
    {
        filas = N-1;
    }
    else if (columnas>=M)
    {
        columnas = M-1;
    }
    else
    {
        robot(m,filas,columnas+3);
        robot(m,filas+2,columnas);
    }
}

void imprimeMatriz(int m[N][M])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}