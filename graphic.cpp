#include"mesfonctions.h"
#include <iostream>
using namespace std;


void drawgrid(RenderWindow &window)
{
	vector<sf::RectangleShape> lines;
	// Lignes verticales
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
	lines[5].setPosition(0, 117);
	lines[6].setPosition(0, 233);
	lines[7].setPosition(0, 350);
	lines[8].setPosition(0, 467);
	lines[9].setPosition(0, 584);
	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::White);
	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);

}


void drawpoint(RenderWindow &window)
{
	// création des points
	CircleShape circle(5);

	// affichage des points
	int i = 50, j = 90;
	while (j < 700)
	{
		while (i < 700)
		{
			circle.setPosition(i, j);
			i = i + 117;
			window.draw(circle);
		}
		j = j + 117;
	}

}


void drawword(RenderWindow &window, Word word, Word w2, int p1, int p2, Text text)

{
	
	Font font;

	Text text2;
	font.loadFromFile("arial.ttf");
	string s, s2, s3;
	int p3 = 0, p4 = -59, p5 = 0, p6 = -59, p7 = -59, p8 = -59, r = 0, b = 0, p9 = 25, c = 0;
	string s4 = MinToMaj(word.getNom());
	RectangleShape carre2(Vector2f(116, 116));
	carre2.setFillColor(Color::Black);
	while (window.isOpen())
	{
		drawgrid(window);
		Event event;
		
		while (window.pollEvent(event))
		{
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			// Affichage d'un mot tapé sur le clavier
			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode < 128)
				{
					c = 0;
					// On récupère les données des touches du clavier
					s = static_cast<char>(event.text.unicode);
					s3 += static_cast<char>(event.text.unicode);
					// transformation de la chaine en majuscule
					s = MinToMaj(s);
					s3 = MinToMaj(s3);
					// choix de la police à utiliser
					text.setFont(font); // font est un sf::Font

					// choix de la chaîne de caractères à afficher
					text.setString(s);
					// choix de la taille des caractères
					text.setCharacterSize(100); // exprimée en pixels, pas en points !

					// choix de la couleur du texte
					text.setFillColor(sf::Color::White);

					text.setPosition(p1, p2);
					p1 = p1 + 116;
					if (s3.size() > 6)
					{
						s3.resize(6);
					}

				}


			}

			// Evenement si on appui sur la touche entrer (ca pass a la ligne suivante et ca permet d'afficher les lettres bien ou mal placées)
			if (event.key.code == sf::Keyboard::Enter)
			{
				p2 = p2 + 58;
				p1 = 25;
				p4 = p4 + 59;
				p6 = p6 + 59;
				p7 = p7 + 59;
				p8 = p8 + 59;
				r = 0;
				b = 1;
				s2 = s3;
				s3 = "";

			}

			// Permet d'effacer un caractère rentré sur le clavier avec la touche backspace ou suppr
			if (event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Delete)

			{
				p1 = p1 - 116;
				s3.resize(s3.size() - 1);
				s = "";
				carre2.setPosition(p1, p2);
				c = 1;
			}

		}
		// Si c = 1 on veut effacer le dernier caractère rentré
		// Efface le caractère en mettant un carré noir sur la fenêtre
		if (c == 1)
		{

			window.draw(carre2);
			drawgrid(window);
		}
		else // sinon on affiche le dernier caractère rentré
		{
			window.draw(text);
		}

		//On verifie que la chaine rentré est bien de 6 lettres
		if (s2.size() == 6)
		{
			// Si on a bien validé le mot rentré avec la touche "entrer", b est à 1
			if (b == 1)
			{
				// On verifie alors si il y a des lettres mal placées
				for (int k = 0; k < 6; k++)
				{
					for (int l = 0; l < 6; l++)
					{
						if (s2[k] == s4[l])
						{
							drawreplace(window, p3 + k * 116, p7); // Affiche par un rond jaune les lettres mal placées
							text.setString(s2[k]);
							text.setPosition(p9 + k * 116, p8);
							window.draw(text);
						}
					}

				}
				// On verifie s'il y a des lettres bien placées
				for (int i = 0; i < 6; i++)
				{

					if (s2[i] == s4[i])
					{

						drawright(window, p3 + i * 116, p4); // Affiche par un carré rouge les lettres bien placées
						text.setString(s2[i]);
						r = r + 1;
						text.setPosition(p9 + i * 116, p6);
						window.draw(text);
					}
					else
						r = 0;
				}
			}
			drawgrid(window);
		}
		window.display();
	}
}

void drawright(RenderWindow &window, int p2, int p3) // fonction qui crée un carré rouge
{
	RectangleShape carre(Vector2f(117, 117));
	carre.setFillColor(Color::Red);
	carre.setPosition(p2, p3);
	window.draw(carre);
}

void drawreplace(RenderWindow &window, int p2, int p3) // fonction qui crée un rond jaune
{
	CircleShape circle(55);
	circle.setFillColor(Color::Yellow);
	circle.setPosition(p2, p3);
	window.draw(circle);
}

string MinToMaj(string s) // fonction qui fait conerti une chaine minuscule en majuscule
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
	return s;
}
