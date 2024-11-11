#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Textt {
private:
	Font font, fontText;
	Text newText;
public:

	Textt();
	Text textShow(string, Vector2f);
	Text textNodo(string, Vector2f);

};