#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //各自のシーンにP_SceneかM_Sceneか置き換える
    mScenes.clear();
    mScenes.push_back(*new M_Scene());
    mScenes.at(0).setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    mScenes.at(0).update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    mScenes.at(0).draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mScenes.at(0).keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    mScenes.at(0).keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mScenes.at(0).mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mScenes.at(0).mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mScenes.at(0).mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mScenes.at(0).mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    mScenes.at(0).mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    mScenes.at(0).mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    mScenes.at(0).windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    mScenes.at(0).gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    mScenes.at(0).dragEvent(dragInfo);
}
