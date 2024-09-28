#include "Circle.h"


Circle::Circle() {
	//Mi cuadro de colores, no definitivo
	texture.loadFromFile("HollowArchives/HollowCharm1.png");

}
Sprite Circle::colorr() {
	
	
	Sprite sprite(texture);
	
	sprite.setScale(0.65f, 0.6f);//Escala de la imagen
	sprite.setPosition(995, 500);
	return sprite;
}