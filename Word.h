#pragma once
#include <string>
using namespace std;

class Word
{
	string nom_;
	//int* tableau_;		// Pointeur pour le tableau dynamique
	int taille_;		// Taille du mot-clé.
public:
	Word(string nom = "",  int taille = 6);
	//Word(const Word& c);  // Constructeur de copie
	~Word();
	char& operator[](int i);
	//void operator=(const Word& c);
	//void saisir();
	void afficher() const;
	//void tirerAleatoirement();
	//void verifier(const Keyword& c, int& nbBonnePos, int& nbMauvaisePos) const;
};