#include "Windoww.h"
List lista;
FileGestures f1;
int main() {

    //Ventana con la imagen
    Windoww imagenDisplay("HollowArchives/Hollownest.jpeg");
    imagenDisplay.run();
    lista.~List();
    f1.~FileGestures();
    return 0;
}