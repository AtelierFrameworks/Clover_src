//
//  P_DeskScene.cpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/21.
//
//

#include "P_DeskScene.hpp"

void P_DeskScene::setup(){
    //背景
    mBackground.load("Prison/P_side.png");
    gIsKeyPressed = false;
    lIsKeyPressed = false;
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    mShadowMovie.load("Prison/P_deskshadow.mp4");
    mShadowMovie.setLoopState(OF_LOOP_NONE);
    mShadowMovie.play();
    mIsPlayChair = false;
    
    //人影
    
    mySound.load("Prison/kodomo.wav");
    mySound.setLoop(false);
//        mySound.play();
//        mySound.setVolume(0.5);
    
    
    
//    //笑い声
//    if(lIsKeyPressed == true){
//        ofBackground(0,0,0);
//        ofSetVerticalSync(true);
//        frameByframe = false;
//        ofEnableSmoothing();
//        mySound.load("Prison/koe.wav");
//        mySound.setLoop(false);
//        mySound.play();
//        mySound.setVolume(0.5);
//    }
   
    //wall crack
    mCrack.setup();
    mIsPlayBed = false;
    //fire(Leap)
    
    setupFire();
}

//--------------------------------------------------------------
void P_DeskScene::update(){
    if(mIsPlayChair){
        mShadowMovie.update();
        ofSoundUpdate();
    }
    if(mSimpleHands.size() > 0 && !mIsPlayDesk){
        mIsPlayDesk = true;
    }
    
    if(mIsPlayDesk){
        updateFire();
    }
}

//--------------------------------------------------------------
void P_DeskScene::draw(){
    //ofSetColor(0,127,127);
    //ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    //ËÉåÊôØ
    mBackground.draw(0,0,ofGetWidth(),ofGetHeight());
    if(mIsPlayChair){
        mShadowMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    if(mIsPlayDesk){
        drawFire();
    }
    
    //crack
    if(mIsPlayBed){
        if(P_Crack::getCount() == -1){
            mIsPlayBed = false;
        }else{
            mCrack.draw();
        }
    }
}


void P_DeskScene::updateFire(){
    //ÁÅ´„ÅÆÁéâ
    group.emitRandom(20, mPosition);//(ofGetMouseX(), ofGetMouseY()));
    mPosition += mVelocity;
    
    if (mPosition.x + 30 <= ofGetMouseX() && y - 30 >= ofGetMouseY() ) {
        mPosition.x -= 4;
        mPosition.y += 4;
        
        if (mPosition.x - ofGetMouseX() == 50) {
            mPosition.x += 7;
            mPosition.y -= 4;
            
        }
        
    }else if (mPosition.x - 30 >= ofGetMouseX() && y - 30 >= ofGetMouseY()) {
        mPosition.x -= 1.5;
        mPosition.y += 5;
        
        if (mPosition.x - ofGetMouseX() == 20) {
            mPosition.x += 5;
            mPosition.y -= 4;
        }
        
        
    }else if (mPosition.x + 30 <= ofGetMouseX() && y + 30 <= ofGetMouseY()) {
        mPosition.x -= 4;
        mPosition.y -= 4;
        
        if (mPosition.x - ofGetMouseX() == 50) {
            mPosition.x += 7;
            mPosition.y += 4;
        }
        
        
    }else if (mPosition.x - 30 >= ofGetMouseX() && y + 30 <= ofGetMouseY()) {
        mPosition.x -= 1.5;
        mPosition.y += 5;
        
        if (mPosition.x - ofGetMouseX() == 20) {
            mPosition.x += 5;
            mPosition.y -= 4;
        }
        
        
        
    }else if (mPosition.x == 100) {
        group.setLifeTime(0);
    }
    sys.update();
    if(mPosition.x > ofGetWidth()){
        mIsPlayDesk = false;
    }
    
}


void P_DeskScene::drawFire(){
    ofSetColor(0);
    //FireBall
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    sprite.bind();
    ofEnablePointSprites();
    if (mPosition.x > 30){
        sys.draw();
    }
    sys.draw();
    ofDisablePointSprites();
    sprite.unbind();
    
}

//--------------------------------------------------------------
void P_DeskScene::keyPressed(int key){
    if(key == 'g'){
        gIsKeyPressed = true;
    }
    
    if(key == 'l'){
        lIsKeyPressed = true;
    }
    
}

//--------------------------------------------------------------
void P_DeskScene::keyReleased(int key){
    if(key == 'g'){
        gIsKeyPressed = false;
    }
    if(key == 'l'){
        lIsKeyPressed = false;
    }
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_DeskScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_DeskScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_DeskScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_DeskScene::dragEvent(ofDragInfo dragInfo){
    
}

void P_DeskScene::setupFire(){
    //fire
    mIsPlayDesk = false;
    ofDisableArbTex();
    sprite.load("Prison/image.png");
    ofEnableArbTex();
    sys.setup();
    group.setup(sys);
    group.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
                   ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));
    group.setLifeTime(0.5);//0.3
    group.setFriction(0.1);
    group.setSize(0, ofxSPK::RangeF(30, 250));
    group.setGravity(ofVec3f(0, -10, 0));
    group.setMass(0.1, 1);
    rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
                                  SPK::Vector3D(0, 1, 0),
                                  200,
                                  10), group);
    
    group.reserve(10000);
    x = ofGetWidth() - 100;
    y = ofRandom(ofGetHeight() / 3, ofGetHeight() / 2);
    mPosition = ofVec2f(x, y);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
    
}

void P_DeskScene::resetFire(){
    x = ofGetWidth() - 100;
    y = ofRandom(ofGetHeight() / 3, ofGetHeight() / 2);
    mPosition = ofVec2f(x, y);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
}

void P_DeskScene::actionBed(){
    mIsPlayBed = true;
}

void P_DeskScene::actionChair(){
    mIsPlayChair = true;
    mySound.play();
}
