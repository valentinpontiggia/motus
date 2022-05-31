#pragma once
#include <iostream>
#include "Application.h"
#include "word.h"

using namespace std;
using namespace sf;



void Application :: Affichage(RenderWindow &window, Solution solution, Historique historique)
{
	Text Lettre, message_erreur, LettreUtil;
	Font font;
	font.loadFromFile("arial.ttf");
	Word lettre_rentre("");
	Essai essai(false, "");
	string s, mot_rentre;
	RectangleShape efface_lettre(Vector2f(116, 116));
	efface_lettre.setFillColor(Color::Black);
	int p1 = 20, p2 = 0, p3 = 2, p4 = -116, p5 = 0, p6 = -116, p7 = -116, p8 = -116, p9 = 25, tentative = 0;
	bool affiche_lettre = false, effacer = false, valider = false, erreur = false;
	int r = 0;
	solution.MinToMaj();
	while (window.isOpen())
	{
		// On dessine d'abord la grille de base
		drawgrid(window);
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
					// Transformation de la chaine récupérée en majuscules
					lettre_rentre.MinToMaj();

					// choix de la police à utiliser
					Lettre.setFont(font);

					// choix de la chaîne de caractères à afficher
					Lettre.setString(lettre_rentre.getNom());

					// choix de la taille des caractères
					Lettre.setCharacterSize(100); // exprimée en pixels, pas en points

					// choix de la couleur de la lettre
					Lettre.setFillColor(sf::Color::White);

					// choix de la position de la lettre
					Lettre.setPosition(p1, p2);

					// Si l'on rentre plus de 6 lettres sur le clavier
					if (mot_rentre.size() > 6)
					{
						affiche_lettre = true; // cette variable à vrai va permettre de ne pas afficher les variables rentrées en trop
						mot_rentre.resize(6); // on va alors couper le mot rentré et garder que les 6 premières lettres tapées
					}
					else
					{
						// si on a rentré moins que 6 lettres, la variable p1 va s'incrémenter. Elle correspond à la valeur de l'abscisse de l'écriture d'une lettre
						affiche_lettre = false;
						p1 = p1 + 116;
					}


				}


			}
			// Evenement si on appui sur la touche entrer
			if (event.key.code == sf::Keyboard::Enter)
			{
				essai.setExistence(false); 
				essai.setNom(mot_rentre); // on met la chaine de caractère rentré dans une variable de type word
				essai.Existence(); // on verifie d'abord si le mot rentré existe
				if (essai.getExistence())
				{
					// si le mot existe, on va incrémenter les différentes variables de positions des variable de type Text
					p2 = p2 + 59;
					p1 = 20;
					p4 = p4 + 59;
					p6 = p6 + 59;
					p7 = p7 + 59;
					p8 = p8 + 59;
					affiche_lettre = false;
					r = 0;
					tentative = tentative + 1; // on incrémente le nombre de tentatives
					valider = true;
					erreur = false;
					essai.MinToMaj();
				}
				else
				{
					// sinon, on met la variable erreur à vrai
					erreur = true;
				}
			}

			// Permet d'effacer un caractère rentré sur le clavier avec la touche backspace ou suppr
			if ((event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Delete) && mot_rentre.size() > 0)

			{
				p1 = p1 - 116;
				mot_rentre.resize(mot_rentre.size() - 1); // on resize le mot avec unne lettre en moins
				lettre_rentre.setNom("");
				efface_lettre.setPosition(p1, p2); // pour effacer la lettre sur la fenetre, on va placer un carré noir dessus. On définit ici ses coordonnées
				effacer = true;
				erreur = false;
			}
		}

		//fonction qui va permettre d'effacer sur la fenetre un caractère
		erase(window, effacer,efface_lettre, affiche_lettre, Lettre);

		// foncton qui va vérifier si le mot rentré correspond à la solution
		r = Verify(window, essai.getNom(), essai.getExistence(), LettreUtil, font, Lettre, solution.getNom(), p3, p4, p6, p7, p8, p9);

		// si on a appuyé sur la touche entrer, on va réinitialiser la chaine de caractère mot_rentre
		if (valider == true)
		{
			mot_rentre ="";
			valider = false;
		}


		// si le mot n'existe pas on affiche un message d'erreur
		if (erreur == true)
		{
			message_erreur.setFont(font);
			message_erreur.setCharacterSize(50);
			message_erreur.setString("Ce mot n'existe \n		pas");
			message_erreur.setFillColor(Color::Red);
			message_erreur.setPosition(720, 500);
			window.draw(message_erreur);
		}
		else // sinon on cache ce message d'erreur avec l'affichage d'un carré noir par dessus
		{
			RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(350, 120));
			rectangle.setFillColor(Color::Black);
			rectangle.setPosition(720, 500);
			window.draw(rectangle);
		}

		// cette fonction permet d'ouvrir une nouvelle fenetre lorsque l'on gagne ou l'on perd
		resultat(window, tentative, r, LettreUtil, font, solution.getNom());

		window.display();

	}
	// si on a atteint le nombre maximum de tentatives, on va inscrire cela dans l'historique avec le sigle "défaite"
	if (tentative == 12 || tentative == 0)
	{
		historique.ecrireHistorique(solution.getNom(), tentative / 2, false);
		Menu menu(700, 700);
		menu.afficherMenu(menu); //retour au menu
	}
	else // sinon on y inscrit notre nombre de tentatives pour gagner avec le sigle "victoire"
	{
		historique.ecrireHistorique(solution.getNom(), tentative / 2, true);
		Menu menu(700, 700);
		menu.afficherMenu(menu); //retour au menu
	}
}
