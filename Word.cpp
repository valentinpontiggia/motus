#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Word.h"
#include <string>

using namespace std;

Word::Word(string nom, int taille)
{
	// Creation et initialisation du tableau dynamique 	
	string nom_ = nom;
	//for (int i = 0; i < taille; i++) nom_[i] = 0;
	taille_ = taille;
}

/*Word::Word(const Combinaison& c)
{
	// Initialisation des champs
	taille_ = c.taille_;

	// Creation et initialisation du tableau dynamique 	
	nom_ = new string [taille_];
	for (int i = 0; i < taille_; i++) tableau_[i] = c.tableau_[i];
}*/

Word::~Word()
{
	// Destruction du tableau dynamique
	delete[] &nom_;
}

char& Word::operator[](int i)
{
	if (i < 0 || i >= taille_)
	{
		cerr << "Dépassement d'indice : i = " << i;
		abort();
	}
	return nom_[i];
}

/*void Word::operator=(const Word& c)
{
		if (this != &c) {
			*nom = *(c.nom);
			*surname = *(c.surname);
		}
		return *this;
	}

	for (int i = 0; i < taille_; i++) nom_[i] = c.nom_[i];
}*/

/*void Keyword::saisir()
{
	cout << "Entrer une combinaison de " << taille_ << " chiffres"
		<< " entre 1 et " << nbCouleurs_ << endl
		<< "en separant les chiffres par des espaces :" << endl;

	// On pourrait aussi vérifier la validité des entrées
	for (int i = 0; i < taille_; i++) cin >> tableau_[i];
}*/

void Word::afficher() const
{
	for (int i = 0; i < taille_; i++) cout << nom_[i] << " ";
	cout << endl;
}

/*void Keyword::tirerAleatoirement()
{
	// Creation et initialisation du tableau des couleurs disponibles
	int* couleurs = new int[nbCouleurs_];
	for (int i = 0; i < nbCouleurs_; i++) couleurs[i] = i + 1;

	// Initialisation du générateur aléatoire
	srand(time(NULL));

	// Tirage aléatoire des couleurs
	int pMax = nbCouleurs_;	// Nombre de couleurs disponibles
	for (int i = 0; i < taille_; i++)
	{
		int p = rand() % pMax;
		tableau_[i] = couleurs[p];
		couleurs[p] = couleurs[pMax - 1];
		pMax--;
	}

	// Destruction du tableau des couleurs
	delete[] couleurs;
}*/

// Version valable uniquement si la combinaison à chercher et la proposition ne comportent pas de répétitions de couleurs
/*void Keyword::verifier(const Keyword& c, int& nbBonnePos, int& nbMauvaisePos) const
{
	nbBonnePos = 0;
	nbMauvaisePos = 0;
	for (int i = 0; i < taille_; i++)
		for (int j = 0; j < taille_; j++)
		{
			if (tableau_[i] == c.tableau_[j])
				if (i == j) nbBonnePos++;
				else nbMauvaisePos++;
		}
}*/

// Version qui fonctionne s'il y a des répétitions de couleurs dans la combinaison à chercher et/ou dans la proposition
/*void Combinaison::verifier(const Combinaison &c,int &nbBonnePos,int &nbMauvaisePos) const
{
// Création de deux copies des combinaisons pour ne pas modifier les originaux
Combinaison comb1(*this);
Combinaison comb2(c);
// Recherche des bien placés
nbBonnePos=0;
for(int i=0;i<taille_;i++)
{
if(comb2[i]==comb1[i])
{
nbBonnePos++;
comb2[i]=0;
comb1[i]=0;
}
}
// Recherche des mal placés
nbMauvaisePos=0;
for(int i=0;i<taille_;i++)
{
if(comb2[i]!=0)
{
for(int j=0;j<taille_;j++)
{
if (comb2[i]==comb1[j])
{
nbMauvaisePos++;
comb1[j]=0;
}
}
}
}
}*/
