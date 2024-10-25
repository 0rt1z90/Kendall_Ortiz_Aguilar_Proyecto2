#include "Windoww.h"
RectangleS button;
Textt text;
Circle c1;
Event event;

Windoww::Windoww(const string& imageFilePath) : window(sf::VideoMode(1200, 750), "SFML Window") {//Cargo la ventana
    window.setFramerateLimit(60);
    texture.loadFromFile(imageFilePath);
    sprite.setTexture(texture);
    scaleSprite();
    start.loadFromFile("HollowArchives/HollowMenu.jpg");
    Vector2u textureSize = start.getSize(); // Tamaño de la imagen
    Vector2u windowSize = window.getSize(); // Tamaño de la ventana

    // Calcular la escala para ajustar la imagen al tamaño de la ventana
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;


    startSprite.setTexture(start);
    startSprite.setScale(scaleX, scaleY);
   
}

void Windoww::run() {
    //Abrimos la ventana
    playMusic();
    processEventsS(window);//Ventana de start
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void Windoww::processEvents() {

    Vector2u textureSize = texture.getSize();
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));//Para obtner poss del mouse
    
    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) {
            window.close();
           }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 454 && mousePos.y <= 454 + 50) {//Saber si se encuentra encima del boton salir

                window.close();

            }

            if (mousePos.x <= 980 || (mousePos.x >= 980 && mousePos.y >= 500)) {//Saber si se encuentra encima del panel de emblemas
                Sprite newEmblem;
                newEmblem = c1.createCircle(mousePos, textureSize);
                circles.push_back(newEmblem);
            }
            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 50 && mousePos.y <= 50 + 50) {

               //Insercion
            }

            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 160 && mousePos.y <= 160 + 50) {

                cout << "Guardar" << endl;
            }
        }
    }
}

void Windoww::processEventsS(RenderWindow& window) {

    while (window.isOpen()) {
 
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
                return;  //Salir del bucle
            }
        }

        //Ventana de start
        window.clear();
        window.draw(startSprite);
        
        window.display();
    }
}

void Windoww::render() {

    //Draw's sobre la ventana
    window.clear();


    window.draw(sprite);
    window.draw(button.rectangle(Vector2f(997, 50)));
    window.draw(text.textShow("INSERCION", Vector2f(1025, 60)));
    window.draw(button.rectangle(Vector2f(997, 150)));
    window.draw(text.textShow("GUARDAR", Vector2f(1025, 160)));
    window.draw(button.rectangle(Vector2f(997, 250)));
    window.draw(text.textShow("EDITAR", Vector2f(1040, 260)));
    window.draw(button.rectangle(Vector2f(997, 454)));
    window.draw(text.textShow("SALIR", Vector2f(1060, 466)));
    window.draw(c1.charm());

    for (auto& emblem : circles) {
        window.draw(emblem);  //Dibujar cada emblema (sprite)
    }


    window.display();

}

void Windoww::scaleSprite() {
    Vector2u textureSize = texture.getSize();
    Vector2f textureSizeS = startSprite.getScale();

    //Mapa:
    float scaleX = static_cast<float>(window.getSize().x * 0.83) / textureSize.x; //83% del ancho de la ventana
    float scaleY = static_cast<float>(window.getSize().y) / textureSize.y; //Todo el alto de la ventana

    //Start
    float scaleXS = static_cast<float>(startSprite.getScale().x * 0.63) / textureSizeS.x; //63% del ancho de la ventana
    float scaleYS = static_cast<float>(startSprite.getScale().y * 0.80) / textureSizeS.y; // odo el alto de la ventana

    //Aplicar la escala al sprite
    sprite.setScale(scaleX, scaleY);//Mapa
    startSprite.setScale(scaleXS, scaleYS);//Start

    // Coordenada (0, 0) para que quede a la izquierda
    sprite.setPosition(0,0);  //Mapa
    startSprite.setPosition(0,0);//Start
}

void Windoww::playMusic() {

    //Archivos de msuica
    music.openFromFile("HollowArchives/HollowOST.ogg");
    music.setLoop(true);
    music.play();

}