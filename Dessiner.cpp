#pragma once
#include <iostream>
#include <fstream>
#include "Dessiner.h"
#include <string>

using namespace std;

Dessiner::Dessiner()
{
	
}


void Dessiner::drawletter(RenderWindow &window, Text text, Font font, char letter)
{
	// dans cette fonction, on définit l'endroit ou chaque lettre utilisée va etre écrite dans la fenetre
	// elle sont rangées par ordre alphabétique sous les mots "lettres utilisees"
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	switch (letter) {
	case 'A':
		text.setString('A');
		text.setPosition(720, 50);
		window.draw(text);
		break;
	case 'B':
		text.setString('B');
		text.setPosition(770, 50);
		window.draw(text);
		break;
	case 'C':
		text.setString('C');
		text.setPosition(820, 50);
		window.draw(text);
		break;
	case 'D':
		text.setString('D');
		text.setPosition(870, 50);
		window.draw(text);
		break;
	case 'E':
		text.setString('E');
		text.setPosition(920, 50);
		window.draw(text);
		break;
	case 'F':
		text.setString('F');
		text.setPosition(970, 50);
		window.draw(text);
		break;
	case 'G':
		text.setString('G');
		text.setPosition(720, 100);
		window.draw(text);
		break;
	case 'H':
		text.setString('H');
		text.setPosition(750, 100);
		window.draw(text);
		break;
	case 'I':
		text.setString('I');
		text.setPosition(770, 100);
		window.draw(text);
		break;
	case 'J':
		text.setString('J');
		text.setPosition(820, 100);
		window.draw(text);
		break;
	case 'K':
		text.setString('K');
		text.setPosition(870, 100);
		window.draw(text);
		break;
	case 'L':
		text.setString('L');
		text.setPosition(920, 100);
		window.draw(text);
		break;
	case 'M':
		text.setString('M');
		text.setPosition(970, 100);
		window.draw(text);
		break;
	case 'N':
		text.setString('N');
		text.setPosition(720, 150);
		window.draw(text);
		break;
	case 'O':
		text.setString('O');
		text.setPosition(770, 150);
		window.draw(text);
		break;
	case 'P':
		text.setString('P');
		text.setPosition(820, 150);
		window.draw(text);
		break;
	case 'Q':
		text.setString('Q');
		text.setPosition(870, 150);
		window.draw(text);
		break;
	case 'R':
		text.setString('R');
		text.setPosition(920, 150);
		window.draw(text);
		break;
	case 'S':
		text.setString('S');
		text.setPosition(970, 150);
		window.draw(text);
		break;
	case 'T':
		text.setString('T');
		text.setPosition(720, 200);
		window.draw(text);
		break;
	case 'U':
		text.setString('U');
		text.setPosition(770, 200);
		window.draw(text);
		break;
	case 'V':
		text.setString('V');
		text.setPosition(820, 200);
		window.draw(text);
		break;
	case 'W':
		text.setString('W');
		text.setPosition(870, 200);
		window.draw(text);
		break;
	case 'X':
		text.setString('X');
		text.setPosition(920, 200);
		window.draw(text);
		break;
	case 'Y':
		text.setString('Y');
		text.setPosition(970, 200);
		window.draw(text);
		break;
	case 'Z':
		text.setString('Z');
		text.setPosition(720, 250);
		window.draw(text);
		break;
	default:
		cout << "Invalid letter" << endl;
	}
}

void Dessiner::erase(RenderWindow &window, bool c, RectangleShape carre2, int h, Text text)
{
	// Si c = true on veut effacer le dernier caractère rentré
	if (c == true)
	{
		window.draw(carre2); // On efface le caractère en mettant un carré noir sur la fenêtre
		drawgrid(window); // on redessine la grille initiale pour avoir un affichage correct
	}
	else // sinon on affiche le dernier caractère rentré
	{
		if (h == false) // permet de réguler le nombre de lettres affichées sur la fenetre
		{
			window.draw(text);
		}
	}
}

void Dessiner::drawgrid(RenderWindow &window)
{
	Text text;
	Font font;
	font.loadFromFile("arial.ttf");
	vector<sf::RectangleShape> lines;
	// Lignes verticales
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(2, 700)));
	// Lignes horizontales
	lines.push_back(sf::RectangleShape(sf::Vector2f(700, 2)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(700, 2)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(700, 2)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(700, 2)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(700, 2)));
	// Positionnement des lignes
	lines[0].setPosition(117, 0);
	lines[1].setPosition(233, 0);
	lines[2].setPosition(350, 0);
	lines[3].setPosition(467, 0);
	lines[4].setPosition(584, 0);
	lines[5].setPosition(700, 0);
	lines[6].setPosition(0, 117);
	lines[7].setPosition(0, 233);
	lines[8].setPosition(0, 350);
	lines[9].setPosition(0, 467);
	lines[10].setPosition(0, 584);
	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::White);
	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);

	// Zone d'affichage des lettres utilisees a droite de la grille
	text.setFont(font);
	text.setString("LETTRES UTILISEES:");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Magenta);
	text.setPosition(720, 20);
	window.draw(text);

}

