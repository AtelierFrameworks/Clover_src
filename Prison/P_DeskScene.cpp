//
//  P_DeskScene.cpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/21.
//
//

#include "P_DeskScene.hpp"

void P_DeskScene::setup(){
    //背景
    myImage.load("P_side.png");
    
    //人影
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.load("P_deskshadow.mp4");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    mySound.load("kodomo.wav");
    mySound.setLoop(false);
    mySound.play();
    mySound.setVolume(0.5);
    
    //笑い声
    ofBackground(0,0,0);
    frameByframe = false;
    mySound.load("koe.wav");
    mySound.setLoop(false);
    mySound.play();
    mySound.setVolume(0.5);

    //壁のひび
    ofBackground(0,0,0);
    frameByframe = false;
    fingersMovie.load("hibi.mov");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    
}

//--------------------------------------------------------------
void P_DeskScene::update(){
    fingersMovie.update();
//  ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void P_DeskScene::draw(){
    //ofSetColor(0,127,127);
    //ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    //ËÉåÊôØ
    myImage.draw(0,0);
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
}

//--------------------------------------------------------------
void P_DeskScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void P_DeskScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_DeskScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_DeskScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_DeskScene::dragEvent(ofDragInfo dragInfo){
    
}
