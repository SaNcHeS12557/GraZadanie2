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

#include "Menu.h"
#include "Gra.h"
#include "Gracz.h"

void Menu::przetwarzacDane() {

	ifstream strum;
	strum.open("dane.txt");

	setlocale(LC_CTYPE, "Polish");

	while (!strum.eof())
	{
		string s;
		//strum >> s;
		getline(strum, s);
		//cout << s << endl;
		hasla.push_back(s);

	}

	strum.close();

	for (string item : hasla)
		cout << item << endl;

	cout << endl << endl;

	assert(hasla.size() > 0); // makros na sprawdzanie danych
	j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
	//cout << hasla[j];

	haslo = hasla[j];
	n = haslo.size();

	for (i = 0; i < n; i++)
	{
		if (haslo[i] == ' ')
			maska[i] = 0;
		else
			maska[i] = 1;
	}
}

void Menu::nowaGra() {
	do
	{
		cout << "\033[47m" << "\033[31m";
		for (i = 0; i < n; i++)
		{

			if (maska[i] == 1)
				cout << ".";
			else
				cout << haslo[i];
		}

		cout << "\033[0m";
		cout << endl;

		sa_spolgloski = 0;
		kwota = 0;

		for (i = 0; i < n; i++)
			if ((!Gra::jestSamogloska(haslo[i])) && (maska[i]))
			{
				sa_spolgloski = 1;
				break;
			}

		if (sa_spolgloski)
			cout << " -- Spolgloski sa --" << endl;

		Gra::textPlayers();

		cout << "1. zgaduj haslo" << endl;
		cout << "2. krecenie kolem" << endl;

		wybor = Gra::WczytajWybor();

		if (wybor == '1')
		{
			cout << "Podaj haslo" << endl;
			getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
			for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
				c = toupper(c);
			if (haslo == proba) {
				cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
				Gracz::gracze[Gra::kolejka].portfel += Gracz::gracze[Gra::kolejka].kasa;
				break;
			}
			else
			{
				Gra::kolejka = (Gra::kolejka + 1) % 3;
				suma = 1;
				cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
				cout << endl << "=================================================" << endl;
				continue;


			}



		}

		rezultat = "";
		i = rand() % 15;
		if (Kolo[i] == 0)
			rezultat = "Strata kolejki";
		if (Kolo[i] == -1)
			rezultat = "Bankrut";
		if (rezultat != "")
			cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
		else
		{
			cout << "\033[1;34m" << Kolo[i] << "\033[0m" << endl;
			kwota = Kolo[i];
		}

		// Strata kolejki i bankrut
		if ((Kolo[i] == 0) || (Kolo[i] == -1))
		{
			if (Kolo[i] == -1) // bankrut
				Gracz::gracze[Gra::kolejka].kasa = 0;

			Gra::kolejka = (Gra::kolejka + 1) % 3;
			suma = 1;
			cout << endl << "=================================================" << endl;

			// TODO
			// sleep for
			// kupowanie samoglosek

			continue;

		}

		cout << Gracz::gracze[Gra::kolejka].imie << ": Podaj litere" << endl;

		literka = Gra::WczytajZnak();

		Gra::zgadl = 0;

		if (Gra::jestSamogloska(literka))
			cout << "samogloska";
		else
			cout << "spolgloska";
		cout << endl;

		for (i = 0; i < n; i++)
		{
			if ((haslo[i] == literka) && (maska[i] == 1)) {
				maska[i] = 0;
				Gra::zgadl++;
			}
		}

		if (Gra::zgadl)
		{
			cout << "OK";
			Gracz::gracze[Gra::kolejka].kasa += kwota * Gra::zgadl;

			cout << endl << Gracz::gracze[Gra::kolejka].imie << "\033[1;32m " << Gracz::gracze[Gra::kolejka].kasa << "\033[0m";


		}
		else {
			cout << "Zle!";
			// strata kolejki
			Gra::kolejka = (Gra::kolejka + 1) % 3;
			cout << endl << "=================================================" << endl;
			suma = 1;
			continue;
		}

		cout << endl;

		suma = 0;

		for (i = 0; i < n; i++)
		{
			suma += maska[i];
		}



	} while (suma);
	cout << "BRAWO!";
	exit(0);

	Gra::textPlayers();
	Beep(523, 500);
}

