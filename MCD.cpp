#include <iostream>

int mcd(int, int);

int main(int argc, const char * argv [])
{
    int m;
    std::cout << "Dame el primer número ";
    std::cin >> m;
    
    int n;
    std::cout << "Dame el segundo número ";
    std::cin >> n;
    
    mcd(m,n);
    
    return 0;
}

int mcd (int m, int n)
{
    int r = m%n;

    if (r == 0)
    {
        return r;
    }
    else
    {
        return mcd(n,r);
    }
}