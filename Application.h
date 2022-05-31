#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include"word.h"
#include "Dessiner.h"
#include"Solution.h"
#include"Essai.h"
#include"historique.h"
using namespace std;
using namespace sf;

class Application
{
public:
	Application();
	void Affichage(RenderWindow &window, Solution sol, Historique historique);
};
