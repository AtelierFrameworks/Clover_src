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
    
    ofImage town;
    ofImage town2;
    ofImage town3;
    
    ofImage sky;
    
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
    bool isMove;
    
    //満天の星
    bool mIsKeyPressed;
    ofImage img;
    int time;
    int i;
    int j;
    

};
