#pragma once
#include "ofMain.h"
class Bats
{
public:
	void setup(int _sep);
	void update();
	void draw();

	ofVideoPlayer Movie;
	
	ofVec3f Position;
	ofVec3f Velocity;
};

