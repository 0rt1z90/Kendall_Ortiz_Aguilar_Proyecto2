#include "Nodo.h"

Nodo::Nodo(Vector2f x, Vector2f y, Sprite image) {
	this->possX = x;
	this->possY = y;
	this->image = image;
	this->sigt = nullptr;
	this->ant = nullptr;
}

void List::add(Vector2f x, Vector2f y, const Sprite& image) {
	Nodo* nuevo = new Nodo(x, y, image);
	
	if (head == nullptr) {
		head = nuevo;
		end = nuevo;
	}
	else {
		Nodo* actual = head;
		while (actual->sigt != nullptr) {

			actual = actual->sigt;
		}
		actual->sigt = nuevo;
	}
}

void List::show() {


}

void List::mostrarNodos(RenderWindow& ventana, List& lista) {
	Nodo* actual = lista.getHead();
	while (actual != nullptr) {
		

		actual = actual->sigt;
	}
}

Nodo* List::getHead() {
	return head;
}
