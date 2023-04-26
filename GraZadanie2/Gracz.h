class Gracz
{
public:
	string imie;
	int kasa = 0;
	int portfel = 0;
	Gracz(string i);
	Gracz(); // default konstruktor
	static Gracz gracze[3];
};

