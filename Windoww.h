#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "RectangleS.h"
#include "Textt.h"
#include "Circle.h"
using namespace std;
using namespace sf;

class Windoww {
private:
    Texture texture;
    RenderWindow window;
    Sprite sprite;
    Music music;


public:

    Windoww(const string& imageFilePath);
    void run();
    void processEvents();
    void render();
    void scaleSprite();
    void playMusic();
};