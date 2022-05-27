#include <iostream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "historique.h"
using namespace sf;
using namespace std;

void Historique :: ecrireHistorique(int nb_essais)
{
	ofstream historique("historique.txt");
	historique << to_string(nb_essais) << endl;
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
	while (getline(file, nb_essais))
	{
	}
	historique[0].setFont(font);
	historique[0].setFillColor(Color::Red);
	historique[0].setCharacterSize(45);
	historique[0].setString("~ Historique ~");
	historique[0].setPosition(Vector2f(270, 120));

	historique[1].setFont(font);
	historique[1].setFillColor(Color::White);
	historique[1].setString("Dernier nombres de tentative :"+nb_essais);
	historique[1].setPosition(Vector2f(290, 320));

	historique[2].setFont(font);
	historique[2].setFillColor(Color::White);
	historique[2].setString("Moyenne de tentatives :"+strmoyenne);
	historique[2].setPosition(Vector2f(270, 450));
}


Historique::~Historique()
{
}

void Historique::afficher(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(historique[i]);
	}
}

void Historique::afficherHistorique(Historique historique)
{
	RenderWindow window(VideoMode(700, 700), "MOTUS");
	cout << "test reussi" << endl;
	window.clear();
	historique.afficher(window);
	window.display();
}
