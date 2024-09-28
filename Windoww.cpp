#include "Windoww.h"
RectangleS button1, button2, button3;
Textt text1, text2, text3;
Circle c1;

Windoww::Windoww(const string& imageFilePath) : window(sf::VideoMode(1200, 750), "SFML Window") {//Cargo la ventana
    texture.loadFromFile(imageFilePath);
    sprite.setTexture(texture);
    scaleSprite();

}

void Windoww::run() {
    //Abrimos la ventana
    playMusic();
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void Windoww::processEvents() {
    Event event;
    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) {
            window.close();
        }
    }
}

void Windoww::render() {

    //Draw's sobre la ventana
    window.clear();
    window.draw(sprite);
    window.draw(button1.rectangle(Vector2f(995, 50)));
    window.draw(text1.textShow("INSERSION", Vector2f(1025, 60)));
    window.draw(button2.rectangle(Vector2f(995, 150)));
    window.draw(text2.textShow("GUARDAR", Vector2f(1025, 160)));
    window.draw(button3.rectangle(Vector2f(995, 250)));
    window.draw(text3.textShow("EDITAR", Vector2f(1040, 260)));
    window.draw(c1.colorr());
    window.display();

}

void Windoww::scaleSprite() {
    Vector2u textureSize = texture.getSize();

    
    float scaleX = static_cast<float>(window.getSize().x * 0.83) / textureSize.x; //83% del ancho de la ventana
    float scaleY = static_cast<float>(window.getSize().y) / textureSize.y; //Todo el alto de la ventana

    //Aplicar la escala al sprite
    sprite.setScale(scaleX, scaleY);

    
    sprite.setPosition(0, 0);  //Coordenada (0, 0) para que quede a la izquierda
}

void Windoww::playMusic() {
    //Archivos de msuica
    music.openFromFile("HollowArchives/HollowOST.ogg");
    music.setLoop(true);
    music.play();
}