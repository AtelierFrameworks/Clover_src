//
//  M_BedScene.cpp
//  Atelier_Room
//
//  Created by √ä¬±‚Ä†‚Ä∞‚àè√§√Å‚àÇ√¶‚Ä∞œÄ√â on 2017/06/11.
//
//
#include "M_BedScene.hpp"
void M_BedScene::setup(){
    isAction = false;
    countTime = 0;
    isShowFont = false;
    magic_kabe.load("Magic/M_front.png");
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    for (int i = 0; i < 20;i++) {
        letters[i].setup(-100, -100, 0);
    }
}

//--------------------------------------------------------------
void M_BedScene::update(){
    updateFont();
    
}

void M_BedScene::updateFont(){
    countTime++;
    if (countTime == 600) {
        countTime = 0;
    }
    int count = countTime % 600;
    
    if(mSimpleHands.size()){
        isShowFont = true;
        int modCount = count % 30;
        if (modCount == 0) {
            //フォント生成の条件
            int letterIndex = count /30 ;
            
            //leapから撮ります。
            float x = mSimpleHands.at(0).handPos.x;
            float y = mSimpleHands.at(0).handPos.y;
            letters[letterIndex].setup(x, y, count);
        }else{
            isShowFont = false;
        }
    
    for (int i=0; i < 20; i++) {
        letters[i].update(count);
    }
    }
}




//--------------------------------------------------------------
void M_BedScene::draw(){
    magic_kabe.draw(0,0,ofGetWidth(), ofGetHeight());
    drawFont();
//    mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void M_BedScene::drawFont(){
    for (int i = 0; i < 20; i++) {
        letters[i].draw();
    }
}

//--------------------------------------------------------------
void M_BedScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void M_BedScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void M_BedScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void M_BedScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void M_BedScene::dragEvent(ofDragInfo dragInfo){
    
}

void M_BedScene::startBed(){
    
}

void M_BedScene::endBed(){
    
}
void M_BedScene::actionBed(){
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,30);
    if(!isAction){
        isAction= true;
        mVideo.play();
    }
}
void M_BedScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    mVideo.stop();
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mEndMovieEvent, e_gimmick);
}

