#include "Textt.h"

Textt::Textt() {
	font.loadFromFile("HollowArchives/HollowText.ttf");//Fuente de texto
	fontText.loadFromFile("HollowArchives/HollowFont5.ttf");
}

Text Textt::textShow(string fact, Vector2f poss) {

	Text text(fact, font);

	text.setPosition(poss);
	return text;
}

Text Textt::textNodo(string txt, Vector2f mouse) {

	newText.setFont(fontText);  
	newText.setString(txt);  //Usar el texto ingresado
	newText.setCharacterSize(24);
	newText.setFillColor(Color::White);
	newText.setPosition(mouse.x - 25, mouse.y - 60);

	return newText;
}