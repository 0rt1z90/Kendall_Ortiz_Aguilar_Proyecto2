#pragma once
#include <SFML/Graphics.hpp>
#include "Nodo.h"
#include <cmath>
#include <math.h>

using namespace sf;

class InterpolacionCubica {
public:
    static float interpolarCubica(float, float, float, float, float);
    static void dibujarCurva(RenderWindow&, Nodo*);

};