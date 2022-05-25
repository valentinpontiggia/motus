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
	font.loadFromFile("arial.ttf");
	string s, s2;
	int p3 = 0, p4 = 0, p5 = 20, p6 = 0;
	string s3 = MinToMaj(word.getNom());
	while (window.isOpen())
	{
		drawgrid(window);
		Event event;
		while (window.pollEvent(event))
		{
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			// Affichage d'un mot
			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode < 128)
				{
					s = static_cast<char>(event.text.unicode);
					s2 += static_cast<char>(event.text.unicode);
					// transformation de la chaine en majuscule
					s = MinToMaj(s);
					s2 = MinToMaj(s2);
					// choix de la police à utiliser
					text.setFont(font); // font est un sf::Font

					// choix de la chaîne de caractères à afficher
					text.setString(s);
					// choix de la taille des caractères
					text.setCharacterSize(100); // exprimée en pixels, pas en points !

					// choix de la couleur du texte
					text.setFillColor(sf::Color::Magenta);

					text.setPosition(p1, p2);
					p1 = p1 + 116;
				}



			}
			if (event.key.code == sf::Keyboard::Enter)
			{
				p2 = p2 + 58;
				p1 = 25;
			}
			
		}
		window.draw(text);
		// Verification de la  premiere ligne
		if (s2.size()==6)
		{
			for (int i = 0; i < 6; i++)
			{

				if (s2[i] == s3[i])
				{
					drawright(window, p3 + i * 117, p4);
					text.setString(s2[i]);
					text.setPosition(p5 + i * 117, p6);
					drawgrid(window);
					window.draw(text);
				}
			}

		}
		window.display();
	}
}

void drawright(RenderWindow &window, int p2, int p3)
{
	RectangleShape carre(Vector2f(117, 117));
	carre.setFillColor(Color::Red);
	carre.setPosition(p2, p3);
	window.draw(carre);
}

void drawreplace(RenderWindow &window)
{
	CircleShape circle(50);
	circle.setPosition(10, 10);
	circle.setFillColor(Color::Yellow);
	window.draw(circle);
}

string MinToMaj(string s)
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
