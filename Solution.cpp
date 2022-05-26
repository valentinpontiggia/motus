#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "time.h"
#include "Word.h"
#include "Essai.h"
#include "Solution.h"
#include <string>

using namespace std;

Solution Solution::tirerAleatoirement()
{
	srand(time(NULL));
	int max = 12;//323578
	int indice_voulu = 1 + rand() % max;
	int indice_actuel = 0;
	cout << "indice voulu : " << indice_voulu << endl;
	string mot_actuel;
	int taille;
	Solution mot_final;
	ifstream file;
	file.open("test.txt");
	if (!file.is_open())
		cout << "Le fichier n existe pas " << endl;
	else
		//while (file >> mot_actuel)
		while (getline(file, mot_actuel)) //lit 1 par 1 les lignes du fichier et met cette ligne dans mot actuel
		{
			indice_actuel++;
			if (indice_actuel == indice_voulu) //si on tombe sur l'indice aléatoire voulu
			{	
				mot_final.setNom(mot_actuel); //notre Solution mot_final voit son champ nom_ (de type string) = ligne lue actuellement
				taille = mot_actuel.size(); 
				mot_final.setTaille(taille); // Solution mot_final voit son champ taille_ = taille du mot lu actuellement
				cout << mot_final.getNom() << endl; //ici ça affiche bien le mot, c'est cette ligne qui fonctionne pas dans le main
				break;
			}
		}
	return mot_final;
}
