//
//  P_Scene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
#include "P_Scene.hpp"
void P_Scene::setup(){
    ofSetFrameRate(60);
    
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    hTower = false;
    eHouselight = false;
    //ゾウ、イヌ
    elephant.load("elephant.png");
    dog.load("inu.png");
    
    //階層移動
    isMove = false;
    
    town.load("sky.png");
    town2.load("sky.png");
    town3.load("town1.png");
    
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(px, py);
    
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
    
    //Mission2
    isMove = false;
    ofBackground(0, 0, 0);
    
    //Mission3
    
}


//--------------------------------------------------------------
void P_Scene::update(){
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
    if (hTower == true) {
        tower.load("tower.png");
    }
    if (eHouselight == true) {
        houselight.load("houselight.png");
    }
    
    if (isMove == true) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    
    if (mPosition.y >= ofGetHeight()) {
        mPosition -= mVelocity;
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
    
    //Mission3
    
    }

//--------------------------------------------------------------
void P_Scene::draw(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    tower.draw(0, 0, ofGetWidth(), ofGetHeight());
    houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    dog.draw(210, 500, 50, 50);
    elephant.draw(370, 500, 50, 50);
    
    ofSetColor(255);
    
    //階層移動
    town.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
    
    
    //Mission2
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);
    
    //Mission3
    
}

//--------------------------------------------------------------
void P_Scene::keyPressed(int key){
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
    if (key == 'h') {
        hTower = true;
    }
    if (key == 'e') {
        eHouselight = true;
    }
    
    //階層移動
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission2
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission3
    
    
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

