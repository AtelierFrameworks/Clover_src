//
//  M_Scene.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/17.
//
//

#include "M_Scene.hpp"
#include "ofxSPK.h"

//spk
ofxSPK::System sys;
ofxSPK::Group group;
ofImage sprite;
ofxSPK::Modifier rot;

void M_Scene::setup(){
    setupStair();
    setupClock();
    mIsActionShelf = false;
   
}

void M_Scene::setupStair(){
    magic_kabe.load("Magic/M_front.png");
    magic_kabe2.load("Magic/M_front.png");
    magic_kabe3.load("Magic/M_front.png");
    
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(stairPx, stairPy);
    isMove = false;
}

void M_Scene::setupClock(){
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //画像データの読込み
    //frameImage.load("M_frame.jpg");
    //JoImage.load("20.jpg");
    ClockImage.load("Magic/M_clock.png");
    
    BellSound.load("Magic/Bell Sound.mp3");
    //BellSound.setLoop(true);
    
    ofSetLineWidth(2);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void M_Scene::update(){
    updateClock();
    if (isMove) {
        mPosition.y += 20;
    }
}

void M_Scene::updateClock(){
    centerx = 595;
    centery = 240;
    needleLx = centerx + 25 * sin(ofGetElapsedTimef() / 4.0);
    needleLy = centery - 25 * cos(ofGetElapsedTimef() / 4.0);
    needleSx = centerx + 15 * sin(ofGetElapsedTimef() / 48.0);
    needleSy = centery - 15 * cos(ofGetElapsedTimef() / 48.0);
}

//--------------------------------------------------------------
void M_Scene::draw(){
    ofSetColor(255, 255, 255);
    if(isMove){
        drawWall();

    }else{
         magic_kabe.draw(0,0,ofGetWidth(),ofGetHeight());
    }
        drawClock();
}

void M_Scene::drawWall(){
        magic_kabe.draw(mPosition.x,mPosition.y,ofGetWidth(),ofGetHeight());
        magic_kabe2.draw(mPosition.x , mPosition.y-1000, ofGetWidth(), ofGetHeight());
        magic_kabe3.draw(mPosition.x,mPosition.y-2000, ofGetWidth(), ofGetHeight());
        
        if (mPosition.y == 2000) {
            mPosition.y = 0;
            isMove = false;
        }
}

void M_Scene::drawClock(){
    //色の設定
    //読み込んだ画像データを画面に描画
    //frameImage.draw(20, 20,400,600);
    //JoImage.draw(60, 60, 320, 520);
//    ClockImage.draw(500, 30, 200, 300);
       ClockImage.draw(500, 150, 200, 300);
    ofSetColor(0, 0, 0);
    ofDrawLine(centerx, centery, needleLx, needleLy);
    ofDrawLine(centerx, centery, needleSx, needleSy);
    if (cos(ofGetElapsedTimef() / 48)==1) {
        BellSound.play();
    }
}

//--------------------------------------------------------------
void M_Scene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void M_Scene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void M_Scene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void M_Scene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_Scene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_Scene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_Scene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void M_Scene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void M_Scene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void M_Scene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void M_Scene::dragEvent(ofDragInfo dragInfo){
    
}

void M_Scene::actionDesk(){
    
}

void M_Scene::actionChair(){
    
}

void M_Scene::actionBed(){
    isMove = true;
}

void M_Scene::actionShelf(){
    
}

void M_Scene::actionStandBed(){
    isMove = false;
}

