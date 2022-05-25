#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include"word.h"
using namespace std;
using namespace sf;

void drawgrid(RenderWindow &window);
void drawpoint(RenderWindow &window);
void drawword(RenderWindow &window, Word word, Word w2, int p1, int p2, Text text);
void drawright(RenderWindow &window, int p2, int p3);
void drawreplace(RenderWindow &window);
string MinToMaj(string s);
