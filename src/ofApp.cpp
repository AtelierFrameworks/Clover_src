#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	Timer.loadFont("MountainsofChristmas.ttf", 200);
	
}

//--------------------------------------------------------------
void ofApp::update() {
	if (isTimer) {
		sec = sec -0.016666;
	}

}

//------------------------------------------

void ofApp::draw(){

	if (min<=0&&sec<=30) {
		ofSetColor(255, 0, 0);
		if (sec<=9.5) {
			time = "0" + ofToString(min, 0) + ":" + "0" + ofToString(sec, 0);
		}
		else {
			time = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
		}
		Timer.drawString(time, (ofGetWidth() / 2) - 150, ofGetHeight() / 2);
	}

	else {
		ofSetColor(255, 255, 255);
		if (sec <=9.5) {
			time = "0" + ofToString(min, 0) + ":" + "0" +ofToString(sec, 0);
		}
		else {
			time = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
		}		
		Timer.drawString(time, (ofGetWidth() / 2) - 150, ofGetHeight() / 2);
	}
	if (sec <= 0.5 && min == 0) {
		
		isTimer = false;
		}
	if (isTimer) {
		if (sec <= 0.5) {
			min--;
			sec = 59;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key=='a') {
		isTimer = false;
		
	}
	if (key=='b') {
		isTimer = true;
	}
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
