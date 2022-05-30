#include "menu.h"
#include "historique.h"
using namespace sf;


Menu::Menu(float hauteur,float largeur)
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
	FloatRect rectJouer = menu[1].getGlobalBounds();
	FloatRect rectHistorique = menu[2].getGlobalBounds();
	FloatRect rectQuitter = menu[3].getGlobalBounds();

	Historique historique(700, 700, 0);

	while (window.isOpen())
	{
		Vector2i intlocalPosition = Mouse::getPosition(window);
		Vector2f localPosition(intlocalPosition.x, intlocalPosition.y);
		Event event;
		window.clear();
	
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					if (event.mouseButton.x >= 270 && event.mouseButton.x <= 500) {
						//if (event.mouseButton.y >=310 && event.mouseButton.y <= 330)
						//{
						// 
						//	maingraphic();
						//}
						if (event.mouseButton.y >= 430 && event.mouseButton.y <= 470)
						{
							historique.ecrireHistorique(4);
							historique.afficherHistorique(historique, window);
						}
						if (event.mouseButton.y >= 560 && event.mouseButton.y <= 610)
						{
							window.close();
						}
					}
				}
			case Event::MouseMoved:
				if (rectJouer.contains(localPosition))
				{
					menu[1].setFillColor(Color::Red);
				}
				else if (rectHistorique.contains(localPosition))
					menu[2].setFillColor(Color::Red);
				else if (rectQuitter.contains(localPosition))
					menu[3].setFillColor(Color::Red);
				else
				{
					menu[1].setFillColor(Color::White);
					menu[2].setFillColor(Color::White);
					menu[3].setFillColor(Color::White);
				}
				break;
			}
		}
		window.clear();
		Menu.afficher(window);
		window.display();
	}
}
