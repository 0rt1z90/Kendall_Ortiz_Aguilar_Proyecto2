#include "RectangleS.h"

RectangleS::RectangleS() {
    //Cargar los botones
    button.loadFromFile("HollowArchives/HollowStyle.jpg");
    buttonText.loadFromFile("HollowArchives/HollowWallp.jpg");
    buttonMenu.loadFromFile("HollowArchives/HollowStyle7.jpg");
    button1.loadFromFile("HollowArchives/HollowStyle2.jpg");
    button2.loadFromFile("HollowArchives/HollowStyle4.jpg");
    button3.loadFromFile("HollowArchives/HollowStyle3.jpg");
}

RectangleShape RectangleS::rectangle(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60

    
    rButton.setTexture(&button);//Asignar la textura al boton

    rButton.setPosition(position);  // X=ancho de la ventana, Y=para la altura
    return rButton;
}

RectangleShape RectangleS::rectangle1(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  

    rButton.setTexture(&button1);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangle2(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  

    rButton.setTexture(&button2);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangle3(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  

    rButton.setTexture(&button3);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangleText(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  
    rButton.setTexture(&buttonText);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangleMenu(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  

    rButton.setTexture(&buttonMenu);

    rButton.setPosition(position);  
    return rButton;
}