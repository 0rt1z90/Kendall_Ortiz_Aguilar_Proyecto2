#include "Inter.h"

float InterpolacionCubica::interpolarCubica(float p0, float p1, float p2, float p3, float t) {

    return 0.5f * ((2.0f * p1) + (-p0 + p2) * t +
        (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t * t +
        (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t * t * t);
}

void InterpolacionCubica::dibujarCurva(RenderWindow& window, Nodo* head) {

    if (!head || !head->sigt) return;

    Nodo* p0 = nullptr;
    Nodo* p1 = head;
    Nodo* p2 = head->sigt;
    Nodo* p3 = p2->sigt;

    //Vector para almacenar los vertices de la curva
    vector<Vertex> vertices;

    while (p2 != nullptr) {
        //Calcular y agregar puntos intermedios 
        for (float t = 0; t <= 1.0f; t += 0.05f) {
            float x, y;

            if (p3) {
                if (p0) {
                    x = interpolarCubica(p0->possX.x, p1->possX.x, p2->possX.x, p3->possX.x, t);
                    y = interpolarCubica(p0->possY.y, p1->possY.y, p2->possY.y, p3->possY.y, t);
                }
                else {
                    x = interpolarCubica(p1->possX.x, p1->possX.x, p2->possX.x, p3->possX.x, t);
                    y = interpolarCubica(p1->possY.y, p1->possY.y, p2->possY.y, p3->possY.y, t);
                }
            }
            else {
                if (p0) {
                    x = interpolarCubica(p0->possX.x, p1->possX.x, p2->possX.x, p2->possX.x, t);
                    y = interpolarCubica(p0->possY.y, p1->possY.y, p2->possY.y, p2->possY.y, t);
                }
                else {
                    x = interpolarCubica(p1->possX.x, p1->possX.x, p2->possX.x, p2->possX.x, t);
                    y = interpolarCubica(p1->possY.y, p1->possY.y, p2->possY.y, p2->possY.y, t);
                }
            }

            //Almacenar el punto calculado
            vertices.emplace_back(Vector2f(x, y), Color::White);
        }

        //Avanzar a los siguientes nodos
        p0 = p1;
        p1 = p2;
        p2 = p3;
        if (p3) p3 = p3->sigt;
    }

    //Dibujar la linea continua si hay vertices
    if (!vertices.empty()) {
        window.draw(&vertices[0], vertices.size(), PrimitiveType::LinesStrip);
    }
}