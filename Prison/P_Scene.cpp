//
//  P_Scene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
#include "P_Scene.hpp"
void P_Scene::setup(){
    mIsPlayChair = false;
    //雷
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    mBackground.load("Prison/P_front");
    //chair
    mVideo.setup("Prison/inazuma.mp4",OF_LOOP_NONE,CONST::G_P_CHAIR);
    ofAddListener(mVideo.mEndEvent,this,&P_Scene::endMovieEvent);
    mIsPlayBed = false;
    //shelf
    mIsPlayShelfSound = false;
    mPlayer.load("Prison/koe.wav");
    mPlayer.setLoop(false);

    //crack
    mCrack.setup();
    mCrackPlayer.load("Prison/kodomo.wav");
    mCrackPlayer.setLoop(false);
    mIsPlayCrackSound = false;
    mIsPlayBed = false;
}


//--------------------------------------------------------------
void P_Scene::update(){
    fingersMovie.update();
    if(mIsPlayShelfSound){
        if(mPlayer.isPlaying()){
            mIsPlayShelfSound = false;
        }
        ofSoundUpdate();
    }
    
    if(mIsPlayCrackSound){
        if(mPlayer.isPlaying()){
            mIsPlayCrackSound = false;
            mIsPlayBed = false;
            P_Crack::reset();
        }
        ofSoundUpdate();
    }

    if(mIsPlayChair){
        mVideo.update();
    }

}

//--------------------------------------------------------------
void P_Scene::draw(){
    ofSetColor(0,127,127);
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
//    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0xFFFFFF);
    
    if(mIsPlayChair){
        mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if(mIsPlayBed){
        mCrack.draw();
    }
}

//--------------------------------------------------------------
void P_Scene::keyPressed(int key){
//    if (key == 't') {
//        tIsKeyPressed = true;
//    }
}

//--------------------------------------------------------------
void P_Scene::keyReleased(int key){
//    if (key == 't') {
//        tIsKeyPressed = false;
//    }
}

//--------------------------------------------------------------
void P_Scene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_Scene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_Scene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_Scene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_Scene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_Scene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_Scene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_Scene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_Scene::dragEvent(ofDragInfo dragInfo){
    
}

void P_Scene::actionShelf(){
    mIsPlayShelfSound = true;
    mPlayer.play();
}

void P_Scene::actionChair(){
    mIsPlayChair = true;
}

void P_Scene::actionBed(){
    mCrack.addCount();
    mIsPlayBed = true;
    if(P_Crack::getCount() == 3){
        soundCrack();
    }
}

void P_Scene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    mIsPlayChair = false;
    CONST::E_GIMMICK e_gimmick = gimmick;
    mVideo.stop();
    ofNotifyEvent(mEndMovieEvent,e_gimmick);
}



void P_Scene::soundCrack(){
    mIsPlayCrackSound = true;
    mCrackPlayer.play();
}

