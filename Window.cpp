#include "Window.h"
#include "Window.h"

Windoww::Windoww(const string& imageFilePath) : window(sf::VideoMode(1200, 750), "SFML Window") {
    if (!texture.loadFromFile(imageFilePath)) {
        throw std::runtime_error("Error al cargar la imagen");
    }

    sprite.setTexture(texture);
    scaleSprite();

}

void Windoww::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }

}

void Windoww::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

}

void Windoww::render() {

    window.clear();
    window.draw(sprite);
    window.display();
}

void Windoww::scaleSprite() {
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(window.getSize().x) / textureSize.x;
    float scaleY = static_cast<float>(window.getSize().y) / textureSize.y;
    sprite.setScale(scaleX, scaleY);
}