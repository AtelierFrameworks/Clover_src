#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	moon.load("moon.png");
	cloud.load("black.png");
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (m_py <= 0 && c_px < ofGetWidth() / 2 - 230) {
		c_px += 0.5;
	}
	
	if (m_py > 0) {
		m_px -= 0.25;
		m_py -= 1;
		m2_px += 0.5;
		m2_py += 0.5;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	moon.draw(m_px, m_py, m2_px, m2_py);
	if (m_py <= 0) {
		cloud.draw(c_px, c_py, 450, 450);
	}

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
