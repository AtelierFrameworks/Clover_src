//
//  P_BedScene.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/17.
//
//

#include "P_BedScene.hpp"

void P_BedScene::setup(){
     ofSetFrameRate(60);
     ofSetBackgroundColor(0);
    
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    eHouselight = false;
    
   
    mouse.load("nezumi.png");
    horse.load("uma.png");
    bat.load("bat.png");
    pumpkin.load("pumpkin.png");
    town.load("town2.png");
    
    //階層移動
    isMove = false;
    
    town1.load("sky.png");
    town2.load("sky.png");
    town3.load("town2.png");
    
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
    
    moon.load("moon.png");
    cloud.load("black.png");
    
    //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;
}

//--------------------------------------------------------------
void P_BedScene::update(){
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
    
    if (m_py <= 0 && c_px < ofGetWidth() / 2 - 230) {
        c_px += 0.5;
    }
    
    if (m_py > 0) {
        m_px -= 0.25;
        m_py -= 1;
        m2_px += 0.5;
        m2_py += 0.5;
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
void P_BedScene::draw(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    mouse.draw(w / 3 - size / 2, h + length * q - t - v - size /2, size, size);
    horse.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    bat.draw(w / 3 - size / 2, h + length * q - t - v - size / 2, size, size);
    pumpkin.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);

    
    ofSetColor(255);
    
    //階層移動
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
    
    //Mission2
    if(isBat == true){
        bat.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
    if(isPumpkin == true){
        pumpkin.draw(w / 3 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
    
    //太陽月
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);
    
    moon.draw(m_px, m_py, m2_px, m2_py);
    if (m_py <= 0) {
        cloud.draw(c_px, c_py, 450, 450);
    }
    
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
void P_BedScene::keyPressed(int key){
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
void P_BedScene::keyReleased(int key){
    //Mission2
    if(key == 'a'){
        isBat = false;
    }
    if(key == 'p'){
        isPumpkin = false;
    }

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


