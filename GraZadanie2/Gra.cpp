#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <locale.h>

using namespace std;

#include "Gra.h"
#include "Gracz.h"

void Gra::textPlayers()
{
	int i;
	std::cout << "\n";
	for (i = 0; i < 3; i++) {
		if (i == kolejka) {
			cout << "\033[1;34m";
		}
		cout << Gracz::gracze[i].imie << "\t" << Gracz::gracze[i].kasa << "\n";
		cout << "\033[0m";

	}
	cout << "\n";
}

int Gra::jestSamogloska(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
		return 1;
	else
		return 0;

}

char Gra::WczytajZnak()
{
	string letter;
	cin >> letter;

	while (letter.length() != 1)
	{
		cout << endl << "Type a single letter and press <enter>: ";
		cin >> letter;
	}

	for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
		c = toupper(c);

	return letter[0];

}

char Gra::WczytajWybor()
{
	char wybor;
	wybor = WczytajZnak();

	while (wybor != '1' && wybor != '2')
	{
		cout << endl << "Wybierz [1-2]: ";
		cin >> wybor;
	}

	return wybor;

}

int zgadl = 0;


