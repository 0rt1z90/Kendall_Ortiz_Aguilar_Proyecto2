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
        arch << actual->charm << endl;
        arch << actual->text.getString().toAnsiString() << endl;
        actual = actual->sigt;

    }
    arch.close();
    cout << "Lista guardada en " << archive << endl;
}

void FileGestures::procesarArchivo(const string& nombreArchivo) {
    font.loadFromFile("HollowArchives/HollowFont5.ttf");
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        delete[] texturas;
        return;
    }

    float x, y;
    string texturaArchivo, nombreEmblema;
    Nodo* ultimo = nullptr;

    while (archivo >> x >> y) { //Lee x y y 
        archivo >> texturaArchivo;  //Lee la ruta del archivo de textura
        archivo >> nombreEmblema;   //Lee el nombre del emblema
        Vector2f pos(x, y);

        // Cargar la textura para el sprite
        Texture* textura = new Texture(); // Crear una textura independiente
        if (!textura->loadFromFile(texturaArchivo)) {
            cerr << "Error al cargar la textura: " << texturaArchivo << endl;
            delete textura;
            continue;  //falla la carga, salta este nodo
        }

        Sprite nuevoEmblema;
        nuevoEmblema.setTexture(*textura);  //Asignar la textura cargada al sprite
        nuevoEmblema.setPosition(x - 30, y - 40);
        nuevoEmblema.scale(0.4f, 0.4f);

        //Crear un objeto Text
        Text nuevoTexto;
        nuevoTexto.setFont(font);
        nuevoTexto.setString(nombreEmblema);
        nuevoTexto.setPosition(x - 25, y - 65);

        //Creacion de nuevo nodo
        Nodo* nuevoNodo = new Nodo(nuevoEmblema, nuevoTexto, textura);
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
        //Dibuja el sprite
        ventana.draw(actual->spri);
        //Dibuja el texto
        ventana.draw(actual->text);



        actual = actual->sigt; //Avanza al siguiente nodo
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