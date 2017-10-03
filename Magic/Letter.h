#pragma once
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#include <vector>

class Letter
{
public:
	void setup(int _x,int _y,int _count_s);
	void update(int _count_u);
	void draw();
    void reset();
	int alpha;
	int countBorn;
	int countNow;
	int countGap;
    bool mIsPlaySound;
	ofxTrueTypeFontUC myFont;
	int num;
	string text;
	int x, y;
    ofSoundPlayer* mSound;
};

