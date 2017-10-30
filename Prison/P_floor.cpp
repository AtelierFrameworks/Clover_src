//
//  P_floor.cpp
//  
//
//  Created by USER1 on 2017/08/31.
//
//

#include "P_floor.hpp"

void P_floor::setup(){
    move = false;
    floor.load("floor1.png");    }

//--------------------------------------------------------------
void ::update(){
    if (move == true) {
        floor.load("floor2.png");
    }
}

//--------------------------------------------------------------
void P_floor::draw(){
    floor.draw(0, 0, ofGetWidth(), ofGetHeight()); }

//--------------------------------------------------------------
void P_floor::keyPressed(int key){
    if (key = 'f') {
        move = true;
    }
}

//--------------------------------------------------------------
void P_floor::keyReleased(int key){

}

//--------------------------------------------------------------
void P_floor::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_floor::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_floor::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_floor::dragEvent(ofDragInfo dragInfo){
    
}

void P_floor::actionBed(){
    mIsPlayBed = true;
}

