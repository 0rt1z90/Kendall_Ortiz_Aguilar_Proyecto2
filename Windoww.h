#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "RectangleS.h"
#include "Textt.h"
#include "Circle.h"
#include "FileGestures.h"
#include "Nodo.h"
#include "Inter.h"

using namespace std;
using namespace sf;

class Windoww {
private:
    bool mostrarEmblemas = false, delet = false, inGame = false, normal1 = false, normal2 = false, altMapMode = false, newAltMapMode = false, newMap = false;//Variables para las imagenes
    Texture texture, start, wallp, achievement;
    RenderWindow window;
    Sprite sprite, startSprite, newEmblem, newWallp, achievementSprite;
    Music music;
    List circles;
    RectangleS button;
    Textt text;
    Circle c1;
    Event event;
    FileGestures f1;
    Font font;
    Text displayedText, editText;
    string inputText, archiveFile, archiveText;


public:

    Windoww(const string& imageFilePath);
    void run();
    void processEvents();
    void processEventsS(RenderWindow&);
    void render();
    void scaleSprite();
    void playMusic();
    void scalarImagen();
    void imagen();

};