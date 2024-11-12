#include "FIleGestures.h"

void FileGestures::save(Nodo* nodo, const string& archive) {
    ofstream arch(archive);  
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

bool FileGestures::procesarArchivo(const string& nombreArchivo, List& circles) {
    font.loadFromFile("HollowArchives/HollowFont5.ttf");

    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return false;  //Retornar false si no se puede abrir el archivo
    }

    float x, y;
    string texturaArchivo, nombreEmblema;
    Nodo* ultimoArchivo = nullptr;  //Ultimo nodo cargado del archivo
    Nodo* nodoUltimoMapa = circles.getEnd();  //Ultimo nodo del mapa antes de cargar el archivo

    while (archivo >> x >> y) {  //Lee x y y
        archivo >> texturaArchivo;   //Lee la  textura
        archivo >> nombreEmblema;    //Lee el nombre
        Vector2f pos(x, y);

        //Carga la textura
        Texture* textura = new Texture();
        if (!textura->loadFromFile(texturaArchivo)) {
            cerr << "Error al cargar la textura: " << texturaArchivo << endl;
            delete textura;
            continue;  //Si la textura no se puede cargar, continuar con el siguiente nodo
        }

        //Crear el sprite y el texto para el nuevo nodo
        Sprite nuevoEmblema;
        nuevoEmblema.setTexture(*textura);
        nuevoEmblema.setPosition(x - 30, y - 40);
        nuevoEmblema.scale(0.4f, 0.4f);

        Text nuevoTexto;
        nuevoTexto.setFont(font);
        nuevoTexto.setString(nombreEmblema);
        nuevoTexto.setPosition(x - 25, y - 65);

        //Crear el nodo
        Nodo* nuevoNodo = new Nodo(nuevoEmblema, nuevoTexto, textura);
        nuevoNodo->possX.x = x;
        nuevoNodo->possY.y = y;
        nuevoNodo->charm = texturaArchivo;

       //Conectar los nodos
        if (ultimoArchivo) {
            ultimoArchivo->sigt = nuevoNodo;
            nuevoNodo->ant = ultimoArchivo;
        }
        else {
           
            if (nodoUltimoMapa) {
                nodoUltimoMapa->sigt = nuevoNodo;
                nuevoNodo->ant = nodoUltimoMapa;
            }
        }

        ultimoArchivo = nuevoNodo;  //Actualizar el ultimo nodo cargado
    }

    //Nuevo end de circles
    if (ultimoArchivo) {
        circles.setEnd(ultimoArchivo);
    }

    archivo.close();
    cout << "Procesamiento del archivo completado y nodos conectados al mapa." << endl;
    return true;  //Si el archivo se proceso correctamente
}

void FileGestures::dibujarEmblemas(RenderWindow& ventana) {

    Nodo* actual = head;

    while (actual != nullptr) {
        //Dibuja el sprite
        ventana.draw(actual->spri);

        InterpolacionCubica::dibujarCurva(ventana, head);

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