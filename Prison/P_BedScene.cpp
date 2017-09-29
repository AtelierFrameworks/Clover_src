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
mIsPlayChair = false;
mIsPlayBed = false;
mIsPlayShelf = false;
ofEnableSmoothing();
mVideo.setup("Prison/P_bedshadow.mp4", OF_LOOP_NONE, CONST::G_P_BED);
ofAddListener(mVideo.mEndEvent,this,&P_BedScene::endMovieEvent);
	//背景
mBackground.load("Prison/P_side.png");

	//ヒビ
	mCrack.setup();
	
  //人影現れて消えるだけ
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    mIsKeyPressed = false;
    ofSetColor(255, 255, 255, 0);
//    shadow.load("Prison/shadow.PNG");
    x = ofRandom(ofGetWidth() - 250);
    y = ofRandom(ofGetHeight() - 400);
    time = -1;
  
	//shadow
  fingersMovie.setLoopState(OF_LOOP_NONE);
  fingersMovie.play();
}

//--------------------------------------------------------------
void P_BedScene::update(){
    if(mIsPlayChair){
        mVideo.update();
    }
    
    //人影(現れて消えるだけ)
    if (!mIsKeyPressed) {
        time++;
    }
    else if(mIsKeyPressed){
        time --;
    }
   
}

//--------------------------------------------------------------
void P_BedScene::draw(){
    //背景
    mBackground.draw(0,0);
	
	//shadow
	if(mIsPlayChair){
		mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	
    //人影(現れて消えるだけ)
	if(mIsPlayShelf){
    i = (int)ofGetFrameNum();//frame数
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
	
	//crack
	if(mIsPlayBed){
		if(P_Crack::getCount() == -1){
			mIsPlayBed = false;
		}else{
			mCrack.draw();
			ofLogNotice() << "crack!" << P_Crack::getCount();
		}
	}
}

//--------------------------------------------------------------
void P_BedScene::keyPressed(int key){
	
}

//--------------------------------------------------------------
void P_BedScene::keyReleased(int key){

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
	mVideo.stop();
	if(!mIsPlayChair){
		CONST::E_GIMMICK e_gimmick = gimmick;
		ofNotifyEvent(mEndMovieEvent,e_gimmick);
	}
	
}

void P_BedScene::actionChair(){
	mIsPlayChair = true;
}

void P_BedScene::actionBed(){
	mIsPlayBed = true;
}

void P_BedScene::actionShelf(){
	mIsPlayShelf = true;
}

