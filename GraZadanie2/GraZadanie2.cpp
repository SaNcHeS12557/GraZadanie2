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
#include "Menu.h"
#include "Gra.h"

// definicja gracze
Gracz Gracz::gracze[3] = { Gracz("Bryanusz"), Gracz("Jessica"), Gracz("Nepomucen") };

int main()
{
    //Gra kolory;

    Menu koloryGame;
    koloryGame.przetwarzacDane();
    koloryGame.nowaGra();

    
}
