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

#endif /* M_DeskScene_hpp */

class M_DeskScene : public BaseScene{
public:
    void setup();
    void setupCurse();
    void setupBat();
    void update();
    void updateCurse();
    void updateBat();
    void draw();
    void drawBat();
    void drawCurse();
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
    ofVideoPlayer ofMovie;
    ofImage magic_kabe;
    float px;
    float py;
    
    //curse
    int check, angle;
    float range,add;
    
    //bat
    ofVideoPlayer Movie1;
    float BatPosition1x = 0;
    float BatPosition1y = 0;
    float BatPosition1w = 0;
    float BatPosition1h = 0;
    ofSoundPlayer BatSound;
    
    //spk
    ofxSPK::System sys;
    ofxSPK::Group group;
    ofImage sprite;
    ofxSPK::Modifier rot;
};
