//
//  P_BedScene.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/17.
//
//

#include "P_BedScene.hpp"

void P_BedScene::setup(){
ofBackground(0,0,0);
ofSetVerticalSync(true);
frameByframe = false;
ofEnableSmoothing();
mVideo.setup("P_bedshadow.mp4", OF_LOOP_NONE, CONST::G_P_BED);
ofAddListener(mVideo.mEndEvent,this,&P_BedScene::endMovieEvent);

//背景
myImage.load("P_side.png");

//ヒビ
ofBackground(0,0,0);
ofSetVerticalSync(true);
ofEnableSmoothing();
fingersMovie.load("hibi.mov");
fingersMovie.setLoopState(OF_LOOP_NONE);
fingersMovie.play();
	
  //人影現れて消えるだけ
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    mIsKeyPressed = false;
    ofSetColor(255, 255, 255, 0);
    shadow.load("shadow.PNG");
    x = ofRandom(ofGetWidth() - 250);
    y = ofRandom(ofGetHeight() - 400);
    time = -1;
  
//shadow
	shadow.load("shadow.PNG");
  fingersMovie.setLoopState(OF_LOOP_NONE);
  fingersMovie.play();
}

//--------------------------------------------------------------
void P_BedScene::update(){
    if(isAction){
        mVideo.update();
    }
    
    //人影(現れて消えるだけ)
    　　if (mIsKeyPressed == false) {
        time++;
    }
    else if(mIsKeyPressed == true){
        time -= 1;
    }
   
}

//--------------------------------------------------------------
void P_BedScene::draw(){
    if(isAction){
        mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }    
    //背景
    myImage.draw(0,0);
    
    //人影(現れて消えるだけ)
    　　i = ofGetFrameNum();//frame数
    if (mIsKeyPressed == true) {
        if (i - time < 256) {
            ofSetColor(255, 255, 255, i - time);
        }
        else if (i - time < 511) {
            j = i - time - 255;
            ofSetColor(255, 255, 255, 255 - 2 * j);
        }
        if (i == 3000) {
            i = i / 5;
        }
    }
    shadow.draw(x, y, 250, 400);
    
    //ヒビ
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
	
	i = (int)ofGetFrameNum();
	if (i < 256) {
		ofSetColor(255, 255, 255, i);
		shadow.draw(800, 300, 250, 400);
	}else if (i < 510) {
		j = i - 255;
		ofSetColor(255, 255, 255, 255 - 2 * j);
		shadow.draw(800, 300, 250, 400);
	}
}

//--------------------------------------------------------------
void P_BedScene::keyPressed(int key){
    if (key == 's') {
        mIsKeyPressed = true;
    }
    
}

//--------------------------------------------------------------
void P_BedScene::keyReleased(int key){
    if (key == 's') {
        mIsKeyPressed = false;
    }
}

//--------------------------------------------------------------
void P_BedScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_BedScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_BedScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_BedScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_BedScene::dragEvent(ofDragInfo dragInfo){
    
}


void P_BedScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    CONST::E_GIMMICK e_gimmick = gimmick;
    mVideo.stop();
    ofRemoveListener(mVideo.mEndEvent, this,&P_BedScene::endMovieEvent);
    ofNotifyEvent(mEndMovieEvent,e_gimmick);
}


