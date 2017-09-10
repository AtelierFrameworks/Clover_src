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
    mVideo.setup("P_bedshadow.mp4", OF_LOOP_NONE, CONST::A_CURTAIN);
    
    //背景
    myImage.load("P_side.png");
    
    
    
    //ヒビ
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.loadMovie("hibi.mov");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
}

//--------------------------------------------------------------
void P_BedScene::update(){
    if(isAction){
        mVideo.update();
    }
    
    //ヒビ
    fingersMovie.update();
}

//--------------------------------------------------------------
void P_BedScene::draw(){
    if(isAction){
        mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    //背景
    myImage.draw(0,0);
    
    //ヒビ
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);


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
void P_BedScene::endMovieEvent(CONST::E_APP & App){
    CONST::E_APP e_app = CONST::A_BED;
    mVideo.stop();
    ofNotifyEvent(mEndMovieEvent,e_app);
    
}


