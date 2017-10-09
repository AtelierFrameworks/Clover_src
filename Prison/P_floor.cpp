//
//  P_floor.cpp
//  
//
//  Created by USER1 on 2017/08/31.
//
//

#include "P_floor.hpp"

void P_floor::setup(){

    //床のひび割れ
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
//    fingersMovie.load("yuka.mov");
//    fingersMovie.setLoopState(OF_LOOP_NONE);
//    fingersMovie.play();
    //背景
    mBackground.load("Prison/P_floor.png");
    
    mCrack.setup();
    mIsPlayBed = false;

}

//--------------------------------------------------------------
void P_floor::update(){
//    fingersMovie.update();
    //crack
    if(mIsPlayBed){
        if(P_Crack::getCount() == -1){
            mIsPlayBed = false;
        }else{
            mCrack.draw();
        }
    }
}

//--------------------------------------------------------------
void P_floor::draw(){
    mBackground.draw(0,0,ofGetWidth(),ofGetHeight());

}

//--------------------------------------------------------------
void P_floor::keyPressed(int key){

}

//--------------------------------------------------------------
void P_floor::keyReleased(int key){

}

//--------------------------------------------------------------
void P_floor::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_floor::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_floor::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_floor::dragEvent(ofDragInfo dragInfo){
    
}

void P_floor::actionBed(){
    mIsPlayBed = true;
}

