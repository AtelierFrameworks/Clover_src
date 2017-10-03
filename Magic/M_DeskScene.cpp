//
//  M_DeskScene.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/09/07.
//
//

#include "M_DeskScene.hpp"
void M_DeskScene::setup(){
    mIsPlayShelf = false;
    mIsPlayBookShelf = false;
    mIsPrevious = true;
    mSoseki.load("Magic/M_frame.mp4");
    mSoseki.setLoopState(OF_LOOP_NONE);
//    mBookPlayer.load("Magic/M_bookshelf.mp4");
    mBookPlayer.setLoopState(OF_LOOP_NONE);
    mBookPlayer.setVolume(0);
    setupBat();
    setupCurse();
    setupStair();
}

void M_DeskScene::setupStair(){
    magic_kabe.load("Magic/M_front.png");
    magic_kabe2=&magic_kabe;
    magic_kabe3=&magic_kabe;
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(stairPx, stairPy);
    isMove = false;
}

void M_DeskScene::setupBat(){
    //Movie1.load("M_bat1.mp4");
    //Movie1.play();
    for (int i = 0; i < BATCOUNT; i++) {
        separate = i % 2;
        bats[i].setup(separate);
    }
    BatSound.load("Magic/batSound.mp3");
    BatSound.setLoop(true);
}

void M_DeskScene::setupCurse(){
    // setup pointsprite texture
    // NOTES: the texture size must be Power of Two,
    // and turn off arb texture option while loading
    out = 0;
    ofDisableArbTex();
    sprite.load("Magic/sample11.png");
    ofEnableArbTex();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    sys.setup();
    
    group.setup(sys);
    group.setColor(ofxSPK::RangeC(ofColor(255, 20), ofColor(255, 40)),
                   ofxSPK::RangeC(ofColor(0, 0 ), ofColor(255, 0)));
    group.setLifeTime(1, 10);//粒子が発生している時間の範囲(最小時間,最大時間)
    group.setFriction(0.1);
    group.setSize(0, ofxSPK::RangeF(50, 200));//粒子の最大の大きさ
    group.setMass(0.1, 0.5);//MAXを高くすると波状がくっきりする?
}

//--------------------------------------------------------------
void M_DeskScene::update(){
    
    if(mIsPlayShelf){
        updateBat();
        updateCurse();
        mSoseki.update();
    }
//    if(mIsPlayBookShelf){
//        updateBookShelf();
//    }
    
    if (isMove) {
        mPosition.y += 20;
    }

}

void M_DeskScene::updateBat(){
    int outWindowCount = 0;
    for (int i = 0; i < BATCOUNT; i++) {
        bats[i].update();
        if(bats[i].Position.y < 0){
            outWindowCount++;
        }
    }
    if(outWindowCount == BATCOUNT){
        BatSound.stop();
        out = 1;
    }
}

void M_DeskScene::updateCurse(){
    check = (int)ofGetElapsedTimef() % 3;
    group.setGravity(ofVec3f(0, -100, 0));
    
    group.reserve(particle);//粒子の発生する量
    if (out == 1) {
        particle -= 15;//消える速さ
        if (particle == 0) {//エラー対策
            out = 0;
            mIsPlayShelf = false;
            for (Bat bat:bats) {
                bat.reset();
            }
            ofNotifyEvent(mShelfEvent, mIsPlayShelf );
        }
    }
    
    if (ofGetElapsedTimef() < 50) {
        range = ofGetElapsedTimef() * 10;
    }
    
//    group.emitRandom(10, ofVec3f(150*sin(15*ofGetElapsedTimef())+ofGetWidth()/2,ofGetHeight()/5*4+300));
     group.emitRandom(10, ofVec3f(150*sin(15*ofGetElapsedTimef())+ofGetWidth()/2,ofGetHeight()/5*4+200));
    sys.update();
}

void M_DeskScene::updateBookShelf(){
    mBookPlayer.update();
    // check end the movie
//    if((mBookPlayer.getCurrentFrame() == mBookPlayer.getTotalNumFrames() && !mIsPrevious) || (mBookPlayer.getCurrentFrame() == 0 && mIsPrevious)){
//        mIsPlayBookShelf = false;
//        mBookPlayer.stop();
//    }
}

//--------------------------------------------------------------
void M_DeskScene::draw(){
    if(isMove){
        drawWall();
    }else{
         magic_kabe.draw(mPosition.x,mPosition.y,ofGetWidth(),ofGetHeight());
    }
    
    mSoseki.draw(ofGetWidth()-600, 300, 400, 600);
    
    if(mIsPlayShelf){
        drawBat();
        drawCurse();
    }
   }


void M_DeskScene::drawBat(){
    for (int i = 0; i < BATCOUNT; i++) {
        bats[i].draw();
    }
}

void M_DeskScene::drawCurse(){
    ofEnableBlendMode(OF_BLENDMODE_ADD/*ALPHA  ADD*/);
    sprite.bind();
    ofEnablePointSprites();
    sys.draw();
    ofDisablePointSprites();
    sprite.unbind();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

void M_DeskScene::drawWall(){
    magic_kabe.draw(mPosition.x,mPosition.y,ofGetWidth(),ofGetHeight());
    magic_kabe2->draw(mPosition.x , mPosition.y-1000, ofGetWidth(), ofGetHeight());
    magic_kabe3->draw(mPosition.x,mPosition.y-2000, ofGetWidth(), ofGetHeight());
    
    if (mPosition.y == 2000) {
        mPosition.y = 0;
        isMove = false;
    }
}

//--------------------------------------------------------------
void M_DeskScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void M_DeskScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void M_DeskScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void M_DeskScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_DeskScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_DeskScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void M_DeskScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void M_DeskScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void M_DeskScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void M_DeskScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void M_DeskScene::dragEvent(ofDragInfo dragInfo){
    
}

void M_DeskScene::endMovieEvent(CONST::E_GIMMICK & gimmick){
   
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mEndMovieEvent, e_gimmick);
}

void M_DeskScene::actionShelf(){
    if(!mIsPlayShelf){
        for (int i = 0;i < BATCOUNT;i++) {
            bats[i].reset();
        }
        mIsPlayShelf = true;
        BatSound.play();
        out = 0;
        particle = 3000;
        mSoseki.play();
    }
}

void M_DeskScene::endShelf(){
     out = 1;
}

void M_DeskScene::actionEndMovie(){

}

void M_DeskScene::actionBed(){

}

void M_DeskScene::actionBedNext(){
    isMove = true;
}

void M_DeskScene::actionStandBed(){
    isMove = false;
}



