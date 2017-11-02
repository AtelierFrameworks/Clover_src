//
//  EventVideo.cpp
//  ofPlay
//
//  Created by 池上綾乃 on 2017/08/29.
//
//

#include "EventVideo.hpp"

void EventVideo::setup(string path,ofLoopType state,CONST::E_MOVIE movie){
    mIsPlayed = false;
    mPlayer.load(path);
    mPlayer.setLoopState(state);
    mMovie = movie;
}

void EventVideo::update(){
    mPlayer.update();
    bool isPlaying = mPlayer.isPlaying();
    if(mPlayer.isInitialized() && !mIsPlayed && !mPlayer.isPlaying()){
        ofNotifyEvent(mEndEvent,mMovie);
        mIsPlayed = true;
    }
}

void EventVideo::draw(float x,float y,float width,float height){
    mPlayer.draw(x,y,width,height);
}

void EventVideo::play(){
    mPlayer.play();
    mIsPlayed = false;
}
void EventVideo::stop(){
    mPlayer.stop();
    mIsPlayed = true;
}

void EventVideo::pause(){
    mPlayer.setPaused(true);
}

void EventVideo::setSpeed(float speed){
    mPlayer.setSpeed(speed);
}

void EventVideo::setFrame(int flameNum){
    mPlayer.setFrame(flameNum);
}

void EventVideo::closeMovie(){
    mPlayer.closeMovie();
}

int EventVideo::getTotalNumFrames(){
    return mPlayer.getTotalNumFrames();
}
