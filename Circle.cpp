#include "Circle.h"

Circle::Circle() {
	//Mi cuadro de colores, ahora definitivo
	texture.loadFromFile("HollowArchives/HollowCharm1.png");

}

Sprite Circle::charm() {
	
	Sprite sprite(texture);
	
	sprite.setScale(0.66f, 0.6f);//Escala de la imagen
	sprite.setPosition(997, 520);
	return sprite;
}

Sprite Circle::createCircle(Vector2f position, Vector2u textureSize) {

	//Verificar si el mouse esta dentro del area del panel de emblemas
	if (position.x >= 997 && position.x <= 997 + (textureSize.x * 0.66f) &&
		position.y >= 520 && position.y <= 520 + (textureSize.y * 0.6f)) {

		//Calcular la poss
		Vector2f relativePos((position.x - 997) / 0.66f, (position.y - 520) / 0.6f);

		int emblemSize = 35;  //Textura(pixeles) de los emblemas
		int emblemX = static_cast<int>(relativePos.x / emblemSize) * emblemSize;
		int emblemY = static_cast<int>(relativePos.y / emblemSize) * emblemSize;

		//Crear un sprite con la parte de la textura que contiene el emblema seleccionado
		currentEmblem.setTexture(texture);
		currentEmblem.setTextureRect(IntRect(emblemX, emblemY, emblemSize, emblemSize));

		emblemSelected = true;  //Marcar que se ha seleccionado un emblema

		
		return Sprite();
	}
	else if (emblemSelected) {

		
		Sprite emblemToDraw = currentEmblem;  //Crear una copia del sprite
		emblemToDraw.setPosition(position);   //Posicionar el emblema en el clic

		return emblemToDraw;
	}

	return Sprite();  //Retornar un sprite vacio




}