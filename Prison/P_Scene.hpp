//
//  P_Scene.hpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/06/11.
//
//
//Áâ¢Â±ãÁî®„Ç∑„Éº„É≥
#pragma once
#ifndef P_Scene_hpp
#define P_Scene_hpp
#include "BaseScene.hpp"
#include <stdio.h>
#include "P_Crack.hpp"
#endif /* P_Scene_hpp */
class P_Scene : public BaseScene{
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
    void actionShelf();
    void actionChair();
    void actionBed();
    void endMovieEvent(CONST::E_GIMMICK & App);
    void soundCrack();
    ofVideoPlayer fingersMovie;
    bool mIsPlayChair;
    bool mIsPlayShelfSound;
    bool mIsPlayBed;
    bool mIsPlayCrackVoice;
    ofSoundPlayer mPlayer;
    ofSoundPlayer mCrackPlayer;
    ofSoundPlayer mLastCrackPlayer;
    ofSoundPlayer mCrackVoicePlayer;
    P_Crack mCrack;
    bool mIsPlayCrackSound;
    ofImage mBackground;
};
