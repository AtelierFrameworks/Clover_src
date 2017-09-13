//
//  M_DeskScene.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/09/07.
//
//

#include "M_DeskScene.hpp"
void M_DeskScene::setup(){
    magic_kabe.load("Magic/M_front.png");
    setupCurse();
}

void M_DeskScene::setupBat(){
    //Movie1.load("M_bat1.mp4");
    //Movie1.play();
    
    BatSound.load("Magic/batSound.mp3");
    BatSound.setLoop(true);
    BatSound.play();
}

void M_DeskScene::setupCurse(){
    // setup pointsprite texture
    // NOTES: the texture size must be Power of Two,
    // and turn off arb texture option while loading
    ofDisableArbTex();
    sprite.load("Magic/sample11.png");
    ofEnableArbTex();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    sys.setup();
    
    group.setup(sys);
    group.setColor(ofxSPK::RangeC(ofColor(255, 20), ofColor(255, 40)),
                   ofxSPK::RangeC(ofColor(0, 0 ), ofColor(255, 0)));
    
    group.setLifeTime(1, 15);//粒子が発生している時間の範囲(最小時間,最大時間)
    group.setFriction(0.1);
    group.setSize(0, ofxSPK::RangeF(50, 200));//粒子の最大の大きさ
    
    
    group.setMass(0.1, 0.5);//MAXを高くすると波状がくっきりする?
}

//--------------------------------------------------------------
void M_DeskScene::update(){
    ofMovie.update();
    updateCurse();
}

void M_DeskScene::updateBat(){
    //Movie1.update();
    //x:x座標  y:y座標 w:映像の横幅 h:映像の縦幅
    //BatPosition1x -= 5;//映像の移動速度
    //BatPosition1y -= 5;//M_bat1の場合、左への移動
    //BatPosition1w -= 5;//ウィンドウの大きさ
    //BatPosition1h -= 5;//拡大・縮小
}

void M_DeskScene::updateCurse(){
    check = (int)ofGetElapsedTimef() % 3;
    if (check == 0) {
        angle = -1000;
    }
    else if (check == 1) {
        angle = 0;
    }
    else if (check == 2) {
        angle = 1000;
    }
    group.setGravity(ofVec3f(0, -50, 0));
    
    group.reserve(3000);//粒子の発生する間隔
    
    if (ofGetElapsedTimef() < 50) {
        range = ofGetElapsedTimef() * 10;
    }
    
    group.emitRandom(10, ofVec3f(150*sin(15*ofGetElapsedTimef())+ofGetWidth()/2,ofGetHeight()/5*4+300/*ofGetMouseX(), ofGetMouseY()*/));
    
    sys.update();
}

//--------------------------------------------------------------
void M_DeskScene::draw(){
    magic_kabe.draw(0,0,ofGetWidth(),ofGetHeight());
    ofMovie.draw(0,0,400,300);
    
    drawCurse();
}

void M_DeskScene::drawBat(){
      //Movie1.draw(ofGetWidth()/2+BatPosition1x, ofGetHeight()+BatPosition1y, 400+BatPosition1w, 300+BatPosition1h);
}

void M_DeskScene::drawCurse(){
    ofEnableBlendMode(OF_BLENDMODE_ADD/*ALPHA  ADD*/);
    sprite.bind();
    ofEnablePointSprites();
    sys.draw();
    ofDisablePointSprites();
    sprite.unbind();
    ofSetColor(255, 255, 0);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
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
    mVideo.stop();
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mEndMovieEvent, e_gimmick);
}

