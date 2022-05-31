#pragma once
#include <iostream>
#include "Application.h"
#include "word.h"

using namespace std;
using namespace sf;

Application::Application()
{

}


void Application::Affichage(RenderWindow& window, Solution solution)
{
	Dessiner graphic;
	Text Lettre, message_erreur, LettreUtil;
	Font font;
	font.loadFromFile("arial.ttf");
	Word lettre_rentre("", 0);
	Essai essai(false, "", 0);
	string s, mot_rentre;
	RectangleShape efface_lettre(Vector2f(116, 116));
	efface_lettre.setFillColor(Color::Black);
	int p1 = 20, p2 = 0, p3 = 2, p4 = -116, p5 = 0, p6 = -116, p7 = -116, p8 = -116, p9 = 25, tentative = 0, correct;
	bool affiche_lettre = false, effacer = false, valider = false, erreur = false;
	int r = 0;
	solution.MinToMaj();
	while (window.isOpen())
	{
		graphic.drawgrid(window);
		Event event;

		while (window.pollEvent(event))
		{
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			// Affichage d'un mot tapé sur le clavier
			if (event.type == sf::Event::TextEntered && event.key.code != sf::Keyboard::BackSpace)
			{

				if (event.text.unicode < 128)
				{
					effacer = false;
					// On récupère les données des touches du clavier
					s = static_cast<char>(event.text.unicode);
					lettre_rentre.setNom(s);
					mot_rentre += static_cast<char>(event.text.unicode);
					// transformation de la chaine en majuscule
					lettre_rentre.MinToMaj();
					// choix de la police à utiliser
					Lettre.setFont(font); // font est un sf::Font

					// choix de la chaîne de caractères à afficher
					Lettre.setString(lettre_rentre.getNom());
					// choix de la taille des caractères
					Lettre.setCharacterSize(100); // exprimée en pixels, pas en points !

					// choix de la couleur du texte
					Lettre.setFillColor(sf::Color::White);

					Lettre.setPosition(p1, p2);

					if (mot_rentre.size() > 6)
					{
						affiche_lettre = true;
						mot_rentre.resize(6);
					}
					else
					{
						affiche_lettre = false;
						p1 = p1 + 116;
					}


				}


			}
			// Evenement si on appui sur la touche entrer (ca pass a la ligne suivante et ca permet d'afficher les lettres bien ou mal placées)
			if (event.key.code == sf::Keyboard::Enter)
			{
				essai.setExistence(false);
				essai.setNom(mot_rentre);
				essai.Existence();
				if (essai.getExistence())
				{
					p2 = p2 + 59;
					p1 = 20;
					p4 = p4 + 59;
					p6 = p6 + 59;
					p7 = p7 + 59;
					p8 = p8 + 59;
					correct = 0;
					affiche_lettre = false;
					tentative = tentative + 1;
					valider = true;
					erreur = false;
					essai.MinToMaj();
				}
				else
				{
					erreur = true;
				}
			}

			// Permet d'effacer un caractère rentré sur le clavier avec la touche backspace ou suppr
			if ((event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Delete) && mot_rentre.size() > 0)

			{
				p1 = p1 - 116;
				mot_rentre.resize(mot_rentre.size() - 1);
				lettre_rentre.setNom("");
				efface_lettre.setPosition(p1, p2);
				effacer = true;
				erreur = false;
			}
		}

		graphic.erase(window, effacer, efface_lettre, affiche_lettre, Lettre);

		r = graphic.Verify(window, essai.getNom(), essai.getExistence(), LettreUtil, font, Lettre, solution.getNom(), p3, p4, p6, p7, p8, p9);


		if (valider == true)
		{
			mot_rentre = "";
			valider = false;
		}



		if (erreur == true)
		{
			message_erreur.setFont(font);
			message_erreur.setCharacterSize(50);
			message_erreur.setString("Ce mot n'existe \n		pas");
			message_erreur.setFillColor(Color::Red);
			message_erreur.setPosition(720, 500);
			window.draw(message_erreur);
		}
		else
		{
			RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(350, 120));
			rectangle.setFillColor(Color::Black);
			rectangle.setPosition(720, 500);
			window.draw(rectangle);
		}


		graphic.resultat(window, tentative, r, LettreUtil, font, solution.getNom());

		window.display();

	}
}
