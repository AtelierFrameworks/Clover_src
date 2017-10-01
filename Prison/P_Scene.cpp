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
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    mBackground.load("Prison/P_front.png");
    //chair
    mVideo = new EventVideo();
    mVideo->setup("Prison/inazuma.mp4",OF_LOOP_NONE,CONST::G_P_CHAIR);
    ofAddListener(mVideo->mEndEvent,this,&P_Scene::endMovieEvent);
    mIsPlayBed = false;
    //shelf
    mIsPlayShelfSound = false;
    mPlayer.load("Prison/koe.wav");
    mPlayer.setLoop(false);

    //crack
    mCrack.setup();
    mCrackPlayer.load("Prison/P_crack.mp3");
    mCrackPlayer.setLoop(false);
    mCrackPlayer.setMultiPlay(true);
    mLastCrackPlayer.load("Prison/P_lastCrack.mp3");
    mLastCrackPlayer.setLoop(false);
    mLastCrackPlayer.setMultiPlay(true);
    mCrackVoicePlayer.load("Prison/kodomo.wav");
    mCrackVoicePlayer.setLoop(false);
    mIsPlayCrackVoice = false;
    mIsPlayCrackSound = false;
    mIsPlayBed = false;
}


//--------------------------------------------------------------
void P_Scene::update(){
    fingersMovie.update();
    if(mIsPlayShelfSound){
        if(!mPlayer.isPlaying()){
            mIsPlayShelfSound = false;
        }
    }
    
    if(mIsPlayCrackSound){
        if(!mPlayer.isPlaying()){
            mIsPlayCrackSound = false;
            mCrackVoicePlayer.play();
            mIsPlayCrackVoice = true;
            
        }
    }

    if(mIsPlayCrackVoice){
        if(!mCrackVoicePlayer.isPlaying()){
            mIsPlayCrackVoice = false;
            mIsPlayBed = false;
            P_Crack::reset();
        }
    }

    if(mIsPlayChair){
        mVideo->update();
    }

}

//--------------------------------------------------------------
void P_Scene::draw(){
    ofSetColor(255);
    mBackground.draw(0,0,ofGetWidth(),ofGetHeight());
//    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    if(mIsPlayChair){
        mVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
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
    if(!mIsPlayShelfSound){
        mIsPlayShelfSound = true;
        mPlayer.play();
    }
}

void P_Scene::actionChair(){
    mIsPlayChair = true;
    mVideo->play();
}

void P_Scene::actionBed(){
    if(!mIsPlayCrackVoice){
    mCrack.addCount();
    mCrackPlayer.play();
    mIsPlayBed = true;
        if(P_Crack::getCount() == 3){
            soundCrack();
        }
    }
}

void P_Scene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    mIsPlayChair = false;
    CONST::E_GIMMICK e_gimmick = gimmick;
    mVideo->stop();
    ofNotifyEvent(mEndMovieEvent,e_gimmick);
}



void P_Scene::soundCrack(){
    mIsPlayCrackSound = true;
    mLastCrackPlayer.play();
}

void P_Scene:: exit(){
    ofRemoveListener(mVideo->mEndEvent, this, &P_Scene::endMovieEvent);
}

