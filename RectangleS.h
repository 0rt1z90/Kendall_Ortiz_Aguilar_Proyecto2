#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class RectangleS {
private:
	Texture button, button1, button2, button3, buttonText, buttonMenu;


public:
	RectangleS();
	RectangleShape rectangle(Vector2f);
	RectangleShape rectangleText(Vector2f);
	RectangleShape rectangleMenu(Vector2f);
	RectangleShape rectangle1(Vector2f);
	RectangleShape rectangle2(Vector2f);
	RectangleShape rectangle3(Vector2f);

}; 