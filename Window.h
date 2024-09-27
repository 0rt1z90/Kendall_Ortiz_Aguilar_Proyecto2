#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Windoww {
private:
    Texture texture;
    RenderWindow window;
    Sprite sprite;

public:

    Windoww(const string& imageFilePath);
    void run();
    void processEvents();
    void render();
    void scaleSprite();
};