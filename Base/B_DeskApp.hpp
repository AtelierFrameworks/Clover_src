//
//  B_DeskApp.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//
//also shelf
#pragma once
#ifndef B_DeskApp_hpp
#define B_DeskApp_hpp

#include <stdio.h>
#include "ofMain.h"
#include "BaseApp.hpp"
#include "ofxLeapMotion2.h"
#include "M_DeskScene.hpp"
#include "P_DeskScene.hpp"
#endif /* B_DeskApp_hpp */

class B_DeskApp : public BaseApp{
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
    void changeScene();
    void setLeapData(std::vector <ofxLeapMotionSimpleHand> simpleHands);
    void endMovie(CONST::E_GIMMICK & app);
    ofEvent<CONST::E_GIMMICK> mMovieEndEvent;
};
