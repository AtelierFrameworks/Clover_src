#pragma once

#include "B_BedApp.hpp"
#include "BaseApp.hpp"
#include "B_DeskApp.hpp"
#include "B_FloorApp.hpp"
#include "ArduinoManager.hpp"
#include "ofxTrueTypeFontUC.h"
#include "EventVideo.hpp"
class ofApp : public BaseApp{
    
	public:
    void setup();
    void setupMission1();
    void setupStair();
    void setupMission2();
    void setupSun();
    void setupMission3();
    void setupStar();
    void update();
    void updateMission1();
    void updateStair();
    void updateMission2();
    void updateSun();
    void updateMission3();
    void updateStar();
    void draw();
    void drawMission1();
    void drawStair();
    void drawMission2();
    void drawSun();
    void drawMission3();
    void drawStar();
    void drawTimer();
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
    void changeMission(CONST::E_MISSION mission);
    void endMovie(CONST::E_MOVIE & movie);
    void receiveData(std::vector<CONST::E_SENSOR> & isActionParts);
//      bool judgeGimmick();
        ofFile mLogDataFile;
        ArduinoManager mArduinoManager;
        shared_ptr<B_BedApp> mBedApp;
        shared_ptr<B_DeskApp> mDeskApp;
        shared_ptr<B_FloorApp> mFloorApp;
    ofSoundPlayer mBgm;
    int mID;
    //0:ベッド 1:机 2:いす 3:棚 4:カーテン
    //s
    bool mIsAction[10];
    bool mIsStartMission;
    bool mIsVideoPlaying;
private:
    std::vector<CONST::E_SENSOR> mJudgeArray;

    
    ofEasyCam mCam;
    
    //
    float size = 90;//反応箇所の画像サイズ（カボチャ、コウモリ）
    float length = 200;//星の一辺の長さ
    float w = ofGetWidth() / 2;
    float h = ofGetHeight() / 2;
    
    float p = cos(PI * 72 / 180);
    float q = sin(PI * 72 / 180);
    float r = tan(PI * 54 / 180);
    float s = tan(PI * 36 / 180);
    float t =  200 * p * s;
    float v = 100/ r;
    
    //挑戦状
    EventVideo challenge_Movie;
    bool  frameByframe;
    
    //Mission1
    ofImage town;
    
    ofImage rabbit;
    
    
    ofImage lamp;
    ofImage houselight;
    ofImage tree;
    ofImage pampukin;
    ofImage tower;
    
    bool mLamp;
    bool eHouselight;
    bool dTree;
    bool rPampukin;
    bool hTower;
    int homePastTime = 0;
    //階層移動
    ofVec2f mPosition;
    ofVec2f mVelocity;
    
    ofImage town1;
    ofImage town2;
    ofImage town3;
    
    float px;
    float py;
    float vx;
    float vy;
    
    bool isMove;
    
    //Mission2
    ofImage bat;
    ofImage pumpkin;
    bool isBat;
    bool isPumpkin;
    
    //太陽月
    ofImage sky;
    bool isMoved;
    
    //Mission3
    bool drawline1;
    bool drawline2;
    bool drawline3;
    bool drawline4;
    bool drawline5;
    
    bool isBat2;
    
    
    //満天の星
    bool mIsKeyPressed;
    ofImage img;
    int time;
    string timerText;
    int i;
    int j;
    
    //Timer
    double sec = 0;
    float timer= 181;
    float min = 3;
    
    ofxTrueTypeFontUC Timer;
    bool isTimer = true;
    
    ofSoundPlayer mSound;

};
