#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

// Valentin PONTIGGIA

class Menu
{
	Font font;
	Text menu[4]; // Un pour le titre et un pour chaque option du menu

public:
	Menu(float hauteur, float largeur); // Constructeur de la classe Menu : remplit les champs des menu[i]
	~Menu();
	void afficher(RenderWindow& window); // Dessine les champs du menu dans la fenêtre, sans l'afficher.
	void afficherMenu(Menu menu); // Ouvre la fenêtre contenant le menu et gère les clics de la souris pour ouvrir les différentes options du menu

};

Text textPointed(RenderWindow& window, Text& text); // Change la couleur du texte s'il est pointé (ne fonctionne pas)
