//
//  M_BedScene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
#include "M_BedScene.hpp"
void M_BedScene::setup(){
    isAction = false;
    mVideo.setup("mahojin.mp4", OF_LOOP_NONE, CONST::A_BED);
    ofAddListener(mVideo.mEndEvent,this,&M_BedScene::endMovieEvent);
}

//--------------------------------------------------------------
void M_BedScene::update(){
    if(isAction){
    mVideo.update();
    }
}

//--------------------------------------------------------------
void M_BedScene::draw(){
    if(isAction){
        mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
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
void M_BedScene::endMovieEvent(CONST::E_APP & App){
    CONST::E_APP e_app = CONST::A_BED;
    mVideo.stop();
    ofNotifyEvent(mEndMovieEvent,e_app);
    
}

