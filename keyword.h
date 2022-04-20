#pragma once
#ifndef _COMBINAISON
#define _COMBINAISON


class Keyword
{
	int* tableau_;		// Pointeur pour le tableau dynamique
	int taille_;		// Taille du mot-clé.
public:
	Keyword(int taille = 6);
	Keyword(const Keyword &c);  // Constructeur de copie
	~Keyword();
	int & operator[](int i);
	void operator=(const Keyword &c);
	void saisir();
	void afficher() const;
	void tirerAleatoirement();
	void verifier(const Keyword &c, int &nbBonnePos, int &nbMauvaisePos) const;
};

#endif