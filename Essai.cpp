#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Word.h"
#include "Essai.h"
#include "Solution.h"
#include <string>
//peut-être trop d'include mais on pourra supprimer le surplus plus tard
using namespace std;

void Essai::Colorier(Essai Mot)
{

}

void Essai ::Comparer(Essai name_, Solution mot_compare)
{
	vector <int> tab(name_.getNom().size());
	for (int i = 0; i < name_.getNom().size(); i++)
	{
		if (name_[i] == mot_compare[i])
			tab[i] = 2;
		if ((name_[i] != mot_compare[i]) && (mot_compare[i] == name_.getNom().find(mot_compare[i])))
			tab[i] = 1;
		else
			tab[i] = 0;
	}
}

void Essai::Existence(Essai Mot)
{
	int max = 323578;
	string mot_compare;
	ifstream file;
	file.open("test.txt");
	if (!file.is_open())
		cout << "Le fichier n existe pas " << endl;
	else
		while (getline(file, mot_compare)) //lit 1 par 1 les lignes du fichier et met cette ligne dans mot_compare
		{
			if (mot_compare == Mot.getNom()) //on compare le mot de la ligne au mot testé
			break;
		}
	cout << "Ce mot n existe pas !" << endl; //si aucun des mots du fichier n'est égal au mot testé alors le mot testé n'existe pas
}
