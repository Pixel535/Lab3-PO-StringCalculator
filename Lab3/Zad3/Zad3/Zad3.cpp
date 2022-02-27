// Zad3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <cmath>
#include <cstring>
#include "Petla.h"


int main()
{
	Petla petla;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Kalkulator" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Dzialania obslugiwane przez program: [+] [-] [*] [/] [^] [p] [%]" << std::endl;
	std::cout << "Aby wyjsc z programu wpisz: [K]" << std::endl;
	petla.petla();
}
