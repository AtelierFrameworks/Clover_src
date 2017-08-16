//
//  B_BedApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_BedApp.hpp"
void B_BedApp::setup(){
   BaseApp::setup();
}

//--------------------------------------------------------------
void B_BedApp::update(){
    BaseApp::update();
}

//--------------------------------------------------------------
void B_BedApp::draw(){
    ofDrawBitmapString("ofBedApp", ofGetWidth()/2, ofGetHeight()/2);
    BaseApp::draw();
}

//--------------------------------------------------------------
void B_BedApp::keyPressed(int key){
    BaseApp::keyPressed(key);

}

//--------------------------------------------------------------
void B_BedApp::keyReleased(int key){
    BaseApp::keyReleased(key);
}

//--------------------------------------------------------------
void B_BedApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_BedApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_BedApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_BedApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_BedApp::changeScene(){
    BaseScene *newScene;
    switch (getNowScene()) {
        case BaseApp::PRISON:
//            newScene = new P_Scene();
            break;
        case BaseApp::MAGIC:
//            newScene = new M_BedScene();
            break;
        case BaseApp::NONE:
            break;
        default:
            break;
    }
    mScenes.push_back(newScene);
    mScenes[0]->setup();
}



