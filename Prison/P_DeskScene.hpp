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
    
    float size = 100;//反応箇所の画像サイズ（カボチャ、コウモリ）
    float length = 200;//星の一辺の長さ
    float w = ofGetWidth() / 2;
    float h = ofGetHeight() / 2;
    
    float p = cos(PI * 72 / 180);
    float q = sin(PI * 72 / 180);
    float r = tan(PI * 54 / 180);
    float s = tan(PI * 36 / 180);
    float t =  200 * p * s;
    float v = 100/ r;

    
    //Mission1
    ofImage town;
    
    ofImage lamp;
    ofImage houselight;
    ofImage tree;
    ofImage pampukin;
    
    ofImage elephant;
    ofImage dog;
        
    bool mLamp;
    bool eHouselight;
    bool dTree;
    bool rPampukin;
    
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
    ofVec2f nPosition;
    ofVec2f nVelocity;
    
    ofImage sky;
    
    float x;
    float y;
    float wx;
    float wy;
    
    ofImage Sun;
    float nx = ofGetWidth() / 2 - 200;
    float ny;
    float size_x = 300;
    float size_y = 300;
    float color = 128;
    
    bool isMoved;
    
    //満天の星
    bool mIsKeyPressed;
    ofImage img;
    int time;
    int i;
    int j;

};
