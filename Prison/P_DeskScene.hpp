//
//  P_DeskScene.hpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/21.
//
//
#pragma once
#ifndef P_DeskScene_hpp
#define P_DeskScene_hpp

#include "BaseScene.hpp"
#include "P_Crack.hpp"
#include <stdio.h>
#include "ofxSPK.h"
#endif /* P_DeskScene_hpp */
class P_DeskScene : public BaseScene{
    void setup();
    void update();
    void draw();
    void updateFire();
    void drawFire();
    void resetFire();
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
    void setupFire();
    void actionBed();
    void actionChair();
    ofVideoPlayer mShadowMovie;
    ofSoundPlayer mySound;
    bool frameByframe;
    ofImage mBackground;
    bool gIsKeyPressed;
    bool lIsKeyPressed;
    bool mIsPlayBed;
    bool mIsPlayDesk;
    bool mIsPlayChair;
    //fireBall
    ofVec2f mPosition;
    ofVec2f mVelocity;
    float x;
    float y;
    float vx;
    float vy;
    
    ofxSPK::System sys;
    ofxSPK::Group group;
    ofImage sprite;
    ofxSPK::Modifier rot;
    
    //bed crack
    P_Crack mCrack;
    
    };
