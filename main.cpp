#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "word.h"
#include "Application.h"
#include "menu.h"
#include "historique.h"
#include <ctime>
using namespace std;
using namespace sf;


int main()
{
	srand(time(NULL));
	Menu menu(700, 700);
	menu.afficherMenu(menu);

	system("pause");
	return 0;
}
