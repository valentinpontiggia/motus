#include <iostream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "historique.h"
#include"menu.h"
using namespace sf;
using namespace std;

void Historique :: ecrireHistorique(int nb_essais)
{
	ofstream historique("historique.txt");
	historique << to_string(nb_essais) << endl; // rentre nb_essais dans le fichier historique.txt
	historique.close();
}

double Historique :: calculerMoyenne()
{
	ifstream historique;
	int total = 0;
	string nb_essais;
	int compteur = 0;
	historique.open("historique.txt");
	if (!historique.is_open())
		cout << "Le fichier n existe pas " << endl;
	else
		while (getline(historique, nb_essais))
		{
			int int_nb_essais = stoi(nb_essais);
			total = total + int_nb_essais;
			compteur++;
		}
	return (total / compteur);
}

Historique::Historique(float moyenne, float largeur, float hauteur)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}
	ifstream file;
	string nb_essais;
	string strmoyenne(to_string(moyenne));
	file.open("historique.txt");
	getline(file, nb_essais); // Récupère la première ligne du fichier historique.txt (= le dernier nb de tentatives)

	historique[0].setFont(font);
	historique[0].setFillColor(Color::Red);
	historique[0].setCharacterSize(45);
	historique[0].setString("~ Historique ~");
	historique[0].setPosition(Vector2f(220, 120));

	historique[1].setFont(font);
	historique[1].setFillColor(Color::White);
	historique[1].setString("Dernier nombres de tentative : "+nb_essais);
	historique[1].setPosition(Vector2f(100, 320));

	historique[2].setFont(font);
	historique[2].setFillColor(Color::White);
	historique[2].setString("Moyenne de tentatives : "+strmoyenne);
	historique[2].setPosition(Vector2f(100, 450));

	historique[3].setFont(font);
	historique[3].setFillColor(Color::White);
	historique[3].setString("~ Retour au menu ~");
	historique[3].setPosition(Vector2f(220, 580));
}


Historique::~Historique()
{
}

void Historique::afficher(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
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
	window1.display();
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
						menu.afficherMenu(menu);
					}
				}
		}
	}
}
