//
//  M_FloorScene.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/09/07.
//
//
#pragma once
#ifndef M_FloorScene_hpp
#define M_FloorScene_hpp
#include <stdio.h>
#include "BaseScene.hpp"
#endif /* M_FloorScene_hpp */

class M_FloorScene : public BaseScene{
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
    void endMovieEvent(CONST::E_GIMMICK & gimmick);
    void actionChair();
    ofVideoPlayer ofMovie;
    float px;
    float py;
    ofImage magic_floor;
    bool isPlayChair;
};
