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


char& Word::operator[](int i)
{
	if (i < 0 || i >= nom_.size())
	{
		cerr << "Dépassement d'indice : i = " << i;
		abort();
	}
	return nom_[i];
}


void Word::afficher() const
{
	for (int i = 0; i < nom_.size(); i++)
	{
		cout << nom_[i];
	}
	cout << endl;
}


void Word::MinToMaj() // fonction qui fait conerti une chaine minuscule en majuscule
{
	for (int i = 0; nom_[i] != '\0'; i++)
	{
		if (nom_[i] >= 'a' && nom_[i] <= 'z')
		{
			nom_[i] = nom_[i] - 32;
		}
	}
}

