#pragma once
#include <string>
#include "word.h"
using namespace std;

class Essai : public Word
{
	bool existe_;
public:
	Essai(bool existe, const string &nom, const int &taille);
	bool getExistence() { return existe_; };
	void setExistence(bool valeur) { existe_ = valeur; };
	void operator=(Word &w);
	void Existence();
};
