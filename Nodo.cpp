#include "Nodo.h"

Nodo::Nodo(Vector2f x, Vector2f y, Sprite image, Text text, string cham) {
	this->possX = x;
	this->possY = y;
	this->spri = image;
	this->sigt = nullptr;
	this->ant = nullptr;
	this->text = text;
	this->charm = cham;

}

Nodo::Nodo(Sprite image, Text text, Texture* cham)
{
	this->spri = image;
	this->sigt = nullptr;
	this->ant = nullptr;
	this->text = text;
	this->t1 = cham;

}

Nodo::Nodo(Vector2f x, Vector2f y, Sprite image) {

	this->possX = x;
	this->possY = y;
	this->spri = image;
	this->sigt = nullptr;
	this->ant = nullptr;

}

void List::add(Vector2f x, Vector2f y, const Sprite& image, const Text& txt, const string& cham) {
	Nodo* nuevo = new Nodo(x, y, image, txt, cham);

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
		nuevo->ant = actual;
		nuevo = actual;
	}
}

void List::deletear(RenderWindow& ventana, const Vector2f& mousePos) {
	Nodo* actual = head;

	
	while (actual) {
		//Verificar si el mouse esta dentro de los limites del sprite
		if (actual->spri.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
			Nodo* nodoAEliminar = actual;

			//Si el nodo a eliminar es el primero
			if (nodoAEliminar == head) {
				head = nodoAEliminar->sigt;
				if (head) head->ant = nullptr;  
			}
			//Si el nodo a eliminar es el ultimo
			else if (nodoAEliminar == end) {
				end = nodoAEliminar->ant;
				if (end) end->sigt = nullptr;  
			}
			//Si el nodo a eliminar esta en el medio
			else {
				nodoAEliminar->ant->sigt = nodoAEliminar->sigt;
				nodoAEliminar->sigt->ant = nodoAEliminar->ant;
			}

			//Eliminar el nodo
			delete nodoAEliminar;
			return;  //Salir cuando se elimina nodo
		}

		actual = actual->sigt;  
	}

}

Nodo* List::getHead() {
	return head;
}