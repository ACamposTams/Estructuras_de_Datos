#include <iostream>

int sumaV(int, int, int);

int main(int argc, const char * argv [])
{
    int a = 100;
    int arreglo[100];
    
    for (int i=0 ; i<a ; i++)
    {
        arreglo[i] = 1;
    }
    
    std::cout << "Suma = " << sumaV(arreglo,0,a) << std::endl;
    
    return 0;
}

int sumaV (int a[], int i, int size)
{
    if (i == size)
        return 0;
    else
        return a[i] + sumaV(a,i+1,size);
}