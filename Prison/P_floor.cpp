//
//  P_floor.cpp
//  
//
//  Created by USER1 on 2017/08/31.
//
//

#include "P_floor.hpp"

void P_floor::setup(){
    //床のひび割れ
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.load("yuka.mov");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    //背景
    myImage.load("P_floor.png");
    setupFire();
    
    
}

//--------------------------------------------------------------
void P_floor::update(){
    fingersMovie.update();
    updateFire();
}

void P_floor::updateFire(){
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

}

//--------------------------------------------------------------
void P_floor::draw(){
    //ËÉåÊôØ
    myImage.draw(0,0);
    //„Å≤„Å≥Ââ≤„Çå
    ofSetColor(0,127,127);
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
    
   
}

void P_floor::drawFire(){
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
void P_floor::keyPressed(int key){
    
}

//--------------------------------------------------------------
void P_floor::keyReleased(int key){
    
}

//--------------------------------------------------------------
void P_floor::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void P_floor::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void P_floor::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void P_floor::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void P_floor::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void P_floor::dragEvent(ofDragInfo dragInfo){
    
}

void P_floor::setupFire(){
    //ÁÅ´„ÅÆÁéâ
    ofDisableArbTex();
    sprite.load("image.png");
    ofEnableArbTex();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
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


