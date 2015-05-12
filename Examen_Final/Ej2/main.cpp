#include <iostream>

const int n = 9;

void alfombra(int[][n],int,int);

int main()
{
    
    int matriz[n][n];
    
    int iteraciones = 5;
    
    std::cout << "Cuadro inicial" << std::endl;
    
    for (int i=0; i<n; i++)
    {
        for (int j =0; j <n; ++j)
        {
            matriz[i][j] = 1;
        }
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j =0; j <n; ++j)
        {
            std::cout << matriz[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    alfombra(matriz,n,iteraciones);
    
    return 0;
}

void alfombra (int matriz[][n], int cuadrado,int iteraciones)
{
    if (iteraciones == 0)
    {
        std::cout << "Cuadro Final" << std::endl;
        for (int i=0; i<n; i++)
        {
            for (int j =0; j <n; ++j)
            {
                std::cout << matriz[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        int division = cuadrado/3;
        
        for (int i=division; i< division*2; i++)
        {
            for (int j = division; j < division*2 ; ++j)
            {
               matriz[i][j] = 0;
            }
        }
        
        alfombra(matriz,cuadrado/3,iteraciones-1);
    }
}