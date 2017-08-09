#pragma once

#include "ofMain.h"
#include <vector>
#include "BaseScene.hpp"
#include "P_Scene.hpp"
#include "M_Scene.hpp"
#include "ofxLeapMotion2.h"
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
        void exit();
        void actionCurtain();
        void closeCurtain();
        void setupArduino(const int & version);
        void updateArduino();
        void setupLeapMotion();
        void updateLeapMotion();
        static string getLogDay();
    
        std::vector<BaseScene *> mScenes;
        ofFile mLogDataFile;
        ofArduino mArduino;
        ofxLeapMotion mLeap; // Leap Motionのメインクラスをインスタンス化
        std::vector <ofxLeapMotionSimpleHand> simpleHands; // シンプルな手のモデルのvector配列
        ofEasyCam mCam;

};
