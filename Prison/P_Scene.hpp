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
    
    float w = ofGetWidth() / 2;
    float h = ofGetHeight() / 2;
    
    float p = cos(PI * 72 / 180);
    float q = sin(PI * 72 / 180);
    float r = tan(PI * 54 / 180);
    float s = tan(PI * 36 / 180);
    float t =  200 * p * s;
    float v = 100/ r;

    //満天の星
    bool mIsKeyPressed;
    ofImage img;
    int time;
    int i;
    int j;


    
};
