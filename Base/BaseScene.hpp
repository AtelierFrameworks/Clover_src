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
#endif /* BaseScene_hpp */
//親クラス
class ofApp;
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
    virtual void actionShelf();
    
    std::vector <ofxLeapMotionSimpleHand> mSimpleHands;
    

};
