#pragma once
class Gra
{
private:
	static int zgadl;
	static int kolejka;
	static void textPlayers();
	static int jestSamogloska(char c);
	static char WczytajZnak();
	static char WczytajWybor();
	friend class Menu;
};

