#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class RectangleS {
private:
	Texture button;


public:
	RectangleS();
	RectangleShape rectangle(Vector2f);

};