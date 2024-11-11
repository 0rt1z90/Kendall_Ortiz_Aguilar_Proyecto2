#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

const int emblemCount = 12;

class Circle {
private:
	int indi;
	Texture texture;

	Texture emblemTextures[emblemCount];
	Sprite emblems[emblemCount];
	string emblemFilenames[12] = {
	"HollowCharm/1HardBlow.png",

	"HollowCharm/2MasterOfLunges.png",

	"HollowCharm/3SharpShadow.png",

	"HollowCharm/4Grimm'sChild.png",

	"HollowCharm/5SongOfTheWeaver.png",

	"HollowCharm/6UnbreakableHeart.png",

	"HollowCharm/7MonarchSoul.png",

	"HollowCharm/8HeartOfTheVoid.png",

	"HollowCharm/9BlessingOfJoni.png",

	"HollowCharm/10Baldur'sBreastplate.png",

	"HollowCharm/11GloryOfTheStingmaster.png",

	"HollowCharm/12LarvaflyElegy.png"
	};


	bool emblemSelected = false;  //Verificar si se ha seleccionado un emblema

public:
	Circle();
	Sprite charm();
	Sprite createCircle(Vector2f, Vector2u);
	void indice(Vector2f);
	int indice2(Vector2f);
	string getEmblemsFiles(int);
	Sprite getEmblems(int);
};