#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "word.h"
#include"mesfonctions.h"
using namespace std;
using namespace sf;


int main()
{

	RenderWindow window(sf::VideoMode(700, 700), "Jeu");
	Word w("poules", 6);
	Word w1;

	int p1 = 20, p2 = 0;
	string s, s2;
	// Création d'un mot
	Text text;


		drawword(window, w, w1, p1, p2, text);
		//window.display();
	system("pause");
	return 0;
}
