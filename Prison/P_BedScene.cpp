//
//  P_BedScene.cpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/31.
//
//

#include "P_BedScene.hpp"
void P_BedScene::setup(){
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.loadMovie("P_bedshadow.mp4");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    
}

//--------------------------------------------------------------
void P_BedScene::update(){
    fingersMovie.update();
    
}

//--------------------------------------------------------------
void P_BedScene::draw(){
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);

   // ofSetColor(0,127,127);
   // ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
}

//--------------------------------------------------------------
void P_BedScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void P_BedScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_BedScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_BedScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_BedScene::dragEvent(ofDragInfo dragInfo){
    
}

void P_BedScene::actionDesk(){
    
}

void P_BedScene::actionChair(){
    
}

void P_BedScene::actionBed(){
    
}

void P_BedScene::actionShelf(){
    
}

