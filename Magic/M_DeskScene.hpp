//
//  M_DeskScene.hpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/09/07.
//
//

#pragma once
#ifndef M_DeskScene_hpp
#define M_DeskScene_hpp
#include <stdio.h>
#include "BaseScene.hpp"
#include "ofxSPK.h"
#include "Bat.h"
#endif /* M_DeskScene_hpp */

class M_DeskScene : public BaseScene{
public:
    void setup();
    void setupCurse();
    void setupBat();
    void setupStair();
    void update();
    void updateCurse();
    void updateBat();
    void updateBookShelf();
    void draw();
    void drawBat();
    void drawCurse();
    void drawWall();
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
    void actionShelf();
    void endShelf();
    void actionEndMovie();
    void actionBed();
    void actionStandBed();
    void actionBedNext();
    ofImage magic_kabe;
    float px;
    float py;
    //shelf
    bool mIsPlayShelf;
    ofEvent<bool> mShelfEvent;
    //curse
    int check, angle;
    float range,add;
    int out ;
    int particle = 3000;
    
    private:
    //bat
    ofSoundPlayer BatSound;
    static const int BATCOUNT = 5;
    Bat bats[BATCOUNT];
    int separate;
    //movie bookshelf
    ofVideoPlayer mBookPlayer;
    bool mIsPlayBookShelf;
    bool mIsPrevious;
    bool mIsPlayBed;
    
    //spk
    ofxSPK::System sys;
    ofxSPK::Group group;
    ofImage sprite;
    ofxSPK::Modifier rot;
    
    //stair
    ofVec2f mPosition;
    constexpr static const float gravity = 9.8;
    ofImage magic_kabe2;
    ofImage magic_kabe3;
    float stairPx;
    float stairPy;
    bool isMove = false;
    };
