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
        end = actual;
    }
}

void List::deletear(RenderWindow& ventana, const Vector2f& mousePos) {
    Nodo* actual = head;

    //Lista vacia
    if (!head) {
        cerr << "La lista está vacía, no se puede eliminar." << endl;
        return;
    }


    while (actual) {
        //Limites del sprite
        if (actual->spri.getGlobalBounds().contains(mousePos)) {


            //Si a borrar es primero
            if (actual == head) {
                head = actual->sigt;
                if (head) {
                    head->ant = nullptr;
                }
                if (!head) {
                    end = nullptr; //La lista queda vacia
                }
            }
            //Si a borrar es ultimo
            else if (actual == end) {
                end = actual->ant;
                if (end) {
                    end->sigt = nullptr;
                }
                else {
                    head = nullptr; //La lista esta vacia
                }
            }
            //Si el nodo a eliminar en el centro
            else {
                if (actual->ant) {
                    actual->ant->sigt = actual->sigt;
                }
                if (actual->sigt) {
                    actual->sigt->ant = actual->ant;
                }
            }


            delete actual;  //Liberamos la memoria

            return;  //Salir de la funcion
        }

        actual = actual->sigt;  // Avanzar al siguiente nodo
    }
}

Nodo* List::getHead() {
    return head;
}

Nodo* List::getEnd() {
    return end;
}

void List::setEnd(Nodo* n) {
    end = n;
}