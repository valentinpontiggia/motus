#pragma once
#include <iostream>
#include <fstream>
#include "Essai.h"
#include <string>

using namespace std;

Essai::Essai(bool existe, const string& nom, const int& taille) :Word(nom, taille)
{
	existe_ = existe;
}


void Essai::Existence()
{
	string mot_compare;
	ifstream file;
	bool r = false;
	file.open("liste_finale.txt");
	if (!file.is_open())
	{
		cout << "Le fichier n existe pas " << endl;
		system("pause");
	}
	else
		while (file >> mot_compare)
		{
			if (mot_compare == getNom()) //on compare le mot de la ligne au mot testé
				existe_ = true;
		}
}
