#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Solution.h"
#include <string>
using namespace std;


void Solution::tirerAleatoirement()
{
	int max = 323578;
	int indice_voulu = rand() % max;
	int indice_actuel = 0;
	int i = 0;
	//cout << "indice voulu : " << indice_voulu << endl;
	string mot_actuel;
	int taille;
	ifstream file;
	file.open("liste_finale.txt");
	if (!file.is_open())
		cout << "Le fichier n existe pas " << endl;
	else
	{
		while (getline(file, mot_actuel)) //lit 1 par 1 les lignes du fichier et met cette ligne dans mot actuel
		{
			if (indice_voulu < 323578)
			{
				indice_actuel++;
				if (indice_actuel == indice_voulu) //si on tombe sur l'indice aléatoire voulu
				{
					if (mot_actuel.size() != 6)
					{
						i = i + indice_voulu;
						if ((max - i) <= 0)
						{
							i = 0;
						}
						indice_voulu = rand() % (max - i);
						indice_actuel = 0;

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
