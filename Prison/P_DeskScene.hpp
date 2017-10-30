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
#include <stdio.h>
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
    
    //Mission1
    ofImage town;
    
    ofImage lamp;
    ofImage houselight;
    ofImage tree;
    ofImage pampukin;
    
    ofImage rabbit;
    
    bool mLamp;
    bool eHouselight;
    bool dTree;
    bool rPampukin;
    
    
    //Mission2
    ofVec2f mPosition;
    ofVec2f mVelocity;
    
    ofImage sky;
    
    
    float px;
    float py;
    float vx;
    float vy;
    
    ofImage Sun;
    float nx = ofGetWidth() / 2-200;
    float ny;
    float size_x = 300;
    float size_y = 300;
    float color = 128;
    
    bool isMove;
    
    //Mission3
    

};
