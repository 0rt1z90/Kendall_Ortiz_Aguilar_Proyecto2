#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Nodo {
public:
	Vector2f possX, possY;
	Nodo* sigt;
	Nodo* ant;
	Sprite spri;
	Text text;
	string charm;
	Texture* t1;

	Nodo(Vector2f, Vector2f, Sprite, Text, string);
	//Nodo(const Sprite& spr, const Text& txt, const string& cham) : spri(spr), text(txt), charm(cham), sigt(nullptr), ant(nullptr) {}


	Nodo(Sprite, Text, Texture*);
	//Nodo(Sprite spr, Text txt, Texture* t2) : spri(spr), text(txt), t1(t2), sigt(nullptr), ant(nullptr) {}

	Nodo(Vector2f, Vector2f, Sprite);
	//Nodo(const Sprite& spr) : spri(spr), sigt(nullptr), ant(nullptr) {}

};

class List {
private:
	Nodo* head = nullptr;
	Nodo* end = nullptr;

public:
	void add(Vector2f, Vector2f, const Sprite&, const Text&, const string&);
	void deletear(RenderWindow&, const Vector2f&);


	~List() {
		while (head != nullptr) {
			Nodo* temp = head;
			head = head->sigt;
			delete temp;
		}
	}

	Nodo* getHead();
};