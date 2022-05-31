#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

// PONTIGGIA Valentin

class Historique
{
	Font font;
	Text historique[7];// Un pour le titre, un pour la première ligne, un pour le retour au menu et un pour chaque partie affichée

public:
	Historique(float hauteur, float largeur); // Constructeur de la classe Historique : remplit les champs des historique[i]
	~Historique();

	void ecrireHistorique(string mot, int nb_essais, bool victoire); // Remplit le fichier "historique.txt" avec les informations de la dernière partie jouée 
	vector<string> enregistrerHisto(); // Enregistre les lignes de historique.txt dans un vecteur de string
	void afficher(RenderWindow& window); // Draw les champs de l'historique dans la fenêtre, sans l'afficher.
	void afficherHistorique(Historique historique, RenderWindow& window); // Ouvre la fenêtre contenant l'historique et gère les clics de la souris pour retourner au menu
};
