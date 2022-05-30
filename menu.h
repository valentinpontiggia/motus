#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Menu
{
	Font font;
	Text menu[4];

public:
	Menu(float hauteur, float largeur);
	~Menu();
	void afficherMenu(Menu menu);
	void afficher(RenderWindow& window);

};

