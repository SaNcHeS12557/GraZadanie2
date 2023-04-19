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

#include "Gracz.h"

// Konstruktor dla gracza
Gracz::Gracz(string i) {
	imie = i;
}
//