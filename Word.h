#pragma once
#include <string>
using namespace std;

class Word
{
	string nom_;
	int taille_;		
public:
	Word(string nom = "", int taille = 0);
	char& operator[](int i);
	void operator=( Word &w);
	void setNom(string valeur) { nom_ = valeur; };
	void reduire(int valeur);
	void setTaille(int valeur) { taille_ = valeur; };
	string getNom() { return nom_; };
	int getTaille() { return taille_; };
	void afficher() const;
	void MinToMaj();
};
