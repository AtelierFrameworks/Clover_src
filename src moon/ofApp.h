#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage moon;
		ofImage cloud;

		ofVec2f mPosition;

		float m_px = ofGetWidth() / 2- 20;
		float m_py = ofGetHeight() + 50;
		float m2_px = 50;
		float m2_py = 50;

		float c_px = -100;
		float c_py = 15;

		
};
