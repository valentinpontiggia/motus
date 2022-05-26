#pragma once
#include <string>
#include "Word.h"
using namespace std;
// Contient la solution tirée aléatoirement
class Solution : public Word
{
	Word sol_;
public:
	Solution tirerAleatoirement();
};
