#include "Bat.h"



void Bat::setup(int _sep) {
    sep = _sep;
	Position.x = ofGetWidth() / 2;
	Position.y = ofGetHeight() / 2;

	Velocity.x = ofRandom(0-_sep, 1-_sep)*3;
	Velocity.y = ofRandom(-1, -0.5)*3;

	for (int i = 0; i < 12; i++) {
		char chara[20];
        Bats[i] = new ofImage();
		sprintf(chara, "Magic/Bat/M_bat0_%d.png", i + 1);
        Bats[i]->load(chara);
		
	}
	currentFrame = ofRandom(0,11);
}

void Bat::update() {
    ofLogNotice() << "update" << Position.x;
    ofLogNotice() << "updatey" << Position.y;
	Position += Velocity;
}

void Bat::draw() {
	Bats[(int)(currentFrame)]->draw(Position.x, Position.y,100,100);
    
	currentFrame+=0.2;

	if (currentFrame > 11) {
		currentFrame = 0;
	}
}

void Bat::reset(){
    Position.x = ofGetWidth() / 2;
    Position.y = 400;
    
    Velocity.x = ofRandom(0-sep, 1-sep)*3;
    Velocity.y = ofRandom(-1, -0.5)*3;
    currentFrame =  ofRandom(0,11);
    ofLogNotice() << "positionx" << Position.x;
    ofLogNotice() << "positiony" << Position.y;

}
