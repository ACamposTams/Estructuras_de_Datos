#include <iostream>

void hanoi(int, int, int, int);

int main (int argc, const char * argv[])
{
    int discos = 0;
    std::cout << "Inserte número de discos: ";
    std::cin >> discos;
    
    if (discos<1)
    {
    std::cout << "El numero de discos debe ser mayor que 0"<<std::endl;
    return 1;
    }
    
    hanoi(discos,1,3,2);
    
    return 0;
}

void hanoi(int n, int x, int y, int z)
{
    if (n==1)
    {
        std::cout<<n<<":"<<x<<"-->"<<y<<std::endl;
    }
    else
    {
        hanoi(n-1,x,z,y);
        std::cout << n << ":" << x << "-->" << y << std::endl;
        hanoi(n-1,z,y,x);
    }
}