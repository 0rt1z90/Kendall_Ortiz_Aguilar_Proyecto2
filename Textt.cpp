#include "Textt.h"
Textt::Textt() {
	font.loadFromFile("HollowArchives/HollowText.ttf");//Fuente de texto

}
Text Textt::textShow(string fact, Vector2f poss) {

	Text text(fact, font);

	text.setPosition(poss);
	return text;
}