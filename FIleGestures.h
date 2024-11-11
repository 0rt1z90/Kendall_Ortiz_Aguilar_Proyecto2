#pragma once
#include <iostream>
#include "Circle.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Nodo.h"
#include "Inter.h"

using namespace sf;
using namespace std;

class FileGestures {
private:
	Nodo* head = nullptr;
	Texture tex;
	Texture* texturas;
	Circle c12;
	Sprite newEmblemm;
	int numTexturas, indice1;
	Font font;


public:
	static void save(Nodo*, const string&);

	void procesarArchivo(const string&);

	~FileGestures();

	void dibujarEmblemas(RenderWindow&);

	FileGestures() : numTexturas(0) {
		texturas = new Texture[100];  //Tamaño maximo de 100 texturas
		indice1 = 0;
	}
};