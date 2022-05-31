#pragma once
#include <iostream>
#include <fstream>
#include "Essai.h"
#include <string>
using namespace std;

Essai::Essai(bool existe, const string& nom) :Word(nom) // Constructeur de la classe Essai, hérite de la construction de la classe Word
{
	existe_ = existe;
}


void Essai::Existence()
{
	string mot_compare; 
	ifstream file;
	bool r = false;
	file.open("liste_finale.txt"); // Ouvre le fichier liste_finale.txt dans file
	if (!file.is_open())
	{
		cout << "Le fichier n existe pas " << endl; // Renvoie un message d'erreur si le fichier n'existe pas
		system("pause");
	}
	else
		while (file >> mot_compare) // Lit ligne par ligne le fichier et met la valeur de la lgien dans mot_compare
		{
			if (mot_compare == getNom()) // On compare le mot de la ligne au mot testé
				existe_ = true; // Si le mot testé est égal à une des lignes du fichier, il existe et on renvoie donc un true comme booléen
		}
}
