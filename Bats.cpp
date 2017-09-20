#include "Bats.h"



void Bats::setup(int _sep){
	Position.x = ofGetWidth() / 2;
	Position.y = ofGetHeight() / 2;
	Position.z = ofGetHeight() / 2;

	if (_sep == 0) {
		Movie.load("M_bat1.mp4");
		Movie.play();

		//進行方向をランダムでとる
		Velocity.x = ofRandom(-1, 0);
		Velocity.y = ofRandom(-1, 0);
		Velocity.z = ofRandom(-1, 1);
	}
	if (_sep == 1) {
		Movie.load("M_bat3.mp4");
		Movie.play();

		//進行方向をランダムでとる
		Velocity.x = ofRandom(0, 1);
		Velocity.y = ofRandom(-1, 0);
		Velocity.z = ofRandom(-1, 1);
	}

}


void Bats::update(){
	Position = Position + Velocity;
	Movie.update();
	
	
}

void Bats::draw() {
	Movie.draw(Position,100,100);
    
}
