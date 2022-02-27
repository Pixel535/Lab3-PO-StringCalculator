#pragma once
#include <iostream>
#include <cmath>
#include <cstring>

class Kalkulator
{
public:
	enum wartosc_symbolu
	{
		LICZBA, KONIEC, PLUS = '+', MINUS = '-', MNOZENIE = '*', DZIELENIE = '/', POTEGA = '^', DRUK = ';', PROCENT = '%', PIERWIASTEK = 'p'
	};
	std::string napis;
	wartosc_symbolu biezacy_symbol;
	double wartosc_liczby;
	int liczba_bledow;
	double d;
	double subskladnik();
	double skladnik();
	double czynnik();

	void blad(const std::string s);
	double wyrazenie();
	

	wartosc_symbolu daj_symbol()
	{
		int i = 0;
		std::string ch;

		do
		{
			if (!std::cin.get(ch[i]))
				return biezacy_symbol = KONIEC;
		} while (ch[i] != '\n' && isspace(ch[i]));


		switch (ch[i])
		{
		case ';':
		case '\n':
			return biezacy_symbol = DRUK;
		case '*':
		case '/':
		case '+':
		case '-':
		case '^':
		case '%':
		case 'p':
			return biezacy_symbol = wartosc_symbolu(ch[i]);
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
			std::cin.putback(ch[i]);
			std::cin >> wartosc_liczby;
			return biezacy_symbol = LICZBA;
		default:
			if (isalpha(ch[i]))
				std::cin.putback(ch[i]);
			std::cin >> napis;
			if (napis == "K")
				return biezacy_symbol = KONIEC;
			blad("Niepoprawny symbol!!!\n");

			return biezacy_symbol = DRUK;
		}
	}
};

