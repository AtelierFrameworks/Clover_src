//
//  B_FloorApp.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//
#pragma once
#ifndef B_FloorApp_hpp
#define B_FloorApp_hpp
#include "ofMain.h"
#endif /* B_FloorApp_hpp */
#include "BaseApp.hpp"
class B_FloorApp : public BaseApp{
    
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
    ofImage floor;
    ofImage floor2;
    bool floorchange;
    ofVec2f mPosition;
    float x = -ofGetWidth() *3 /  2;
    float y = -ofGetHeight() * 3 / 2 ;
    ofVec2f mVelocity;
    int i;
    int j;
    float w, h;
};
