#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    challenge_Movie.loadMovie("challenge_Movie.m4v");
    challenge_Movie.play();
}

//--------------------------------------------------------------
void ofApp::update(){
   
    challenge_Movie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xFFFFFF);
    challenge_Movie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
    //ofPixels & pixels = fingersMovie.getPixels();
    //unsigned char * pixels = fingersMovie.getPixels();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
