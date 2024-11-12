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

	//Verificar si el clic esta dentro del area del panel de emblemas
	if (position.x >= 997 && position.x <= 997 + (textureSize.x * 0.66f) &&
		position.y >= 520 && position.y <= 520 + (textureSize.y * 0.6f)) {

		//Marcar que se ha seleccionado un emblema
		emblems[indi].setTexture(texture);
		emblemSelected = true;

		//Retornar un sprite vacio si solo estas seleccionando un emblema
		return Sprite();
	}
	else if (emblemSelected) {
		//Si el clic no esta en el panel de emblemas y ya se ha seleccionado un emblema


		Sprite emblemToDraw = emblems[indi];  //Crear una copia del sprite

		emblemToDraw.setPosition(position.x - 30, position.y - 40);   //Posicionar el emblema en el clic
		emblemToDraw.setScale(0.4f, 0.4f);

		return emblemToDraw;

	}

	return Sprite(); //Retornar un sprite vacio si no se ha seleccionado un emblema

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

int Circle::indice2(Vector2f index)
{

	if ((index.x > 1007 && index.x < 1060) && (index.y > 526 && index.y < 578)) {
		return 0;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 526 && index.y < 578)) {
		return  1;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 526 && index.y < 578)) {
		return  2;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 586 && index.y < 636)) {
		return  3;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 586 && index.y < 636)) {
		return  4;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 586 && index.y < 636)) {
		return  5;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 644 && index.y < 697)) {
		return  6;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 644 && index.y < 697)) {
		return  7;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 644 && index.y < 697)) {
		return  8;
	}
	else if ((index.x > 1007 && index.x < 1060) && (index.y > 702 && index.y < 745)) {
		return  9;
	}
	else if ((index.x > 1069 && index.x < 1122) && (index.y > 702 && index.y < 745)) {
		return  10;
	}
	else if ((index.x > 1137 && index.x < 1192) && (index.y > 702 && index.y < 745)) {
		return  11;
	}
}

Sprite Circle::getEmblems(int index) {
	return emblems[index];
}

string Circle::getEmblemsFiles(int index) {
	return emblemFilenames[index];
}