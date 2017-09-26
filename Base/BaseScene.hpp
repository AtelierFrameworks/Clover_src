//
//  BaseScene.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
#pragma once
#ifndef BaseScene_hpp
#define BaseScene_hpp
#include <stdio.h>
#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include <vector>
#include "EventVideo.hpp"
#include "CONST.h"
#endif /* BaseScene_hpp */
//親クラス
class BaseApp;
class BaseScene{
public:
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    virtual void mouseMoved(int x, int y );
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    virtual void mouseEntered(int x, int y);
    virtual void mouseExited(int x, int y);
    virtual void windowResized(int w, int h);
    virtual void dragEvent(ofDragInfo dragInfo);
    virtual void gotMessage(ofMessage msg);
    
    virtual void setLeapData(std::vector <ofxLeapMotionSimpleHand> simpleHands);
    virtual void actionDesk();
    virtual void actionChair();
    virtual void actionBed();
    virtual void actionBedNext(){};
    virtual void actionStandBed(){};
    virtual void actionShelf();
    virtual void endShelf(){};
    virtual void actionFloor(){};
    virtual void actionEndMovie(){};
    virtual void endMovieEvent(CONST::E_GIMMICK & App){};
    EventVideo mVideo;
    ofEvent<CONST::E_GIMMICK> mEndMovieEvent;
    bool isAction = false;
    std::vector <ofxLeapMotionSimpleHand> mSimpleHands;

};
