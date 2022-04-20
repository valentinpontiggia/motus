#include <iostream>
#include "combinaison.h"

using namespace std;

int main()
{
	// Déclaration d'une combinaison
	Combinaison c(4, 10);
	cout << "Combinaison c(4,10)" << endl;
	cout << "Taille de la combinaison : " << c.getTaille() << endl;
	cout << "Nombre de couleurs : " << c.getNbCouleurs() << endl;
	cout << "c : ";
	c.afficher();
	cout << endl;

	// Saisie des valeurs
	c.saisir();
	cout << "c : ";
	c.afficher();
	cout << endl;

	// Tirage aléatoire
	cout << "Tirage aléatoire" << endl;
	c.tirerAleatoirement();
	cout << "c : ";
	c.afficher();
	cout << endl;

	// Différentes façons de déclarer un objet combinaison et tirage aléatoire
	Combinaison c1;
	c1.tirerAleatoirement();
	cout << "Combinaison c1;" << endl;
	cout << "Taille de la combinaison : " << c1.getTaille() << endl;
	cout << "Nombre de couleurs : " << c1.getNbCouleurs() << endl;
	cout << "c1 : ";
	c1.afficher();
	cout << endl;

	Combinaison c2(5);
	c2.tirerAleatoirement();
	cout << "Combinaison c2(5);" << endl;
	cout << "Taille de la combinaison : " << c2.getTaille() << endl;
	cout << "Nombre de couleurs : " << c2.getNbCouleurs() << endl;
	cout << "c2 : ";
	c2.afficher();
	cout << endl;

	Combinaison c3(6, 6);
	c3.tirerAleatoirement();
	cout << "Combinaison c3(6,6);" << endl;
	cout << "Taille de la combinaison : " << c3.getTaille() << endl;
	cout << "Nombre de couleurs : " << c3.getNbCouleurs() << endl;
	cout << "c3 : ";
	c3.afficher();
	cout << endl;

	// Constructeur de copie
	Combinaison c4(c3);
	cout << "Combinaison c4(c3);" << endl;
	cout << "Taille de la combinaison : " << c4.getTaille() << endl;
	cout << "Nombre de couleurs : " << c4.getNbCouleurs() << endl;
	cout << "c4 : ";
	c4.afficher();
	cout << endl;

	// Operateur [] 
	Combinaison c5;
	for (int i = 0; i<c5.getTaille(); i++) c5[i] = i + 1;
	cout << "c5 : ";
	c5.afficher();

	// Opérateur d'affectation
	c5 = c4;
	cout << "c5=c4" << endl;
	cout << "c5 : ";
	c5.afficher();
	cout << endl;

	return 0;
}