int Dessiner::Verify(RenderWindow &window, string s2, bool b, Text text2, Font font, Text text, string s4, int p3, int p4, int p6, int p7, int p8, int p9)
{
	int r = 0;
	//On verifie que la chaine rentré est bien de 6 lettres
	if (s2.size() == 6)
	{
		// Si on a bien validé le mot rentré avec la touche "entrer" et que ce mot existe, b est à vrai
		if (b == true)
		{
			for (int m = 0; m < 6; m++)
			{
				drawletter(window, text2, font, s2[m]); // écrit sur la fenetre chaque lettre utilisée
			}

			// On verifie si il y a des lettres mal placées
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 6; l++)
				{
					if (s2[k] == s4[l])
					{
						drawreplace(window, p3 + k * 116, p7, s2[k], text, p9, p8, k); // si elles sont mal placées, un rond jaune se dessinera autour d'elles
					}
				}

			}
			// On verifie s'il y a des lettres bien placées
			for (int i = 0; i < 6; i++)
			{

				if (s2[i] == s4[i])
				{

					drawright(window, p3 + i * 116, p4); // Affiche par un carré rouge autour de la lettre bien placée
					text.setString(s2[i]);
					r = r + 1; // s'il y a une letttre bien placée, on incrémente la variable r
					text.setPosition(p9 + i * 116, p6); // on redessine la lettre qui aura été cachée par le carré rouge
					window.draw(text);
				}
				else
					r = 0; // s'il n'y a aucune lettre bien placée, r est à 0
			}
			drawgrid(window);
		}
	}
	return r; // on retourne le nombre de lettre bien placées
}

void Dessiner::drawright(RenderWindow &window, int p2, int p3) 
{
	// cette fonction définie comment dessiner un carré rouge qui va correspondre aux lettres bien placées
	RectangleShape carre(Vector2f(117, 117));
	carre.setFillColor(Color::Red);
	carre.setPosition(p2, p3);
	window.draw(carre);
}

void Dessiner::drawreplace(RenderWindow &window, int p2, int p3, char s, Text text, int p9, int p8, int k)
{
	// cette fonction définie comment dessiner un rond jaune qui va correspondre aux lettres mal placées
	CircleShape circle(55);
	circle.setFillColor(Color::Yellow);
	circle.setPosition(p2, p3);
	window.draw(circle);
	text.setString(s);
	text.setPosition(p9 + k * 116, p8);
	window.draw(text); // on redessine la lettre qui aura été cachée par le rond jaune
}

void Dessiner::resultat(RenderWindow &window, int essai, int r, Text text2, Font font, string s4)
{
	Event event2;
	if (r == 6) // si le nombre de lettres bien placées vaut 6 alors on a résolu le motus
	{
		RenderWindow window1(sf::VideoMode(1000, 100), "Reponse"); // une fenetre réponse va s'ouvrir
		while (window1.isOpen())
		{
			while (window1.pollEvent(event2))
			{

				if (event2.type == sf::Event::Closed)
				{
					window1.close();
					window.close();
				}

			}
			// on affiche sur cette fenetre un message qui dit que l'on a gagné
			text2.setFont(font);
			text2.setString("Bravo! Tu as trouvé le mot " + s4);
			text2.setCharacterSize(50);
			text2.setFillColor(sf::Color::Red);
			window1.draw(text2);
			window1.display();
		}
	}
	// Si le nombre de tentatives maxium est atteint, on va ouvrir une fenetre réponse
	else if (essai == 12)
	{

		RenderWindow window1(sf::VideoMode(1000, 100), "Reponse");
		while (window1.isOpen())
		{
			while (window1.pollEvent(event2))
			{

				if (event2.type == sf::Event::Closed)
				{
					window1.close();
					window.close();
				}

			}
			// sur cette fenetre réponse va s'afficher la solution
			text2.setFont(font);
			text2.setString("Le mot etait " + s4);
			text2.setCharacterSize(50);
			text2.setFillColor(sf::Color::Red);
			window1.draw(text2);
			window1.display();
		}
	}


}
