#pragma once
#include "ofMain.h"

class Bat
{
public:
	void setup(int _sep);
	void update();
	void draw();
    void reset();
	ofImage* Bats[12];

	float currentFrame;
	ofVec2f Position;
	ofVec2f Velocity;
    int sep;
};

