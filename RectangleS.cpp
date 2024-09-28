#include "RectangleS.h"

RectangleS::RectangleS() {
    button.loadFromFile("HollowArchives/HollowStyle.jpg");
}

RectangleShape RectangleS::rectangle(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tama�o del bot�n: 200x60
   
   

    //Asignar la textura al bot�n
    rButton.setTexture(&button);

    rButton.setPosition(position);  // X=ancho de la ventana, Y=para la altura
    return rButton;
}