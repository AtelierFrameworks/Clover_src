//
//  M_BedScene.cpp
//  Atelier_Room
//
//  Created by √ä¬±‚Ä†‚Ä∞‚àè√§√Å‚àÇ√¶‚Ä∞œÄ√â on 2017/06/11.
//
//
#include "M_BedScene.hpp"
void M_BedScene::setup(){
    ofSetFullscreen(true);
    isAction = false;
    countTime = 0;
    isShowFont = false;
    mIsPlayBookShelf = false;
    mIsPrevious = false;
    magic_kabe.load("Magic/M_front.png");
    mBookPlayer.load("Magic/M_Bookshelf.mp4");
    mBookPlayer.setLoopState(OF_LOOP_NONE);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    mCamera.setOrientation(ofPoint(-20, 0, 0));
    for (int i = 0; i < LETTER_COUNT;i++) {
        letters[i].setup(-1000, -1000, 0);
    }
}

//--------------------------------------------------------------
void M_BedScene::update(){
    updateFont();
    if(mIsPlayBookShelf){
        mBookPlayer.update();
        // check end the movie
        if((mBookPlayer.getCurrentFrame() == mBookPlayer.getTotalNumFrames() && !mIsPrevious) || (mBookPlayer.getCurrentFrame() == 1 && mIsPrevious)){
            mIsPlayBookShelf = false;
            mBookPlayer.stop();
        }
    }
}

void M_BedScene::updateFont(){
    countTime++;
    if (countTime == 300) {
        countTime = 0;
    }
    int count = countTime % 300;
    
    if(mSimpleHands.size()){
        int modCount = count % 15;
        if (modCount == 0) {
            //フォント生成の条件
            int letterIndex = count /15 ;
            
            //leapからとります。
            float x = mSimpleHands.at(0).handPos.x;
            float y = mSimpleHands.at(0).handPos.y;
            letters[letterIndex].setup(x, y, count);
        }
    }
    for (int i=0; i < LETTER_COUNT; i++) {
        letters[i].update(count);
    }

}




//--------------------------------------------------------------
void M_BedScene::draw(){
    ofSetColor(255);
    magic_kabe.draw(0,0,ofGetWidth(), ofGetHeight());
    mVideo.draw(0, 0, 300, ofGetHeight());
    drawFont();
}

void M_BedScene::drawFont(){
    mCamera.begin();
    for (int i = 0; i < LETTER_COUNT; i++) {
        letters[i].draw();
    }
    mCamera.end();
}

//--------------------------------------------------------------
void M_BedScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void M_BedScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void M_BedScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void M_BedScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void M_BedScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void M_BedScene::dragEvent(ofDragInfo dragInfo){
    
}

void M_BedScene::startBed(){
    
}

void M_BedScene::endBed(){
    
}

void M_BedScene::actionBed(){
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,30);
    if(!isAction){
        isAction= true;
        mVideo.play();
    }
}
void M_BedScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    mVideo.stop();
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mEndMovieEvent, e_gimmick);
}

void M_BedScene::actionEndMovie(){
    mIsPlayBookShelf = true;
    if(mBookPlayer.getCurrentFrame() == mBookPlayer.getTotalNumFrames()){
        mBookPlayer.previousFrame();
        mIsPrevious = true;
    }
    mBookPlayer.play();
}


