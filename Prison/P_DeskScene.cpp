//
//  P_DeskScene.cpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/21.
//
//

#include "P_DeskScene.hpp"
#include "ofxSPK.h"

ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

ofxSPK::Modifier rot;
void P_DeskScene::setup(){
    //人影
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.loadMovie("P_deskshadow.mp4");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    mySound.loadSound("kodomo.wav");
    mySound.setLoop(false);
    mySound.play();
    mySound.setVolume(0.5);
    
    
    
    //笑い声
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    mySound.loadSound("koe.wav");
    mySound.setLoop(false);
    mySound.play();
    mySound.setVolume(0.5);
    
    
    
    
    
    //壁のひび
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    fingersMovie.loadMovie("hibi.mov");
    fingersMovie.setLoopState(OF_LOOP_NONE);
    fingersMovie.play();
    
    
    //火の玉
    ofDisableArbTex();
    sprite.loadImage("image.png");
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

//--------------------------------------------------------------
void P_DeskScene::update(){
    fingersMovie.update();
    
    
    //火の玉
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
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void P_DeskScene::draw(){
    //ofSetColor(0,127,127);
    //ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,20);
    ofSetColor(0xFFFFFF);
    fingersMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
    
    
    //火の玉
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    sprite.bind();
    ofEnablePointSprites();
    if (mPosition.x > 30)
    {
        sys.draw();
    }
    sys.draw();
    ofDisablePointSprites();
    sprite.unbind();
}

//--------------------------------------------------------------
void P_DeskScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void P_DeskScene::keyReleased(int key){
    
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
