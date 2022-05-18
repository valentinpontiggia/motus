#pragma once
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Word.h"
#include "Essai.h"
#include "Solution.h"
#include <string>

using namespace std;

void Essai::Colorier(Essai Mot)
{

}

void Essai ::Comparer(Essai name_, Solution mot_compare)
{
	int tab[name_.size()];
	for (int i = 0, i < name_.size(), i++)
	{
		if (name_[i] == mot_compare[i])
			tab[i] = 2;
		if ((name_[i] != mot_compare[i]) && (mot_compare[i] == name_.find(mot_compare[i])))
			tab[i] = 1;
		else
			tab[i] = 0;
	}
}