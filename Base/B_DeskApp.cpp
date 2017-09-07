//
//  B_DeskApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_DeskApp.hpp"
void B_DeskApp::setup(){
  
//    mCam.setOrientation(ofPoint(-20, 0, 0));
//
    BaseApp::setup();
}

//--------------------------------------------------------------
void B_DeskApp::update(){
    BaseApp::update();
}

//--------------------------------------------------------------
void B_DeskApp::draw(){
//    if(simpleHands.size() ){
//        mCam.begin();
//        ofVec2f p = simpleHands.at(0).fingers.at(INDEX).pos;
//        ofSetColor(0);
//        ofDrawSphere( simpleHands.at(0).fingers.at(INDEX).pos, 10);
//        mCam.end();
//    }
    BaseApp::draw();
}

//--------------------------------------------------------------
void B_DeskApp::keyPressed(int key){
    BaseApp::keyPressed(key);
    
}

//--------------------------------------------------------------
void B_DeskApp::keyReleased(int key){
    BaseApp::keyReleased(key);
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

void B_DeskApp::changeScene(){
    BaseScene *newScene;
    switch (getNowScene()) {
        case CONST::PRISON:
//            newScene = new P_Scene();
            break;
        case CONST::MAGIC:
//            newScene = new M_BedScene();
            break;
        case CONST::NONE:
              mScenes.clear();
            break;
        default:
            break;
    }
    mScenes.push_back(newScene);
    mScenes[0]->setup();
}


