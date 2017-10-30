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
    drawline1 = false;
    drawline2 = false;
    drawline3 = false;
    drawline4 = false;
    drawline5 = false;
    
    ofBackground(0, 0, 0);
    
    //満天の星
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;

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
    
    //太陽月
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
    
    
    //満天の星
    if (mIsKeyPressed == false) {
        time++;
    }
    else if (mIsKeyPressed == true) {
        time --;
    }

    
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
    if(isBat == true){
        bat.draw(50, 500, 100, 100);
    }
    if(isPumpkin == true){
        pumpkin.draw(150, 500, 100, 100);
    }
    
    //太陽月
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);
    
    //Mission3
    ofSetColor(255, 0, 0);
    ofDrawCircle(w, h, 5);
    ofSetColor(120);
    ofDrawCircle(w - 200 * p, h + 200 * q, 5);
    ofDrawCircle(w + 100, h + 200 * q - t - v, 5);
    ofDrawCircle(w - 100, h + 200 * q - t - v, 5);
    ofDrawCircle(w + 200 * p, h + 200 * q, 5);
    
    
    ofSetColor(255, 255, 0);
    
    if(drawline1 == true){
        //ofSetColor(255, 255, 0);
        ofDrawLine(w, h, w - 200 * p, h + 200 * q);
    }
    if(drawline2 == true){
        //ofSetColor(255, 255, 0);
        ofDrawLine(w - 200 * p, h + 200 * q, w + 100, h + 200 * q - t - v);
    }
    if(drawline3 == true){
        //ofSetColor(255, 255, 0);
        ofDrawLine(w + 100, h + 200 * q - t - v, w - 100, h + 200 * q - t - v);
    }
    if(drawline4 == true){
        //ofSetColor(255, 255, 0);
        ofDrawLine(w - 100, h + 200 * q - t - v, w + 200 * p, h + 200 * q);
    }
    if(drawline5 == true){
        //ofSetColor(255, 255, 0);
        ofDrawLine(w + 200 * p, h + 200 * q, w, h);
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
    
    //太陽月
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission3
    if(key =='1'){
        drawline1 = true;
    }
    if(key =='2'){
        drawline2 = true;
    }
    
    if(key =='3'){
        drawline3 = true;
    }
    
    if(key =='4'){
        drawline4 = true;
    }
    
    if(key =='5'){
        drawline5 = true;
    }

    
    //満天の星
    if (key == 's') {
        mIsKeyPressed = true;
    }
    
    
}

//--------------------------------------------------------------
void P_Scene::keyReleased(int key){
    //Mission2
    if(key == 'a'){
        isBat = false;
    }
    if(key == 'p'){
        isPumpkin = false;
    }

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

