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
     ofSetBackgroundColor(0);
    
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    eHouselight = false;
    
    rabbit.load("usa.png");
    town.load("town3.png");
    
    //階層移動
    isMove = false;
    
    town1.load("sky.png");
    town2.load("sky.png");
    town3.load("town3.png");
    
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(px, py);
    
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
    
    //Mission2
    isBat = false;
    isPumpkin = false;
    
    //太陽月
    isMoved = false;
    Sun.load("sun.png");
    
    //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;

}

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
    
    //階層移動
    if (isMove == true) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    
    if (mPosition.y >= ofGetHeight()) {
        mPosition -= mVelocity;
    }

    //Mission2
    if(isBat == true){
        bat.load("bat.png");
    }
    
    if(isPumpkin == true){
        pumpkin.load("pumpkin.png");
    }

    
    
    //太陽月
    if (isMoved == true) {
        sky.load("sky2.png");
        x = 0;
        y = 0;
        nPosition = ofVec2f(x, y);
        wx = 0;
        wy = 0;
        nVelocity = ofVec2f(wx, wy);
        
        nVelocity.y += 0.01;
        nPosition -= nVelocity;
    }
    
    if (nPosition.y <= -ofGetHeight() * 3) {
        nPosition += nVelocity;
    }
    
    if (isMoved == true) {
        ny += 1.5;
        size_x -= 0.1;
        size_y -= 0.1;
        color += 0.127;
    }
    
    //満天の星
    if (mIsKeyPressed == false) {
        time++;
    }
    else if (mIsKeyPressed == true) {
        time --;
    }


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
    
    //階層移動
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
    
    //Mission2
    if(isBat == true){
        bat.draw(50, 500, 100, 100);
    }
    if(isPumpkin == true){
        pumpkin.draw(150, 500, 100, 100);
    }

    
    //太陽月
    sky.draw(nPosition.x, nPosition.y, ofGetWidth(), ofGetHeight() * 4);
    if(isMoved == false){
        ofSetColor(130);
    }
    if (isMoved == true) {
        ofSetColor(color, color, color);
    }
    Sun.draw(nx, ny, size_x, size_y);
    
    //満天の星
    i = ofGetFrameNum();//frame数
    if (mIsKeyPressed == true) {
        if (i - time < 256*2-1) {
            ofSetColor(255, 255, 255, (i - time)/2);
        }
        
        
        if (i == 3000) {
            i = i / 5;
        }
        img.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
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
    
    //階層移動
    if (key == 'b') {
        isMove = true;
    }

    //Mission2
    if(key == 'a'){
        isBat = true;
    }
    if(key == 'p'){
        isPumpkin = true;
    }

    
    //太陽月
    if (key == 'b') {
        isMoved = true;
    }
    
    //満天の星
    if (key == 's') {
        mIsKeyPressed = true;
    }

}

//--------------------------------------------------------------
void P_DeskScene::keyReleased(int key){
    //Mission2
    if(key == 'a'){
        isBat = false;
    }
    if(key == 'p'){
        isPumpkin = false;
    }

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
