#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Solution.h"
#include <string>
using namespace std;


void Solution::tirerAleatoirement()
{
	int max = 323578; // Nombre de lignes du fichier liste_finale.txt
	int indice_voulu = rand() % max; // Sélectionne un indice aléatoire qui sera la ligne du mot dans le dictionnaire
	int indice_actuel = 0; // Correspond à l'indice de la ligne du dictionnaire actuellement lue
	int i = 0;
	string mot_actuel; // Prend une par une les valeurs des mots du dictionnaire jusqu'à celui désiré
	ifstream file;
	file.open("liste_finale.txt"); // Ouvre le fichier en lecture dans file
	if (!file.is_open())
		cout << "Le fichier n existe pas " << endl; // Vérification que le fichier est bien ouvert
	else
	{
		while (getline(file, mot_actuel)) //lit 1 par 1 les lignes du fichier et met cette ligne dans mot actuel
		{
			if (indice_voulu < 323578)
			{
				indice_actuel++;
				if (indice_actuel == indice_voulu) // Si on tombe sur l'indice aléatoire voulu
				{
					if (mot_actuel.size() != 6) // On ne prend que les mots de 6 lettres
					{
						i = i + indice_voulu;
						if ((max - i) <= 0)
						{
							i = 0;
						}
						indice_voulu = rand() % (max - i); // Recherche un nouveau mot comme solution
						indice_actuel = 0; // On remet les valeurs à 0

					}
					else
					{
						setNom(mot_actuel); //notre Solution mot_final voit son champ nom_ (de type string) = ligne lue actuellement
					}
				}
			}
			else
				indice_voulu = 0;
		}
	}
}
