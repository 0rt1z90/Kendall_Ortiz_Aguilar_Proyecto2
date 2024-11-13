#include "Windoww.h"

const int NUM_IMAGENS = 16; //Vector de sprites
Texture images[NUM_IMAGENS];
size_t index = 0;

Windoww::Windoww(const string& imageFilePath) : window(sf::VideoMode(1200, 750), "SFML Window") {//Cargo la ventana

    window.setFramerateLimit(60);
    texture.loadFromFile(imageFilePath);
    sprite.setTexture(texture);
    scaleSprite();

    //Cargo el vector
    images[0].loadFromFile("HollowExtras/HollowImage.jpg");
    images[1].loadFromFile("HollowExtras/HollowImage1.jpg");
    images[2].loadFromFile("HollowExtras/HollowImage2.jpg");
    images[3].loadFromFile("HollowExtras/HollowImage3.jpg");
    images[4].loadFromFile("HollowExtras/HollowImage4.jpg");
    images[5].loadFromFile("HollowExtras/HollowImage5.jpg");
    images[6].loadFromFile("HollowExtras/HollowImage6.jpg");
    images[7].loadFromFile("HollowExtras/HollowImage7.jpg");
    images[8].loadFromFile("HollowExtras/HollowImage8.jpg");
    images[9].loadFromFile("HollowExtras/HollowImage9.jpg");
    images[10].loadFromFile("HollowExtras/HollowImage10.jpg");
    images[11].loadFromFile("HollowExtras/HollowImage11.jpg");
    images[12].loadFromFile("HollowExtras/HollowImage12.jpg");
    images[13].loadFromFile("HollowExtras/HollowImage13.jpg");
    images[14].loadFromFile("HollowExtras/HollowImage14.jpg");
    images[15].loadFromFile("HollowExtras/HollowImage15.jpg");


    //Establecer la primera textura al sprite
    newWallp.setTexture(images[index]);
    scalarImagen();

    start.loadFromFile("HollowArchives/HollowMenu.jpg");
    
    Vector2u textureSize = start.getSize(); //Tamaño de la imagen
    Vector2u windowSize = window.getSize(); //Tamaño de la ventana

    //Calcular la escala para ajustar la imagen al tamaño de la ventana
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    startSprite.setTexture(start);
    startSprite.setScale(scaleX, scaleY);


    achievement.loadFromFile("HollowArchives/HollowAchie.jpeg");
    achievementSprite.setTexture(achievement);

    Vector2u textureSizeAchien = achievement.getSize(); //Tamaño de la imagen
    Vector2u windowSizeAchien = window.getSize(); //Tamaño de la ventana

    //Calcular la escala para ajustar la imagen al tamaño de la ventana
    float scaleXAchien = static_cast<float>(windowSizeAchien.x) / textureSizeAchien.x;
    float scaleYAchien = static_cast<float>(windowSizeAchien.y) / textureSizeAchien.y;
    achievementSprite.setTexture(achievement);
    achievementSprite.setScale(scaleXAchien, scaleYAchien);

    //Cargar la fuente para el texto
    if (!font.loadFromFile("HollowArchives/HollowText2.ttf")) {
        
    }

    //Configurar el texto
    displayedText.setFont(font);
    displayedText.setCharacterSize(24);      //Tamaño de texto
    displayedText.setFillColor(Color::White);
    displayedText.setPosition(1000, 370);      //Posicion del texto en la ventana

    editText.setFont(font);
    editText.setCharacterSize(24);      //Tamaño de texto
    editText.setFillColor(Color::White);
    editText.setPosition(1000, 370);      //Posicion del texto en la ventana
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
            //Regresar al menu
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
       
        if (!altMapMode) { //Captura el texto ingresado por el usuario
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
        }
        else {
            if (event.type == Event::TextEntered) {
                
                if (event.text.unicode == '\b' && !archiveText.empty()) {
                    archiveText.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                    archiveText += static_cast<char>(event.text.unicode);
                }
                editText.setString(archiveText);
            }
        }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {


            if (mousePos.x >= 997 && mousePos.x < 1200 &&
                mousePos.y >= 454 && mousePos.y <= 454 + 50) { //Saber si esta sobre el boton salir

                inGame = false;
            }

            if (newAltMapMode == true) {
                if (mousePos.x >= 997 && mousePos.x < 1200 && mousePos.y >= 5 && mousePos.y < 80) {
                    imagen();//Cambiar de imagen
                }
            }
            else {

                if (!altMapMode) {

                    //Crear circulo solo si se ingreso texto 
                    if ((mousePos.x >= 980 && mousePos.y >= 500)) {
                        newEmblem = c1.createCircle(mousePos, textureSize);
                        archiveFile = c1.getEmblemsFiles(c1.indice2(mousePos));
                    }
                    else if (mousePos.x < 980 && !inputText.empty()) {
                        newEmblem = c1.createCircle(mousePos, textureSize);

                        circles.add(mousePos, mousePos, newEmblem, text.textNodo(inputText, mousePos), archiveFile);

                        inputText.clear(); //Limpia el texto despues de crear el circulo
                    }

                    if (mousePos.x >= 997 && mousePos.x < 1200 &&
                        mousePos.y >= 5 && mousePos.y <= 65) {
                        delet = true;

                        normal1 = true;
                        normal2 = false;

                    }

                    if (mousePos.x >= 997 && mousePos.x < 1200 &&
                        mousePos.y >= 76 && mousePos.y <= 134) {
                        delet = false;
                        normal1 = false;
                        normal2 = true;
                    }
                    if (delet) {
                        circles.deletear(window, mousePos);  //Llamar al metodo eliminarEmblema
                    }

                }
                else {

                    //Condicion para cargar el archivo
                    if (mousePos.x >= 997 && mousePos.x < 1200 && mousePos.y >= 5 && mousePos.y <= 65) {

                        if (archiveText.empty()) {
                            //Mostrar un mensaje si el texto esta vacio
                            cout << "Por favor ingresa un nombre de archivo." << endl;
                            return;  //No continuar si el texto esta vacio
                        }

                        if (!archiveText.empty()) {  

                            //Modificar el nombre del archivo antes de pasarlo
                            string nombreArchivo = "HollowList/" + archiveText;

                            //Añadir ".txt" si el nombre no termina en ello
                            if (nombreArchivo.substr(nombreArchivo.length() - 4) != ".txt") {
                                nombreArchivo += ".txt";
                            }
                            cout << nombreArchivo << endl;
                           
                            bool arc = f1.procesarArchivo(nombreArchivo, circles);

                            if (!arc) {

                            }
                            else {
                                mostrarEmblemas = true;  //Mostrar los emblemas despues de cargar el archivo
                            }

                            archiveText.clear(); //Limpia el texto despues de crear el circulo
                        }

                    }

                    if (mousePos.x >= 997 && mousePos.x < 1200 &&
                        mousePos.y >= 76 && mousePos.y <= 134) {

                        if (archiveText.empty()) {
                          
                            cout << "Por favor ingresa un nombre de archivo." << endl;
                            return;  //No continuar si el texto esta vacio
                        }

                        if (!archiveText.empty()) { 

                            //Modificar el nombre del archivo antes de pasarlo
                            string nombreArchivo = "HollowList/" + archiveText;
                            //Añadir ".txt" si el nombre no termina en ello
                            if (nombreArchivo.substr(nombreArchivo.length() - 4) != ".txt") {
                                nombreArchivo += ".txt";
                            }
                            cout << nombreArchivo << endl;
                            
                            f1.save(circles.getHead(), nombreArchivo);

                            archiveText.clear(); 
                        }
                    }
                }
            }
        }
    }
}

