#pragma once
class Gra
{
public:
	static char WczytajZnak();
	static int kolejka;
private:
	static int zgadl;
	static void textPlayers();
	static int jestSamogloska(char c);
	static char WczytajWybor();
	friend class Menu;
};

