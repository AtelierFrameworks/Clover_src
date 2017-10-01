//
//  M_BedScene.cpp
//  Atelier_Room
//
//  Created by √ä¬±‚Ä†‚Ä∞‚àè√§√Å‚àÇ√¶‚Ä∞œÄ√â on 2017/06/11.
//
//
#include "M_BedScene.hpp"
void M_BedScene::setup(){
    isAction = false;
    countTime = 0;
    isShowFont = false;
    mIsPlayBookShelf = false;
    mIsPrevious = false;
    mVideo.setup("Magic/M_bookshelf.mp4", OF_LOOP_NONE, CONST::G_M_BED);
    ofAddListener(mVideo.mEndEvent, this, &M_BedScene::endMovieEvent);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    mCamera.setOrientation(ofPoint(-20, 0, 0));
    for (int i = 0; i < LETTER_COUNT;i++) {
        letters[i].setup(-1000, -1000, 0);
    }
    mIsPlayBed = false;
    setupStair();
}

void M_BedScene::setupStair(){
    magic_kabe.load("Magic/M_fullBook.png");
    magic_kabe2.load("Magic/M_fullBook.png");
    magic_kabe3.load("Magic/M_fullBook.png");
    
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(stairPx, stairPy);
    isMove = false;
}


//--------------------------------------------------------------
void M_BedScene::update(){
    updateFont();
    if(mIsPlayBookShelf){
        updateBookShelf();
    }
    if (isMove) {
        mPosition.y +=  20;
//        if(
    }
}

void M_BedScene::updateBookShelf(){
    mVideo.update();

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
    if(isMove){
        drawWall();
    }else{
        mVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    drawFont();
}

void M_BedScene::drawFont(){
    mCamera.begin();
    for (int i = 0; i < LETTER_COUNT; i++) {
        letters[i].draw();
    }
    mCamera.end();
}

void M_BedScene::drawWall(){
    magic_kabe.draw(mPosition.x,mPosition.y,ofGetWidth(),ofGetHeight());
    magic_kabe2.draw(mPosition.x , mPosition.y-1000, ofGetWidth(), ofGetHeight());
    magic_kabe3.draw(mPosition.x,mPosition.y-2000, ofGetWidth(), ofGetHeight());
    
    if (mPosition.y == 2000) {
        mPosition.y = 0;
        isMove = false;
        mIsPlayBed = false;
    }
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


void M_BedScene::actionBed(){
    mIsPlayBed = true;
    if(!mIsPrevious){
        mIsPrevious = !mIsPrevious; 
        mVideo.setSpeed(1.1);
        mVideo.play();
        mIsPlayBookShelf = true;
    }else{
        bool a = true;
        ofNotifyEvent(mStairEvent, a);
    }
}

void M_BedScene::actionBedNext(){
    if(!isMove){
        isMove = true;
    }
}

void M_BedScene::actionStandBed(){
    isMove = false;
}
void M_BedScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
    if(mIsPlayBookShelf){
        mIsPlayBookShelf = false;
    }
    mVideo.stop();
    if(mIsPlayBed){
        CONST::E_GIMMICK e_gimmick = gimmick;
        ofNotifyEvent(mEndMovieEvent, e_gimmick);
    }
}

void M_BedScene::actionEndMovie(){
    mIsPlayBookShelf = true;
    if(mIsPrevious){
        mVideo.setFrame(mVideo.getTotalNumFrames());
        mVideo.setSpeed(-2);
    }else{
        mVideo.setFrame(0);
        mVideo.setSpeed(1.1);
    }
    mIsPrevious = !mIsPrevious;
    mVideo.play();
}


