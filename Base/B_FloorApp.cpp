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
    move = false;
    floor.load("floor1.png");
}

//--------------------------------------------------------------
void B_FloorApp::update(){
    BaseApp::update();
    if (move == true) {
//        floor.load("floor2.png");
    }
}

//--------------------------------------------------------------
void B_FloorApp::draw(){
    BaseApp::draw();
    floor.draw(0, 0, ofGetWidth(), ofGetHeight()); 
}

//--------------------------------------------------------------
void B_FloorApp::keyPressed(int key){
    BaseApp::keyPressed(key);
    if (key == 'f') {
        move = true;
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

void B_FloorApp::endMovie(CONST::E_MOVIE & movie){
    CONST::E_MOVIE e_movie = movie;
    ofNotifyEvent(mMovieEndEvent, e_movie);
}