void Windoww::processEventsS(RenderWindow& window) {
    Event event;

    while (window.isOpen() && !inGame) {

        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window)); //Obtener posicion del mouse
        while (window.pollEvent(event)) {

            altMapMode = false;  //Cambiar a la edicion
            newAltMapMode = false;//Cambiar al vector de imagenes
            newMap = false;//Imagen de logros

            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if (mousePos.x > 541 && mousePos.x < 659 && mousePos.y > 434 && mousePos.y < 453) {
                    inGame = true;
                    return;

                }
                if (mousePos.x > 556 && mousePos.x < 644 && mousePos.y > 482 && mousePos.y < 497) {
                    inGame = true;
                    altMapMode = true;  //Cambiar al mapa alternativo
                    return;
                }
                if (mousePos.x > 567 && mousePos.x < 633 && mousePos.y > 572 && mousePos.y < 585) {
                    inGame = true;
                    newAltMapMode = true;//Cambiar el vector
                }
                if (mousePos.x > 527 && mousePos.x < 672 && mousePos.y > 525 && mousePos.y < 542) {
                    inGame = true;
                    newMap = true;//Cambiar al logro
                }
                if (mousePos.x > 544 && mousePos.x < 654 && mousePos.y > 613 && mousePos.y < 631) {  //Zona adicional para salir
                    window.close();
                }

            }
        }
        //Dibujar la pantalla de inicio
        Text t2;
        t2.setFont(font);
        t2.setCharacterSize(24);      //Tamaño de texto
        t2.setFillColor(Color::White);
        
        
        window.clear();
        window.draw(startSprite);

        t2.setPosition(20, 100);      //Posicion del texto en la ventana
        t2.setString("Se le recomienda ir primero");
        window.draw(t2);
        t2.setPosition(20, 130);      //Posicion del texto en la ventana
        t2.setString("a la seccion de");
        window.draw(t2);
        t2.setPosition(20, 160);      //Posicion del texto en la ventana
        t2.setString("Achievements");
        window.draw(t2);

        window.display();
    }
}

