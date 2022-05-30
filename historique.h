#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Historique
{
	Font font;
	Text historique[4];

public:
	Historique(float hauteur, float largeur, float moyenne);
	~Historique();

	void ecrireHistorique(int nb_essais);
	void afficher(RenderWindow& window);
	void afficherHistorique(Historique historique, RenderWindow& window);
	double calculerMoyenne();

};
