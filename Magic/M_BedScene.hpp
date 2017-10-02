//
//  M_BedScene.hpp
//  Atelier_Room
//
//  Created by √ä¬±‚Ä†‚Ä∞‚àè√§√Å‚àÇ√¶‚Ä∞œÄ√â on 2017/06/11.
//
//
//√à‚â†√Æ√ä‚â•√Ø√Ç√µ‚â•√ä√µ‚àè√à¬ß¬Æ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•
#pragma once
#ifndef M_BedScene_hpp
#define M_BedScene_hpp
#include "BaseScene.hpp"
#include <stdio.h>
#include <vector>
#include "Letter.h"
#endif /* M_BedScene_hpp */
class M_BedScene : public BaseScene{
public:
    void setup();
    void setupStair();
    void update();
    void draw();
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
    void exit();
    void actionBed();
    void actionBedNext();
    void actionStandBed();
    void endMovieEvent(CONST::E_GIMMICK & gimmick);
    void updateFont();
    void drawFont();
    void actionEndMovie();
    void updateBookShelf();
    ofImage magic_kabe;
    float px;
    float py;
    //desk Font
    int countTime;
    static const int LETTER_COUNT = 20;
    Letter letters[LETTER_COUNT];
      //bookshelf and stair
    ofEvent<bool> mStairEvent;
private:
    bool isShowFont;
    ofEasyCam mCamera;
    //movie bookshelf
    EventVideo mBookPlayer;
    bool mIsPlayBookShelf;
    bool mIsPrevious;
    bool mIsPlayBed;
  
    //stair
    ofVec2f mPosition;
    ofSoundPlayer mStairPlayer;
//    constexpr static const float gravity = 9.8;
    ofImage *magic_kabe2;
    ofImage *magic_kabe3;
    ofImage *preWall;
    float stairPx;
    float stairPy;
    bool isMove = false;

   };
