//
//  P_Scene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
#include "P_Scene.hpp"
void P_Scene::setup(){
    //雷
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    fingersMovie.load("Prison/inazuma.mp4");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    mIsPlayShelfSound = false;
    mPlayer.load("Prison/scream.mp3");
    mPlayer.setLoop(OF_LOOP_NONE);
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

}

//--------------------------------------------------------------
void P_Scene::draw(){
    ofSetColor(0,127,127);
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
    
    }

//--------------------------------------------------------------
void P_Scene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void P_Scene::keyReleased(int key){
    
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

