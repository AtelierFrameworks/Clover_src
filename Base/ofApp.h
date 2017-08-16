#pragma once


#include "Prison/P_Scene.hpp"
#include "M_BedScene.hpp"

#include "B_BedApp.hpp"
class B_DeskApp;
class B_FloorApp;
#include "BaseApp.hpp"
class ofApp : public BaseApp{
    
	public:
        enum E_SCENE {NONE,MAGIC,PRISON};
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
    void changeScene();
        ofFile mLogDataFile;
        ofArduino mArduino;
        shared_ptr<B_BedApp> mBedApp;
        shared_ptr<B_DeskApp> mDeskApp;
        shared_ptr<B_FloorApp> mFloorApp;

};
