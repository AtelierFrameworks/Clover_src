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
#include "ofxTrueTypeFontUC.h"
#include <vector>
#include "Letter.h"
#endif /* M_BedScene_hpp */
class M_BedScene : public BaseScene{
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
    void startBed();
    void endBed();
    void actionBed();
    void endMovieEvent(CONST::E_GIMMICK & gimmick);
    void updateFont();
    void drawFont();
    ofImage magic_kabe;
    float px;
    float py;
    //desk Font
    int countTime ;
    Letter letters[20];
    //bookshelf
private:
    bool isShowFont;
    
};
