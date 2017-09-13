#pragma once


#include "Prison/P_Scene.hpp"
#include "Magic/M_Scene.hpp"
#include "B_BedApp.hpp"
#include "BaseApp.hpp"
#include "B_DeskApp.hpp"
#include "B_FloorApp.hpp"
#include "ofxLeapMotion2.h"
#include "ArduinoManager.hpp"
class ofApp : public BaseApp{
    
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
        void setupLeapMotion();
        void updateLeapMotion();
        void actionCurtain();
        void closeCurtain();
        void sendAction(CONST::E_GIMMICK app);
        void changeScene();
        void endMovie(CONST::E_GIMMICK & app);
//        bool judgeGimmick();
        ofFile mLogDataFile;
        ArduinoManager mArduinoManager;
        shared_ptr<B_BedApp> mBedApp;
        shared_ptr<B_DeskApp> mDeskApp;
        shared_ptr<B_FloorApp> mFloorApp;
    
    //0:ベッド 1:机 2:いす 3:棚 4:カーテン
    bool mIsAction[5];
private:
   // std::vector<GimmickDataModel> mGimmckModels;
    ofxLeapMotion mLeap; // Leap Motionのメインクラスをインスタンス化
    std::vector <ofxLeapMotionSimpleHand> simpleHands; // シンプルな手のモデルのvector配列
    ofEasyCam mCam;
};
