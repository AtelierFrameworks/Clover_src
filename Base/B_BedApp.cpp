//
//  B_BedApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_BedApp.hpp"
void B_BedApp::setup(){
    BaseApp::setup();
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    setupMission1();
}

void B_BedApp::setupMission1(){
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    eHouselight = false;
    mouse.load("nezumi.png");
    horse.load("uma.png");
    bat.load("bat2.png");
    pumpkin.load("pumpkin2.png");
    town.load("town2.png");
    lamp.load("lamp.png");
    houselight.load("houselight.png");
    tree.load("tree.png");
    pampukin.load("pampkin.png");
}

void B_BedApp::setupStair(){
    //階層移動
    isMove = true;
    town1.load("sky.png");
    town2.load("sky.png");
    town3.load("ontown2.png");
    px = 0;
    py = 0;
    mPosition = ofVec2f(px, py);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);

}

void B_BedApp::setupMission2(){
    //Mission2
     town3.load("town2.png");
    isBat = false;
    isPumpkin = false;
    bat.load("bat.png");

}

void B_BedApp::setupSun(){
    //太陽月
    isMoved = true;
    //moon.load("moon.png");
    //cloud.load("black.png");
    sky.load("sky2.png");
    px = 0;
    py = 0;
    mPosition = ofVec2f(px, py);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);

}

void B_BedApp::setupStar(){
    //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = true;
}

//--------------------------------------------------------------
void B_BedApp::update(){
    BaseApp::update();
    if(!getIsMovie()){
    switch (getNowMission()) {
        case CONST::MISSION1:
            updateMission1();
            break;
        case CONST::STAIR:
            updateStair();
            break;
        case CONST::MISSION2:
            updateMission2();
            break;
        case CONST::SUN:
            updateSun();
            break;
        case CONST::STAR:
            updateStar();
            break;
        case CONST::LOSE:
            //play movie
            break;
        default:
            break;
            
    }
}
}

void B_BedApp::updateMission1(){
    //Mission1
 }

void B_BedApp::updateStair(){
    //階層移動
    if (isMove) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    if (mPosition.y >= ofGetHeight()) {
        isMove = false;
    }
}

void B_BedApp::updateMission2(){
   
}

void B_BedApp::updateSun(){
    //太陽月
    if (isMoved ) {
        mVelocity.y += 0.05;
        mPosition -= mVelocity;
    }
    if (mPosition.y <= -ofGetHeight() * 3.5) {
        mPosition += mVelocity;
    }
       if (m_py <= 0 && c_px < ofGetWidth() / 2 - 230) {
        c_px += 1.6;
    }
    if (m_py > 0) {
        m_px -= 0.25;
        m_py -= 1;
        m2_px += 0.5;
        m2_py += 0.5;
    }
}

void B_BedApp::updateStar(){
    //満天の星
    if (mIsKeyPressed == false) {
        time++;
    }
    else if (mIsKeyPressed == true) {
        time --;
    }
}

//--------------------------------------------------------------
void B_BedApp::draw(){
    BaseApp::draw();
    if(!getIsMovie()){
        switch (getNowMission()) {
            case CONST::MISSION1:
                drawMission1();
                break;
            case CONST::STAIR:
                drawStair();
                break;
            case CONST::MISSION2:
                drawMission2();
                break;
                
            case CONST::SUN:
                drawSun();
                break;
            case CONST::STAR:
                drawStar();
                break;
            case CONST::LOSE:
                ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
                ofSetColor(127,127,127,127);
                ofDrawRectangle(0, 0, ofGetWidth(), ofGetWidth());

                break;
            default:
                break;
        }
    }
    if(getNowMission() == CONST::WIN){
        drawStar();
    }
    
}

void B_BedApp::drawMission1(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    if (mLamp) {
        lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (rPampukin) {
        pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (dTree) {
        tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (eHouselight) {
        houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    ofSetColor(100);
    mouse.draw(w / 3 * 2 - size / 2, h - size / 2, size, size);
    horse.draw(w / 3 * 4 - size / 2, h - size / 2, size, size);
    ofSetColor(255, 255, 255);
    bat.draw(w / 3 * 2 - size / 2, h - size / 2, size - 20, size);
    pumpkin.draw(w / 3 * 4 - size / 2, h - size / 2, size - 20, size);
    ofSetColor(255);
}

void B_BedApp::drawStair(){
    //階層移動
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
}

void B_BedApp::drawMission2(){
    //Mission2
    if(isBat){
        pumpkin.draw(w / 3 * 4 - size / 2, h - size / 2, size - 20, size);
    }
    if(isPumpkin){
        bat.draw(w / 3 * 2 - size / 2, h - size / 2, size - 20, size);
    }
}

void B_BedApp::drawSun(){
    //太陽月
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);
    /*moon.draw(m_px, m_py, m2_px, m2_py);
    if (m_py <= 0) {
        cloud.draw(c_px, c_py, 450, 450);
    }*/
}

void B_BedApp::drawStar(){
    //満天の星
    //勝利動画のタイミング
    //負け→タイムアップになった瞬間真っ暗のち動画再生
    i = ofGetFrameNum();//frame数
    if (mIsKeyPressed == true) {
        if (i - time < 256*2-1) {
            ofSetColor(255, 255, 255, (i - time)/2);
        }
        if (i == 3000) {
            i = i / 5;
        }
        img.draw(0, 0, ofGetWidth(), ofGetHeight());
    }

}
//--------------------------------------------------------------
void B_BedApp::keyPressed(int key){
    BaseApp::keyPressed(key);
    //Mission1
    if (key == 'm') {
        mLamp = true;
    }
    if (key == 'r') {
        rPampukin = true;
    }
    if (key == 'd') {
        dTree = true;
    }
    if (key == 'e') {
        eHouselight = true;
    }
    
    //階層移動
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission2
    if(key == 'a'){
        isBat = true;
    }
    if(key == 'p'){
        isPumpkin = true;
    }
    
    //太陽月
    if (key == 'b') {
        isMoved = true;
    }
    
    //満天の星
    if (key == 's') {
        mIsKeyPressed = true;
    }
}

//--------------------------------------------------------------
void B_BedApp::keyReleased(int key){
    BaseApp::keyReleased(key);
    //Mission2
    if(key == 'a'){
        isBat = false;
    }
    if(key == 'p'){
        isPumpkin = false;
    }
}

//--------------------------------------------------------------
void B_BedApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_BedApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_BedApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_BedApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_BedApp::changeMission(){
    switch (getNowMission()) {
        case CONST::STAIR:
            setupStair();
            break;
        case CONST::SUN:
            setupSun();
            break;
        case CONST::STAR:
            setupStar();
            break;
        case CONST::LOSE:
            break;
        case CONST::MISSION2:
            setupMission2();
          
            break;

        default:
            break;
    }
}

