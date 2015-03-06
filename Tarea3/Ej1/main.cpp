#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
	int p;
	std::cout << "Ingresa el primer número" << std::endl;
	std::cin >> p;

	int q;
	std::cout << "Ingresa el último número" << std::endl;
	std::cin >> q;

	int n;
	std::cout << "Ingresa la cantidad de números que quieres encontrar" << std::endl;
	std::cin >> n;

	LinkedList<int> * primos = new LinkedList<int>();

	int k = 0;
	int a = 0;

	for (int i = p; i < q; ++i)
	{
		for (int j = 1; j < i+1; ++j)
		{
			if ((i%j)==0)
			{
				a++;
			}
		}
		
		if (a<=2)
		{
			primos->insertFront(i);
			k++;
		}
		
		if (k == n)
		{
			i = q;
		}
		
		a=0;
	}
	
	std::cout << *primos << std::endl;

	delete primos;
}
