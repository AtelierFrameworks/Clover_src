#pragma once

#include "ofMain.h"
#include <vector>
#include "BaseScene.hpp"
#include "P_Scene.hpp"
#include "M_Scene.hpp"
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
        static string getLogDay();
    
        std::vector<BaseScene *> mScenes;
        ofFile mLogDataFile;
        static int logNumber;
        static bool isStartScene;
        ofArduino mArduino;
};
