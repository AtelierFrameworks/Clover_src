//
//  P_DeskScene.cpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/21.
//
//

#include "P_DeskScene.hpp"

void P_DeskScene::setup(){
    ofSetFrameRate(60);
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    eHouselight = false;
    
    rabbit.load("usa.png");
    town.load("town3.png");
    
    //Mission2
    isMove = false;
    ofBackground(0, 0, 0);
    Sun.load("sun.png")}

//--------------------------------------------------------------
void P_DeskScene::update(){
    //Mission1
    if (mLamp == true) {
        lamp.load("lamp.png");
    }
    if (rPampukin == true) {
        pampukin.load("pampukin.png");
    }
    if (dTree == true) {
        tree.load("tree.png");
    }
    if (eHouselight == true) {
        houselight.load("houselight.png");
    }
    
    //Mission2
    if (isMove == true) {
        sky.load("sky2.png");
        px = 0;
        py = 0;
        mPosition = ofVec2f(px, py);
        vx = 0;
        vy = 0;
        mVelocity = ofVec2f(vx, vy);
        
        mVelocity.y += 0.01;
        mPosition -= mVelocity;
    }
    
    if (mPosition.y <= -ofGetHeight() * 3) {
        mPosition += mVelocity;
    }
    
    if (isMove == true) {
        ny += 1.5;
        size_x -= 0.1;
        size_y -= 0.1;
        color += 0.127;
    }
    
    //Mission3

}

//--------------------------------------------------------------
void P_DeskScene::draw(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    rabbit.draw(130, 500, 50, 50);
    
    ofSetColor(255);
    
    //Mission2
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);
    if(isMove == false){
        ofSetColor(130);
    }
    if (isMove == true) {
        ofSetColor(color, color, color);
    }
    Sun.draw(nx, ny, size_x, size_y);
    
    //Mission3
    
    
   }


//--------------------------------------------------------------
void P_DeskScene::keyPressed(int key){
    //Mission1
    if (key == 'm') {
        mLamp = true;
    }
    if (key == 'r') {
        rPampukin = true;
    }
    if (key == 'd') {
        dTree = true;
    }
    if (key == 'e') {
        eHouselight = true;
    }
    
    //Mission2
    if (key == 'b') {
        isMove = true;
    }
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
}

void P_DeskScene::actionChair(){
    mIsPlayChair = true;
    mySound.play();
}
