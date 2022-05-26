#pragma once
#include <string>
#include "Word.h"
#include "Solution.h"
using namespace std;
// Contient les mots à tester par le joueur
class Essai : public Word
{
	Word test_;
public :
	void Colorier(Essai mot_compare);
	void Comparer(Essai mot_compare, Solution solution);
	void Existence(Essai Mot);
};
