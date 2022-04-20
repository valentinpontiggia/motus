#include <iostream>
#include <cstdlib>
#include <ctime>
#include "keyword.h"

using namespace std;

Keyword::Keyword(int taille)
{
	// V�rification de la validit� des param�tres
	if (taille<0) taille = 0;

	// Creation et initialisation du tableau dynamique 	
	tableau_ = new int[taille];
	for (int i = 0; i<taille; i++) tableau_[i] = 0;

	// Initialisation des champs
	taille_ = taille;
	nbCouleurs_ = nbCouleurs;
}

Keyword::Keyword(const Combinaison &c)
{
	// Initialisation des champs
	taille_ = c.taille_;
	nbCouleurs_ = c.nbCouleurs_;

	// Creation et initialisation du tableau dynamique 	
	tableau_ = new int[taille_];
	for (int i = 0; i<taille_; i++) tableau_[i] = c.tableau_[i];
}

Keyword::~Keyword()
{
	// Destruction du tableau dynamique
	delete[] tableau_;
}

int & Keyword::operator[](int i)
{
	if (i<0 || i >= taille_)
	{
		cerr << "D�passement d'indice : i = " << i;
		abort();
	}
	return tableau_[i];
}

void Keyword::operator=(const Keyword &c)
{

	if (taille_ != c.taille_)
	{
		delete[] tableau_;
		tableau_ = new int[c.taille_];
		taille_ = c.taille_;
	}

	for (int i = 0; i<taille_; i++) tableau_[i] = c.tableau_[i];
}

void Keyword::saisir()
{
	cout << "Entrer une combinaison de " << taille_ << " chiffres"
		<< " entre 1 et " << nbCouleurs_ << endl
		<< "en separant les chiffres par des espaces :" << endl;

	// On pourrait aussi v�rifier la validit� des entr�es
	for (int i = 0; i<taille_; i++) cin >> tableau_[i];
}

void Keyword::afficher() const
{
	for (int i = 0; i<taille_; i++) cout << tableau_[i] << " ";
	cout << endl;
}

void Keyword::tirerAleatoirement()
{
	// Creation et initialisation du tableau des couleurs disponibles
	int *couleurs = new int[nbCouleurs_];
	for (int i = 0; i<nbCouleurs_; i++) couleurs[i] = i + 1;

	// Initialisation du g�n�rateur al�atoire
	srand(time(NULL));

	// Tirage al�atoire des couleurs
	int pMax = nbCouleurs_;	// Nombre de couleurs disponibles
	for (int i = 0; i<taille_; i++)
	{
		int p = rand() % pMax;
		tableau_[i] = couleurs[p];
		couleurs[p] = couleurs[pMax - 1];
		pMax--;
	}

	// Destruction du tableau des couleurs
	delete[] couleurs;
}

// Version valable uniquement si la combinaison � chercher et la proposition ne comportent pas de r�p�titions de couleurs
void Keyword::verifier(const Keyword &c, int &nbBonnePos, int &nbMauvaisePos) const
{
	nbBonnePos = 0;
	nbMauvaisePos = 0;
	for (int i = 0; i<taille_; i++)
		for (int j = 0; j<taille_; j++)
		{
			if (tableau_[i] == c.tableau_[j])
				if (i == j) nbBonnePos++;
				else nbMauvaisePos++;
		}
}

// Version qui fonctionne s'il y a des r�p�titions de couleurs dans la combinaison � chercher et/ou dans la proposition
/*void Combinaison::verifier(const Combinaison &c,int &nbBonnePos,int &nbMauvaisePos) const
{

// Cr�ation de deux copies des combinaisons pour ne pas modifier les originaux
Combinaison comb1(*this);
Combinaison comb2(c);

// Recherche des bien plac�s
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

// Recherche des mal plac�s
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



