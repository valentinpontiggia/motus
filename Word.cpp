#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Word.h"
#include <string>

using namespace std;

Word::Word(string nom)
{
	nom_ = nom;
}


char& Word::operator[](int i) // Définition d'un opérateur [] pour accéder à une certaine lettre de notre Word.
{
	if (i < 0 || i >= nom_.size()) // L'indice doit être compris entre 0 et la taille du mot
	{
		cerr << "Dépassement d'indice : i = " << i;
		abort();
	}
	return nom_[i];
}


void Word::afficher() const // Affiche le mot
{
	for (int i = 0; i < nom_.size(); i++)
	{
		cout << nom_[i]; // Caractère par caractère. Cette méthode nous a beaucoup servi pour la vérification de la validité de nos programmes
	}
	cout << endl;
}


void Word::MinToMaj() // Fonction qui convertit une chaine minuscule en majuscule
{
	for (int i = 0; nom_[i] != '\0'; i++)
	{
		if (nom_[i] >= 'a' && nom_[i] <= 'z') // Si la lettre est bien une lettre de l'alphabet en minuscule
		{
			nom_[i] = nom_[i] - 32; // On la passe en majuscule (code ASCII)
		}
	}
}
