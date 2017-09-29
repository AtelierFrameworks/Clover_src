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
#include "P_floor.hpp"
#include "M_FloorScene.hpp"
class BaseApp;
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
    void changeScene();
    void endMovie(CONST::E_GIMMICK & gimmick);
    ofEvent<CONST::E_GIMMICK> mMovieEndEvent;
};
