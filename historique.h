#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Historique
{
	Font font;
	Text historique[7];//Un pour le titre, un pour la première ligne, un pour le retour au menu et un pour chaque partie affichée

public:
	Historique(float hauteur, float largeur); //construit l'historique et remplit les champs des historique[i]
	~Historique();

	void ecrireHistorique(string mot, int nb_essais, bool victoire); //remplit le fichier "historique.txt" avec les informations de la dernière partie jouée 
	vector<string> enregistrerHisto();
	void afficher(RenderWindow& window); //draw les champs de l'historique dans la fenêtre, sans l'afficher.
	void afficherHistorique(Historique historique, RenderWindow& window); //ouvre la fenêtre contenant l'historique et gère les clics de la souris pour retourner au menu
};
