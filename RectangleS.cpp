#include "RectangleS.h"

RectangleS::RectangleS() {
    button.loadFromFile("HollowArchives/HollowStyle.jpg");
    buttonText.loadFromFile("HollowArchives/HollowWallp.jpg");
    button1.loadFromFile("HollowArchives/HollowStyle2.jpg");
    button2.loadFromFile("HollowArchives/HollowStyle4.jpg");
    button3.loadFromFile("HollowArchives/HollowStyle3.jpg");
}

RectangleShape RectangleS::rectangle(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60



    //Asignar la textura al boton
    rButton.setTexture(&button);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangle1(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60



    //Asignar la textura al boton
    rButton.setTexture(&button1);

    rButton.setPosition(position);  
    return rButton;
}

RectangleShape RectangleS::rectangle2(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60



    //Asignar la textura al boton
    rButton.setTexture(&button2);

    rButton.setPosition(position); 
    return rButton;
}

RectangleShape RectangleS::rectangle3(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60



    //Asignar la textura al boton
    rButton.setTexture(&button3);

    rButton.setPosition(position); 
    return rButton;
}

RectangleShape RectangleS::rectangleText(Vector2f position) {

    RectangleShape rButton(Vector2f(200, 60));  //Tamaño del boton 200x60



    //Asignar la textura al boton
    rButton.setTexture(&buttonText);

    rButton.setPosition(position); 
    return rButton;
}