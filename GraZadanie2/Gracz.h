class Gracz
{
public:
	Gracz(string i);
	Gracz(); // default konstruktor
	static Gracz gracze[3];
	string imie;
	int kasa = 0;
	int portfel = 0;
private: 
friend class Menu;
friend class Gra;
};
