#include "FIleGestures.h"

void FileGestures::save(Nodo* nodo, const string& archive) {
	ofstream arch(archive);  //Abrir en modo 
	if (!arch) {
		cout << "no" << endl;
	}

	Nodo* actual = nodo;

	while (actual != nullptr) {
		arch << actual->possX.x << endl;
		arch << actual->possY.y << endl;

		actual = actual->sigt;

	}
	arch.close();
	cout << "Lista guardada en " << archive << endl;
}

void FileGestures::cargar(List& list, const string& archivo) {
	int x = 0, y = 0;

	ifstream archivo1(archivo);
	if (!archivo1) {
		cerr << "No se pudo abrir el archivo para leer." << endl;
		return;
	}

	archivo1.close();
	cout << "Lista cargada desde " << archivo << endl;
}

void FileGestures::procesarArchivo(const string& nombreArchivo) {
	
	ifstream archivo(nombreArchivo);
	if (!archivo) {
		cerr << "No se pudo abrir el archivo." << endl;
		delete[] texturas;
		return;
	}



	float x, y;
	Nodo* ultimo = nullptr;

	//Leer coordenadas del archivo

	while (archivo >> x >> y) {

		Vector2f pos(x, y);
		Sprite nuevoEmblema;

		if (x > 997) {

			int indice1 = c12.indice2(pos);
			
			if (!texturas[numTexturas].loadFromFile(c12.getEmblemsFiles(indice1))) {
				cerr << "Error al cargar la textura para x > 997." << endl;

			}	continue;
		}
		nuevoEmblema.setTexture(texturas[numTexturas]);
		nuevoEmblema.scale(0.4f, 0.4f);
		numTexturas++;  //Aumentar el numero de texturas

		if (x < 997) {

			nuevoEmblema.setPosition(x, y);

		}
		else {
			continue;  //salta la creación del nodo
		}


		//Crear un nuevo nodo con el Sprite
		Nodo* nuevoNodo = new Nodo(nuevoEmblema);
		if (!head) {
			head = nuevoNodo;
			ultimo = head;
		}
		else {
			ultimo->sigt = nuevoNodo;
		}
		ultimo = nuevoNodo;
	}

	archivo.close();
	cout << "Procesamiento del archivo completado." << endl;

}

void FileGestures::dibujarEmblemas(RenderWindow& ventana) {
	Nodo* actual = head;
	while (actual) {
		ventana.draw(actual->spri);
		actual = actual->sigt;
	}
}

FileGestures::~FileGestures() {
	//Liberar memoria de la lista enlazada
	Nodo* actual = head;
	while (actual) {
		Nodo* temp = actual;
		actual = actual->sigt;
		delete temp;
	}
}