#include "Kalkulator.h"
#include <iostream>
#include <cmath>
#include <cstring>

void Kalkulator::blad(const std::string s)
{
	std::cerr << s << std::endl;
}

double Kalkulator::wyrazenie()
{
	double lewa = skladnik();

	for (;;)
		switch (biezacy_symbol)
		{
		case PLUS:
			daj_symbol();
			lewa += skladnik();
			break;
		case MINUS:
			daj_symbol();
			lewa -= skladnik();
			break;
		default:
			return lewa;
		}
}

double Kalkulator::subskladnik()
{
	double lewa = czynnik();

	for (;;)
		switch (biezacy_symbol)
		{
		case POTEGA:
			daj_symbol();
			lewa = pow(lewa, czynnik());
			break;
		case PROCENT:
			daj_symbol();
			lewa = lewa * czynnik() / 100;
			break;
		case PIERWIASTEK:
			daj_symbol();

			lewa = pow(lewa, (1 / czynnik()));
			break;
		default:
			return lewa;
		}
}

double Kalkulator::skladnik()
{
	double lewa = subskladnik();
	for (;;)
		switch (biezacy_symbol)
		{
		case MNOZENIE:
			daj_symbol();
			lewa *= subskladnik();
			break;
		case DZIELENIE:
			daj_symbol();
			d = skladnik();
			if (d == 0)
			{
				blad("Nie dziel przez 0 !!!");
				system("pause");
				system("cls");
			}
			lewa /= d;
			break;
		default:
			return lewa;
		}
}

double Kalkulator::czynnik()
{
	switch (biezacy_symbol)
	{
	case LICZBA:
		daj_symbol();
		return wartosc_liczby;
	case MINUS:
		daj_symbol();
		return -czynnik();
	case KONIEC:
		return 1;
	default:;
	}
	return 0;
}



