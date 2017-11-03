//
//  B_FloorApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_FloorApp.hpp"
void B_FloorApp::setup(){
    BaseApp::setup();
    floorchange = false;
    floor.load("floor1.png");
    floor2.load("floor3.png");
}

//--------------------------------------------------------------
void B_FloorApp::update(){
    BaseApp::update();
    if (floorchange == true) {
        mPosition = ofVec2f(x, y);
        i += ofGetWidth() * 3 / 2 / 30 ;
        j += ofGetHeight() * 3 / 2 / 30;
        mVelocity = ofVec2f(i, j);
        mPosition += mVelocity;
        w = ofGetWidth() * 4 - i * 2;
        h = ofGetHeight() * 4 - j * 2;
    }
    
    if (mPosition.x >= 0 && mPosition.y >= 0) {
        mPosition -= mVelocity;
        
    }}

//--------------------------------------------------------------
void B_FloorApp::draw(){
    BaseApp::draw();
    floor.draw(0, 0, ofGetWidth(), ofGetHeight());
    if (floorchange == true) {
        floor2.draw(mPosition, w, h);
        
    }
}

//--------------------------------------------------------------
void B_FloorApp::keyPressed(int key){
    BaseApp::keyPressed(key);
    if (key == 'f') {
        floorchange = true;
    }
}

//--------------------------------------------------------------
void B_FloorApp::keyReleased(int key){
    BaseApp::keyReleased(key);
}

//--------------------------------------------------------------
void B_FloorApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_FloorApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_FloorApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_FloorApp::changeScene(){
}





