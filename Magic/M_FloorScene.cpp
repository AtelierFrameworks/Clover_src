//
//  M_FloorScene.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/09/07.
//
//

#include "M_FloorScene.hpp"

void M_FloorScene::setup(){
    mVideo = new EventVideo();
    mVideo->setup("Magic/M_mahojin.mp4", OF_LOOP_NONE, CONST::G_M_CHAIR);
    ofAddListener(mVideo->mEndEvent,this,&M_FloorScene::endMovieEvent);
//    mVideo.play();
//    mVideo.pause();
    magic_floor.load("Magic/M_floor.png");
    isPlayChair = false;
}

//--------------------------------------------------------------
void M_FloorScene::update(){
    if(isPlayChair){
        mVideo->update();
    }
}

//--------------------------------------------------------------
void M_FloorScene::draw(){
    magic_floor.draw(0, 0, ofGetWidth(), ofGetHeight());
    if(isPlayChair){
        mVideo->draw(0,0,ofGetWidth(),ofGetHeight());
    }
}

//--------------------------------------------------------------
void M_FloorScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void M_FloorScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void M_FloorScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void M_FloorScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_FloorScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_FloorScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_FloorScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void M_FloorScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void M_FloorScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void M_FloorScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void M_FloorScene::dragEvent(ofDragInfo dragInfo){
    
}

void M_FloorScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    mVideo->stop();
    isPlayChair = false;
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mEndMovieEvent, e_gimmick);
}

void M_FloorScene::actionChair(){
    isPlayChair = true;
    mVideo->play();
}

void M_FloorScene:: exit(){
    ofRemoveListener(mVideo->mEndEvent, this, &M_FloorScene::endMovieEvent);
}

