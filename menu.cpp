#include "menu.h"
#include "historique.h"
#include "Application.h"
using namespace sf;


Menu::Menu(float hauteur, float largeur)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(45);
	menu[0].setString("MOTUS");
	menu[0].setPosition(Vector2f(270, 120));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("~ Jouer ~");
	menu[1].setPosition(Vector2f(290, 320));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("~ Historique ~");
	menu[2].setPosition(Vector2f(270, 450));

	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setString("~ Quitter ~");
	menu[3].setPosition(Vector2f(285, 580));

}


Menu::~Menu()
{
}

Text textPointed(RenderWindow& window, Text& text) //change la couleur du texte s'il est pointé
{
	if (text.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		text.setFillColor(Color::Red);
		text.setStyle(Text::Underlined);
	}
	else
	{
		text.setFillColor(Color::White);
		text.setStyle(Text::Regular);
	}
	return text;
}

void Menu::afficher(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::afficherMenu(Menu Menu)
{

	RenderWindow window(VideoMode(700, 700), "MOTUS");
	Historique historique(700, 700);

	while (window.isOpen())
	{
		Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					if (event.mouseButton.x >= 270 && event.mouseButton.x <= 500) { //si la souris clique sur un point d'abscisse l'une des options
						if (event.mouseButton.y >=330 && event.mouseButton.y <= 350) //insérer les fonctions qui lancent le jeu, pas oublier les include
						{
							window.close();
							RenderWindow window(sf::VideoMode(1100, 700), "MOTUS");
							Solution sol("", 0);
							sol.tirerAleatoirement();
							cout << sol.getNom();
							Application motus;
							motus.Affichage(window, sol, historique);
						}
						if (event.mouseButton.y >= 430 && event.mouseButton.y <= 470) //si la souris clique sur un point d'ordonnée de l'option historique
						{
							historique.afficherHistorique(historique, window);
						}
						if (event.mouseButton.y >= 560 && event.mouseButton.y <= 610)
						{
							window.close();
						}
					}
				}
			}
		}
		window.clear();
		menu[1] = textPointed(window, menu[1]);
		menu[2] = textPointed(window, menu[2]);
		menu[3] = textPointed(window, menu[3]);
		Menu.afficher(window);
		window.display();
	}
}
