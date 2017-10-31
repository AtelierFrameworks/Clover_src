//
//  P_BedScene.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/17.
//
//

#ifndef P_BedScene_hpp
#define P_BedScene_hpp

#include <stdio.h>
#endif /* P_BedScene_hpp */

#include "BaseScene.hpp"
class P_BedScene : public BaseScene{
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
    
    ofImage mouse;
    ofImage horse;
    
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
    
    ofImage moon;
    ofImage cloud;
    
    ofVec2f mPosition;
    
    float m_px = ofGetWidth() / 2- 20;
    float m_py = ofGetHeight() + 50;
    float m2_px = 50;
    float m2_py = 50;
    
    float c_px = -100;
    float c_py = 15;
    
    //満天の星
    bool mIsKeyPressed;
    ofImage img;
    int time;
    int i;
    int j;
    

};
