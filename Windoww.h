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
    Texture start;
    RenderWindow window;
    Sprite sprite;
    Sprite startSprite;
    Music music;
    vector<Sprite> circles; // Almacena los círculos creados, lo dejare en vectores hasta que estudie nodos


public:

    Windoww(const string& imageFilePath);
    void run();
    void processEvents();
    void processEventsS(RenderWindow&);
    void render();
    void scaleSprite();
    void playMusic();
};