#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Circle {
private:
	CircleShape circle;
	Texture texture;

public:
	Circle();
	Sprite colorr();
};

