//
//  EventVideo.hpp
//  ofPlay
//
//  Created by 池上綾乃 on 2017/08/29.
//
//
#pragma once
#ifndef EventVideo_hpp
#define EventVideo_hpp
#include <stdio.h>
#endif /* EventVideo_hpp */
#include "ofMain.h"
#include "CONST.h"
class EventVideo{
    public:
    CONST::E_GIMMICK mGimmick;
    ofEvent <CONST::E_GIMMICK> mEndEvent;
    ofVideoPlayer mPlayer;
    void setup(string path,ofLoopType type,CONST::E_GIMMICK app);
    void update();
    void draw(float x,float y,float width,float height);
    void play();
    void stop();
    void pause();
    void setSpeed(float speed);
    void setFrame(int frameNum);
    void closeMovie();
    int getTotalNumFrames();
    bool mIsPlayed;
};
