#include "Windoww.h"

Windoww::Windoww(const string& imageFilePath) : window(sf::VideoMode(1200, 750), "SFML Window") {//Cargo la ventana
    window.setFramerateLimit(60);
    texture.loadFromFile(imageFilePath);
    sprite.setTexture(texture);
    scaleSprite();
    start.loadFromFile("HollowArchives/HollowMenu.jpg");
    f1.procesarArchivo("HollowList/List_N.txt");
    Vector2u textureSize = start.getSize(); //Tamaño de la imagen
    Vector2u windowSize = window.getSize(); //Tamaño de la ventana

    //Calcular la escala para ajustar la imagen al tamaño de la ventana
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;


    startSprite.setTexture(start);
    startSprite.setScale(scaleX, scaleY);

    //Cargar la fuente para el texto
    if (!font.loadFromFile("HollowArchives/HollowText2.ttf")) {
        
    }

    //Configurar el texto
    displayedText.setFont(font);
    displayedText.setCharacterSize(24);      //Tamaño de texto
    displayedText.setFillColor(Color::White);
    displayedText.setPosition(1000, 370);      //Posicion del texto en la ventana

}

void Windoww::run() {
    //Abrimos la ventana
    playMusic();
    processEventsS(window);
    while (window.isOpen()) {
        if (inGame) {
            processEvents();
            render();
        }
        else {
            
            processEventsS(window);
        }
    }

}

void Windoww::processEvents() {
    Vector2u textureSize = texture.getSize();
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window)); //Para obtener pos del mouse

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) {
            window.close();
        }

        //Captura el texto ingresado por el usuario
        if (event.type == Event::TextEntered) {
            if (event.text.unicode == '\b' && !inputText.empty()) {
                //Manejo de backspace
                inputText.pop_back();
            }
            else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                inputText += static_cast<char>(event.text.unicode); //Acumula caracteres
            }
            displayedText.setString(inputText);  //Actualizar texto mostrado
        }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {



            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 454 && mousePos.y <= 454 + 50) { //Saber si está sobre el boton salir

                inGame = false;
            }

            //Crear circulo solo si se ingreso texto en inputText
            if ((mousePos.x >= 980 && mousePos.y >= 500)) {
                newEmblem = c1.createCircle(mousePos, textureSize);
                archiveFile = c1.getEmblemsFiles(c1.indice2(mousePos));
            }
            else if (mousePos.x < 980 && !inputText.empty()) {
                newEmblem = c1.createCircle(mousePos, textureSize);

                circles.add(mousePos, mousePos, newEmblem, text.textNodo(inputText, mousePos), archiveFile);

                inputText.clear(); //Limpia el texto despues de crear el círculo
            }

            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 5 && mousePos.y <= 65) {
                mostrarEmblemas = true;

                normal1 = true;
                normal2 = false;
                
            }

            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 76 && mousePos.y <= 134) {
                f1.save(circles.getHead(), "HollowList/List_N.txt");
                normal3 = true;

            }

            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 145 && mousePos.y <= 205) {
                normal1 = false;
                normal2 = true;
                normal3 = false;
            }
            if (mostrarEmblemas) {
                circles.deletear(window, mousePos);  //Llamar al metodo para eliminar
            }
        }
    }
}

void Windoww::processEventsS(RenderWindow& window) {
    Event event;

    while (window.isOpen() && !inGame) {
        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window)); //Obtener posicion del mouse
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();

            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
                inGame = true; //Cambia al mapa
                return;
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if (mousePos.x > 541 && mousePos.x < 659 && mousePos.y > 434 && mousePos.y < 453) {
                    inGame = true; //Cambia al mapa
                    return;

                }
                if (mousePos.x > 544 && mousePos.x < 654 && mousePos.y > 613 && mousePos.y < 631) {
                    window.close();

                }
            }
        }

        //Dibujar la pantalla de inicio
        window.clear();
        window.draw(startSprite);
        window.display();
    }
}

void Windoww::render() {

    //Draw's sobre la ventana
    window.clear();


    window.draw(sprite);

    if (normal1 == false) {
        window.draw(button.rectangle(Vector2f(997, 5)));
        window.draw(text.textShow("EDITAR", Vector2f(1025, 20)));
    }
    else {
        window.draw(button.rectangle1(Vector2f(997, 5)));
        window.draw(text.textShow("EDITAR", Vector2f(1025, 20)));
    }


    if (normal2 == false) {
        window.draw(button.rectangle(Vector2f(997, 145)));
        window.draw(text.textShow("INSERTAR", Vector2f(1040, 160)));
    }
    else {
        window.draw(button.rectangle2(Vector2f(997, 145)));
        window.draw(text.textShow("INSERTAR", Vector2f(1040, 160)));
    }


    if (normal3 == false) {
        window.draw(button.rectangle(Vector2f(997, 75)));
        window.draw(text.textShow("GUARDAR", Vector2f(1025, 90)));
    }
    else {
        window.draw(button.rectangle3(Vector2f(997, 75)));
        window.draw(text.textShow("GUARDAR", Vector2f(1025, 90)));
    }




    window.draw(button.rectangle(Vector2f(997, 454)));
    window.draw(text.textShow("MENU", Vector2f(1060, 466)));

    window.draw(button.rectangleText(Vector2f(997, 350)));
    window.draw(text.textShow("NOMBRE:", Vector2f(997, 338)));

    if (mostrarEmblemas) {
        //f1.dibujarEmblemas(window);
    }
    window.draw(c1.charm());//Imagen

    InterpolacionCubica::dibujarCurva(window, circles.getHead());

    Nodo* actual = circles.getHead();
    while (actual != nullptr) {
        window.draw(actual->spri);
        window.draw(actual->text);
        actual = actual->sigt;
    }
    window.draw(displayedText);
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
    float scaleYS = static_cast<float>(startSprite.getScale().y * 0.80) / textureSizeS.y; //Todo el alto de la ventana

    //Aplicar la escala al sprite
    sprite.setScale(scaleX, scaleY);//Mapa
    startSprite.setScale(scaleXS, scaleYS);//Start

    // Coordenada (0,0) para que quede a la izquierda
    sprite.setPosition(0, 0);  //Mapa
    startSprite.setPosition(0, 0);//Start
}

void Windoww::playMusic() {

    //Archivos de msuica
    music.openFromFile("HollowArchives/HollowOST.ogg");
    music.setLoop(true);
    music.play();

}