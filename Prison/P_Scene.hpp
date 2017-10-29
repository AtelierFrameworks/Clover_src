//
//  P_Scene.hpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/06/11.
//
//
//Áâ¢Â±ãÁî®„Ç∑„Éº„É≥
#pragma once
#ifndef P_Scene_hpp
#define P_Scene_hpp
#include "BaseScene.hpp"
#include <stdio.h>
#endif /* P_Scene_hpp */
class P_Scene : public BaseScene{
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
    
    //Mission１
    ofImage town;
    
    ofImage elephant;
    ofImage dog;
    
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
    
    //Mission2
    ofVec2f mPosition;
    ofVec2f mVelocity;
    
    ofImage sky;
    
    float px;
    float py;
    float vx;
    float vy;
    
    bool isMove;
    
    //Mission3

    
};
