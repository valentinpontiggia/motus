#include <iostream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "historique.h"
#include"menu.h"
using namespace sf;
using namespace std;

void Historique::ecrireHistorique(string mot, int nb_essais, bool victoire) //à mettre dans fichier jeu
{
	fstream historique("historique.txt"); //ouvre le fichier historique.txt dans historique
	if (historique.is_open())
	{

		historique.seekp(0, ios::end); //place le curseur à la fin du fichier
		if (victoire)
			historique << "      " + to_string(nb_essais) + "               " + mot + "          Victoire" + "\n"; // rentre nb_essais dans le fichier historique.txt
		else
			historique << "      " + to_string(nb_essais) + "               " + mot + "          Défaite" + "\n";
	}
	historique.close();
}

vector<string> Historique::enregistrerHisto()
{
	vector<string> copieHisto;
	string histo;
	ifstream historique("historique.txt");
	if (historique.is_open())
	{
		while (getline(historique, histo))
			copieHisto.push_back(histo); //lit ligne par ligne le fichier historique.txt et écris chaque ligne dans un vecteur de string
	}
	historique.close();
	return copieHisto;
}


Historique::Historique(float largeur, float hauteur)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}
	ifstream file;
	vector<string> vectHisto = enregistrerHisto(); //crée le veteur de string contenant les lignes du fichier historique.txt
	vector<string> dernierscoups; //vecteur de string de destination qui contiendra ces lignes dans l'ordre inverse (seules les dernières parties nous intéressent)
	vector<string>::reverse_iterator it;

	for (it = vectHisto.rbegin(); it != vectHisto.rend(); it++)//on lit le vecteur-copie de historique.txt dans l'ordre inverse à l'aide d'un reverse iterator
	{
		dernierscoups.push_back(string(*it)); //et on écrit chacune de ces lignes dans le nouveau vecteur dernierscoups
	}
	for (int i = 0; i <= dernierscoups.size() && i < 4; i++) //
	{
		historique[i + 2].setFont(font);
		historique[i + 2].setFillColor(Color::White);
		historique[i + 2].setString(dernierscoups[i]);

	}
	historique[0].setFont(font);
	historique[0].setFillColor(Color::Red);
	historique[0].setCharacterSize(45);
	historique[0].setString("~ Historique ~");
	historique[0].setPosition(Vector2f(220, 120));

	historique[1].setFont(font);
	historique[1].setFillColor(Color::White);
	historique[1].setCharacterSize(38);
	historique[1].setString("Essais       Mot      Résultat");
	historique[1].setPosition(Vector2f(100, 250));

	historique[2].setPosition(Vector2f(100, 310));
	historique[3].setPosition(Vector2f(100, 360));
	historique[4].setPosition(Vector2f(100, 410));
	historique[5].setPosition(Vector2f(100, 460));

	historique[6].setFont(font);
	historique[6].setFillColor(Color::White);
	historique[6].setString("~ Retour au menu ~");
	historique[6].setPosition(Vector2f(220, 580));
}


Historique::~Historique()
{
}

void Historique::afficher(RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		window.draw(historique[i]);
	}
}

void Historique::afficherHistorique(Historique historique, RenderWindow& window)
{
	RenderWindow window1; // Nouvelle fenêtre pour l'historique
	Event event;
	window.close(); // Fermeture du menu
	window1.create(VideoMode(700, 700), "MOTUS");
	window1.clear();
	historique.afficher(window1);
	window1.display(); //affiche l'historique
	while (window1.isOpen())
	{
		while (window1.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
				if (event.mouseButton.x >= 200 && event.mouseButton.x <= 600)
				{
					if (event.mouseButton.y >= 550 && event.mouseButton.y <= 610) // Si on clique sur "Retour au menu"
					{
						window1.close();
						Menu menu(700, 700);
						menu.afficherMenu(menu); //retour au menu
					}
				}
		}
	}
}
