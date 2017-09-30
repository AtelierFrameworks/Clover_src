#include "Bat.h"



void Bat::setup(int _sep) {
	Position.x = ofGetWidth() / 2;
	Position.y = ofGetHeight() / 2;

	Velocity.x = ofRandom(0-_sep, 1-_sep);
	Velocity.y = ofRandom(-1, 0);

	for (int i = 0; i < 12; i++) {
		char chara[20];
		sprintf(chara, "Magic/Bat/M_bat0_%d.png", i + 1);
        ofLogNotice() << "chara" << chara;
		Bats[i].load(chara);
		
	}
	currentFrame = ofRandom(0,11);
}

void Bat::update() {
	Position += Velocity;
}

void Bat::draw() {
	Bats[(int)(currentFrame)].draw(Position.x, Position.y,100,100);

	currentFrame+=0.2;

	if (currentFrame > 11) {
		currentFrame = 0;
	}
}
