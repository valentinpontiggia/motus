#pragma once
#include <string>
#include "word.h"
using namespace std;


class Solution : public Word
{
public:
	Solution(const string &nom, const int &taille) : Word(nom, taille) {};
	void tirerAleatoirement();
};
