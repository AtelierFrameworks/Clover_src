//
//  B_DeskApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_DeskApp.hpp"
void B_DeskApp::setup(){
    BaseApp::setup();
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    setupMission1();
}

void B_DeskApp::setupMission1(){
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    eHouselight = false;
    //ゾウ、イヌ
    elephant.load("elephant.png");
    dog.load("inu.png");
    bat.load("bat2.png");
    pumpkin.load("pumpkin2.png");
    town.load("town3.png");
    lamp.load("lamp.png");
    pampukin.load("pampukin.png");
    tree.load("tree.png");
    houselight.load("houselight.png");

}

void B_DeskApp::setupStair(){
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
}

void B_DeskApp::setupMission2(){
    //Mission2
    isBat = false;
    isPumpkin = false;
    bat.load("bat.png");
    pumpkin.load("pumpkin.png");
}

void B_DeskApp::setupSun(){
    //太陽月
    isMoved = false;
    Sun.load("sun.png");
    sky.load("sky2.png");
}

void B_DeskApp::setupStar(){
     //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;
}

//--------------------------------------------------------------
void B_DeskApp::update(){
    BaseApp::update();
}

void B_DeskApp::updateMission1(){
    //Mission1
    

}

void B_DeskApp::updateStair(){
    //階層移動
    if (isMove == true) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    
    if (mPosition.y >= ofGetHeight()) {
        mPosition -= mVelocity;
    }

}

void B_DeskApp::updateMission2(){
    

}

void B_DeskApp::updateSun(){
    //太陽月
    if (isMoved) {
        
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
    
    if (isMoved) {
        ny += 1.5;
        size_x -= 0.1;
        size_y -= 0.1;
        color += 0.127;
    }
}

void B_DeskApp::updateStar(){
    //満天の星
    if (mIsKeyPressed) {
        time++;
    }
    else if (mIsKeyPressed) {
        time --;
    }
}

//--------------------------------------------------------------
void B_DeskApp::draw(){
    BaseApp::draw();
}

void B_DeskApp::drawMission1(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    dog.draw(w / 3 - size / 2, h + length * q - t - v - size / 2, size, size);
    elephant.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    bat.draw(w / 3 - size / 2, h + length * q - t - v - size / 2, size, size);
    pumpkin.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    ofSetColor(255);
}

void B_DeskApp::drawStair(){
    //階層移動
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
}

void B_DeskApp::drawMission2(){
    //Mission2
    if(isBat){
        bat.draw(w / 3 * 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
    if(isPumpkin){
        pumpkin.draw(w / 3 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
}

void B_DeskApp::drawSun(){
    //太陽月
    sky.draw(nPosition.x, nPosition.y, ofGetWidth(), ofGetHeight() * 4);
    if(isMoved){
        ofSetColor(130);
    }
    if (isMoved) {
        ofSetColor(color, color, color);
    }
    Sun.draw(nx, ny, size_x, size_y);
}

void B_DeskApp::drawStar(){
    //満天の星
    i = ofGetFrameNum();//frame数
    if (mIsKeyPressed) {
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
void B_DeskApp::keyPressed(int key){
    BaseApp::keyPressed(key);
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
void B_DeskApp::keyReleased(int key){
    BaseApp::keyReleased(key);
    //Mission2
    if(key == 'a'){
        isBat = false;
    }
    if(key == 'p'){
        isPumpkin = false;
    }

}

//--------------------------------------------------------------
void B_DeskApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_DeskApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_DeskApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_DeskApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_DeskApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_DeskApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_DeskApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_DeskApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_DeskApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_DeskApp::endMovie(CONST::E_MOVIE & movie){
    CONST::E_MOVIE e_movie = movie;
    ofNotifyEvent(mMovieEndEvent, e_movie);
}

