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
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.loadMovie("yuka.mov");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    //背景
    myImage.loadImage("P_floor.png");
}

//--------------------------------------------------------------
void P_floor::update(){
    fingersMovie.update();
    
}

//--------------------------------------------------------------
void P_floor::draw(){
    //背景
    myImage.draw(0,0);
    //ひび割れ
    ofSetColor(0,127,127);
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
    
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

void P_floor::actionDesk(){
    
}

void P_floor::actionChair(){
    
}

void P_floor::actionBed(){
    
}

void P_floor::actionShelf(){
    
}


