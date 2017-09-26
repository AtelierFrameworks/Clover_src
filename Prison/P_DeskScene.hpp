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
    
    ofVideoPlayer fingersMovie;
    ofSoundPlayer mySound;
    bool frameByframe;
    ofImage myImage;
    bool gIsKeyPressed;
    bool lIsKeyPressed;
    
    };
