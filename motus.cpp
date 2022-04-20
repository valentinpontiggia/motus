#include <iostream>
#include "keyword.h"

using namespace std;

int main()
{
	int p;
	cout << "Entrer le nombre de pions différents entre 4 et 8 : ";
	cin >> p;
	Combinaison ordi(4, p);
	ordi.tirerAleatoirement();
	cout << "Ordinateur : ";
	ordi.afficher();
	cout << endl;

	int coup = 0;
	int nbBonnePos = 0, nbMauvaisePos;
	while (coup<10 && nbBonnePos<4)
	{
		Combinaison joueur(4, p);
		joueur.saisir();
		ordi.verifier(joueur, nbBonnePos, nbMauvaisePos);
		cout << "  Coup " << coup + 1 << " : " << nbBonnePos << " bien placés, " << nbMauvaisePos
			<< " mal placés" << endl << endl;
		coup++;
	}
	if (nbBonnePos == 4) cout << "Gagné en " << coup << " coups" << endl;
	return 0;
}