void Windoww::render() {

    //Draw's sobre la ventana
    window.clear();


    window.draw(sprite);

    if (newMap == true) {
        Text t1;
        window.draw(achievementSprite);
       
        t1.setFont(font);
        t1.setCharacterSize(24);      //Tamaño de texto
        t1.setFillColor(Color::White);
        t1.setPosition(32, 380);      //Posicion del texto en la ventana
        t1.setString("Creador del programa: Kendall Ortiz Aguilar");
        window.draw(t1);
        t1.setPosition(32, 410);
        t1.setString("Mayor logro: Platinar Hollow Knight");
        window.draw(t1);
        t1.setPosition(32, 440);
        t1.setString("Estudiante de ING en sistemas");
        window.draw(t1);
        t1.setPosition(500, 100);
        t1.setString("Se le recuerda al usuario que no puede insertar una lista");
        window.draw(t1);
        t1.setPosition(500, 120);
        t1.setString("sin haber puesto minimo un punto");
        window.draw(t1);
    }

    if (newAltMapMode == true) {
        window.draw(newWallp);
        window.draw(button.rectangleCam(Vector2f(997, 5)));
        window.draw(text.textShow("CAMBIAR", Vector2f(1000, 15)));
       
    }

    if (altMapMode == true) {

        window.draw(button.rectangleText(Vector2f(997, 350)));
        window.draw(text.textShow("NOMBRE:", Vector2f(997, 338)));

        window.draw(button.rectangle3(Vector2f(997, 4)));
        window.draw(text.textShow("INSERTAR", Vector2f(1025, 20)));

        window.draw(button.rectangle3(Vector2f(997, 75)));
        window.draw(text.textShow("GUARDAR", Vector2f(1025, 90)));

        window.draw(c1.charm());//Imagen
        if (mostrarEmblemas) {
            f1.dibujarEmblemas(window);
        }
        InterpolacionCubica::dibujarCurva(window, circles.getHead());

        Nodo* actual = circles.getHead();

        while (actual != nullptr) {
            window.draw(actual->spri);
            window.draw(actual->text);
            actual = actual->sigt;
        }
        window.draw(editText);

    }

    if (altMapMode == false && newAltMapMode == false && newMap == false) {
        if (normal1 == false) {
            window.draw(button.rectangle(Vector2f(997, 5)));
            window.draw(text.textShow("BORRAR", Vector2f(1025, 20)));
        }
        else {
            window.draw(button.rectangle1(Vector2f(997, 5)));
            window.draw(text.textShow("EDICION", Vector2f(1025, 20)));
        }

        if (normal2 == false) {
            window.draw(button.rectangle(Vector2f(997, 75)));
            window.draw(text.textShow("AGREGAR", Vector2f(1025, 90)));
        }
        else {
            window.draw(button.rectangle2(Vector2f(997, 75)));
            window.draw(text.textShow("EDICION", Vector2f(1025, 90)));
        }

        window.draw(button.rectangleText(Vector2f(997, 350)));
        window.draw(text.textShow("NOMBRE:", Vector2f(997, 338)));

        window.draw(c1.charm());//Imagen
        if (mostrarEmblemas) {
            f1.dibujarEmblemas(window);
        }
        InterpolacionCubica::dibujarCurva(window, circles.getHead());

        Nodo* actual = circles.getHead();

        while (actual != nullptr) {
            window.draw(actual->spri);
            window.draw(actual->text);
            actual = actual->sigt;
        }
        window.draw(displayedText);


    }

    window.draw(button.rectangleMenu(Vector2f(997, 454)));
    window.draw(text.textShow("MENU", Vector2f(1060, 466)));

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

void Windoww::scalarImagen() {

    Vector2u textureSizew = images[index].getSize();
    Vector2u windowSizew = window.getSize();
    float scaleXx = static_cast<float>(windowSizew.x) / textureSizew.x;
    float scaleYy = static_cast<float>(windowSizew.y) / textureSizew.y;
    newWallp.setScale(scaleXx, scaleYy);
}

void Windoww::imagen()
{
    //Incrementar el indice de la imagen
    index = (index + 1) % NUM_IMAGENS;

    //Actualizar la textura del sprite
    newWallp.setTexture(images[index]);

    //Escalar la nueva imagen
    scalarImagen();
}