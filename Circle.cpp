#include "Circle.h"

Circle::Circle() {
	//Mi cuadro de colores, ahora definitivo
	texture.loadFromFile("HollowArchives/HollowCharm.png");

	indi = 0;

	for (int i = 0; i < 12; i++) {
		emblemTextures[i].loadFromFile(emblemFilenames[i]);
	}


}

Sprite Circle::charm() {
	
	Sprite sprite(texture);
	
	sprite.setScale(0.66f, 0.6f);//Escala de la imagen
	sprite.setPosition(997, 520);

	for (int i = 0; i < emblemCount; i++) {

		emblems[i].setTexture(emblemTextures[i]);
	}
	return sprite;
}

Sprite Circle::createCircle(Vector2f position, Vector2u textureSize) {
	indice(position);

	//Verificar si el mouse esta dentro del area del panel de emblemas
	if (position.x >= 997 && position.x <= 997 + (textureSize.x * 0.66f) &&
		position.y >= 520 && position.y <= 520 + (textureSize.y * 0.6f)) {

		emblems[indi].setTexture(texture);
		emblemSelected = true;
		int emblemSize = 130;

		
		return Sprite();
	}
	else if (emblemSelected) {

		
		Sprite emblemToDraw = emblems[indi];  // Crear una copia del sprite

		emblemToDraw.setPosition(position);   // Posicionar el emblema en el clic
		emblemToDraw.setScale(0.4f, 0.4f);

		
		return emblemToDraw;
	}

	return Sprite();  //Retornar un sprite vacio

}

void Circle::indice(Vector2f index)
{

	if ((index.x > 1007 && index.x < 1060) && (index.y > 526 && index.y < 578)) {
		indi = 0;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 526 && index.y < 578)) {
		indi = 1;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 526 && index.y < 578)) {
		indi = 2;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 586 && index.y < 636)) {
		indi = 3;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 586 && index.y < 636)) {
		indi = 4;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 586 && index.y < 636)) {
		indi = 5;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 644 && index.y < 697)) {
		indi = 6;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 644 && index.y < 697)) {
		indi = 7;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 644 && index.y < 697)) {
		indi = 8;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 702 && index.y < 745)) {
		indi = 9;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 702 && index.y < 745)) {
		indi = 10;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 702 && index.y < 745)) {
		indi = 11;
	}

}