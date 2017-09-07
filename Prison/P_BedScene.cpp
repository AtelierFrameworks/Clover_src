//
//  P_BedScene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/17.
//
//

#include "P_BedScene.hpp"
void P_BedScene::setup(){
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.load("P_bedshadow.mp4");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    
    //背景
    myImage.load("P_side.png");
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
    
    //背景
    myImage.draw(0,0);

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


