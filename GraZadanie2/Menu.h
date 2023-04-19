#pragma once
class Menu
{
public:
	int n, i, j;
	int suma = 0;
	int kwota = 0;
	char wybor;
	string proba;
	string rezultat;
	int Kolo[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
	// -1 bankrut
	// 0 strata kolejki
	char literka;
	int sa_spolgloski = 0;
	string haslo; // = "wielka antarktyda";
	vector<string> hasla;
	void przetwarzacDane();
	int maska[100];
	void nowaGra();
};

