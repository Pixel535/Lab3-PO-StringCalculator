#include "Petla.h"

void Petla::petla()
{
	std::cout << "\nPodaj ciagiem dzialanie do obliczenia: " << std::endl;

	while (std::cin)
	{
		
		daj_symbol();
		if (biezacy_symbol == KONIEC) break;
		if (biezacy_symbol == DRUK) continue;
		std::cout << "\nWYNIK: " << wyrazenie() << std::endl;
		std::cout << "\nPodaj ciagiem dzialanie do obliczenia: " << std::endl;

	}
}