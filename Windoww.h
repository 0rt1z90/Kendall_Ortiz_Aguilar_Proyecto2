#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "RectangleS.h"
#include "Textt.h"
#include "Circle.h"
#include "FileGestures.h"
#include "Nodo.h"

using namespace std;
using namespace sf;

class Windoww {
private:
    bool mostrarEmblemas = false;
    Texture texture, start;
    RenderWindow window;
    Sprite sprite, startSprite, newEmblem;
    Music music;
    List circles;
    RectangleS button;
    Textt text;
    Circle c1;
    Event event;
    FileGestures f1;
  


public:

    Windoww(const string& imageFilePath);
    void run();
    void processEvents();
    void processEventsS(RenderWindow&);
    void render();
    void scaleSprite();
    void playMusic();
};