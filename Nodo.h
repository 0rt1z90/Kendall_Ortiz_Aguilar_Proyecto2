#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Nodo {
public:
	Vector2f possX, possY;
	Sprite image;
	Nodo* sigt;
	Nodo* ant;
	Sprite spri;

	Nodo(Vector2f, Vector2f, Sprite);
	Nodo(const Sprite& spr) : spri(spr), sigt(nullptr) {}

};

class List {
private:
	Nodo* head = nullptr;
	Nodo* end = nullptr;

public:
	void add(Vector2f, Vector2f, const Sprite&);

	void show();

	~List() {
		while (head != nullptr) {
			Nodo* temp = head;
			head = head->sigt;
			delete temp;
		}
	}

	void mostrarNodos(RenderWindow&, List&);

	Nodo* getHead();
};

