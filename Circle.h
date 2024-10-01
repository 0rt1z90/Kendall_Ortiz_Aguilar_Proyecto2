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
	Color colors;
	Sprite currentEmblem;  //Sprite que almacena el emblema seleccionado
	bool emblemSelected = false;  //Verificar si se ha seleccionado un emblema

public:
	Circle();
	Sprite charm();
	Sprite createCircle(Vector2f, Vector2u);
};

