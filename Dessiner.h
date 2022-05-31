#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include"word.h"
#include "Application.h"
using namespace std;
using namespace sf;

class Dessiner
{

public:
	Dessiner() {};
	void drawletter(RenderWindow &window, Text text, Font font, char letter);
	void erase(RenderWindow &window, bool c, RectangleShape carre2, int h, Text text);
	void drawgrid(RenderWindow &window);
	void drawright(RenderWindow &window, int p2, int p3);
	void drawreplace(RenderWindow &window, int p2, int p3, char s, Text text, int p9, int p8, int k);
	void resultat(RenderWindow &window, int essai, int r, Text text2, Font font, string s4);
	int Verify(RenderWindow &window, string s2, bool b, Text text2, Font font, Text text, string s4, int p3, int p4, int p6, int p7, int p8, int p9);
};
