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
    void endMovieEvent(CONST::E_APP & App);
    void updateFont();
    void drawFont();
     ofImage magic_kabe;
    float px;
    float py;
    
    //desk Font
    ofxTrueTypeFontUC myFont;
    string text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12, text13, text14, text15, text16, text17, text18, text19, text20;
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10, x11, y11, x12, y12, x13, y13, x14, y14, x15, y15, x16, y16, x17, y17, x18, y18, x19, y19, x20, y20;
    double a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20;
    int countTime = 0;
    int count = 0;
    int num;
    std::vector <string> WORDS;
    int index;
    int a;
    
    //bookshelf
    
    
};
