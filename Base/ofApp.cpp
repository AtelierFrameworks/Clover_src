#include "ofApp.h"
//カーテンゾーン
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    mBgm.setLoop(true);
    mBgm.setVolume(0.5);
   
    for(int i = 0; i < 5;i++){
        mIsAction[i] = false;
    }
    setupLeapMotion();
    mArduinoManager.setup();
    setNowScene(CONST::NONE);
    //„É≠„Ç∞„Éï„Ç°„Ç§„É´‰ΩúÊàê
    isStartScene=false;
    //„Ç∑„Éº„É≥ÂàùÊúüÂåñ
    mScenes.clear();
//    actionCurtain();
    //TODO::setJudgeModel
    mID = 0;
    ofAddListener(mBedApp ->mMovieEndEvent, this, &ofApp::endMovie);
    ofAddListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
    ofAddListener(mFloorApp -> mMovieEndEvent,this,&ofApp::endMovie);
    
    
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    //挑戦状
    ofSetVerticalSync(true);
    frameByframe = false;
    ofEnableSmoothing();
    challenge_Movie.load("challenge_Movie.m4v");
    challenge_Movie.play();
    
 
    
    
    Timer.loadFont("MountainsofChristmas.ttf", 200);
    
   
}

void ofApp::setupMission1(){
    
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    hTower = false;
    eHouselight = false;
    //ウサギ
    rabbit.load("usa.png");
    town.load("town1.png");
    bat.load("bat2.png");
    

}

void ofApp::setupStair(){
    
    //階層移動
    isMove = false;
    
    town1.load("sky.png");
    town2.load("sky.png");
    town3.load("town1.png");
    
    px = 0;
    py = 0;
    
    mPosition = ofVec2f(px, py);
    
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
}

void ofApp::setupMission2(){
    
    //Mission2
    isBat = false;
    isPumpkin = false;
}

void ofApp::setupSun(){
    //太陽月
    isMoved = false;
}

void ofApp::setupMission3(){
    //Mission3
    drawline1 = false;
    drawline2 = false;
    drawline3 = false;
    drawline4 = false;
    drawline5 = false;
    isBat2 = false;
}

void ofApp::setupStar(){
    //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;
    

}
//--------------------------------------------------------------
void ofApp::update(){
    updateLeapMotion();
    mArduinoManager.update();
    BaseApp::update();
    
    
    //挑戦状
    challenge_Movie.update();
    
    if (isTimer) {
        sec = sec -0.016666;
    }
}

void ofApp::updateMission1(){
    //Mission1
    if (mLamp == true) {
        lamp.load("lamp.png");
    }
    if (rPampukin == true) {
        pampukin.load("pampukin.png");
    }
    if (dTree == true) {
        tree.load("tree.png");
    }
    if (hTower == true) {
        tower.load("tower.png");
    }
    if (eHouselight == true) {
        houselight.load("houselight.png");
    }
    
    if (isMove == true) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    
    if (mPosition.y >= ofGetHeight()) {
        mPosition -= mVelocity;
    }
}

void ofApp::updateStair(){
    //階層移動
    if (isMove == true) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
    }
    
    if (mPosition.y >= ofGetHeight()) {
        mPosition -= mVelocity;
    }

}

void ofApp::updateMission2(){
    //Mission2
    if (isMove == true) {
        sky.load("sky2.png");
        px = 0;
        py = 0;
        mPosition = ofVec2f(px, py);
        vx = 0;
        vy = 0;
        mVelocity = ofVec2f(vx, vy);
        
        mVelocity.y += 0.01;
        mPosition -= mVelocity;
    }
    
    if (mPosition.y <= -ofGetHeight() * 3) {
        mPosition += mVelocity;
    }

}

void ofApp::updateSun(){
    //太陽月
    if (isMoved == true) {
        sky.load("sky2.png");
        px = 0;
        py = 0;
        mPosition = ofVec2f(px, py);
        vx = 0;
        vy = 0;
        mVelocity = ofVec2f(vx, vy);
        
        mVelocity.y += 0.01;
        mPosition -= mVelocity;
    }
    
    if (mPosition.y <= -ofGetHeight() * 3) {
        mPosition += mVelocity;
    }

}

void ofApp::updateMission3(){
    //Mission3
    if(isBat2 == true){
        bat.load("bat.png");
    }
}

void ofApp::updateStar(){
    //満天の星
    if (mIsKeyPressed == false) {
        time++;
    }
    else if (mIsKeyPressed == true) {
        time --;
    }

}
//-----------------------

void ofApp::draw(){
    BaseApp::draw();
    //挑戦状
    ofSetColor(0xFFFFFF);
    challenge_Movie.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetHexColor(0x000000);
}

void ofApp::drawMission1(){
    //Mission1
    town.draw(0, 0, ofGetWidth(), ofGetHeight());
    lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    tower.draw(0, 0, ofGetWidth(), ofGetHeight());
    houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    rabbit.draw(w / 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    bat.draw(w / 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    
    ofSetColor(255);
   
}

void ofApp::drawStair(){
    //階層移動
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
}

void ofApp::drawMission2(){
    //Mission2
    if(isBat == true){
        bat.draw(w - length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
    if(isPumpkin == true){
        pumpkin.draw(w + length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);
    }
}

void ofApp::drawSun(){
    //太陽月
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);

}

void ofApp::drawMission3(){
    //Mission3
    if(isBat2 == true){
        
        ofSetColor(255, 0, 0);
        bat.draw(w - size / 2, h - size / 2, size, size);//上
        ofSetColor(255);
        bat.draw(w - length * p - size / 2, h + length * q - size / 2, size, size);//左下
        bat.draw(w + length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);//右
        bat.draw(w - length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);//左
        bat.draw(w + length * p - size / 2, h + length * q - size / 2, size, size);//右下
        
    }
    ofSetColor(255, 255, 0);
    
    if(drawline1 == true){
        ofDrawLine(w, h, w - length * p, h + length * q);
    }
    if(drawline2 == true){
        ofDrawLine(w - length * p, h + length * q, w + length / 2, h + length * q - t - v);
    }
    if(drawline3 == true){
        ofDrawLine(w + length / 2, h + length * q - t - v, w - length / 2, h + length * q - t - v);
    }
    if(drawline4 == true){
        ofDrawLine(w - length / 2, h + length * q - t - v, w + length * p, h + length * q);
    }
    if(drawline5 == true){
        ofDrawLine(w + length * p, h + length * q, w, h);
    }
    
    

}

void ofApp::drawStar(){
    //満天の星
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

void ofApp::drawTimer(){
    
    if (min<=0&&sec<=30) {
        ofSetColor(255, 0, 0);
        if (sec<=9.5) {
            time = "0" + ofToString(min, 0) + ":" + "0" + ofToString(sec, 0);
        }
        else {
            time = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(time, (ofGetWidth() / 2) - 150, ofGetHeight() / 2);
    }
    
    else {
        ofSetColor(255, 255, 255);
        if (sec <=9.5) {
            time = "0" + ofToString(min, 0) + ":" + "0" +ofToString(sec, 0);
        }
        else {
            time = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(time, (ofGetWidth() / 2) - 150, 50);
    }
    if (sec <= 0.5 && min == 0) {
        
        isTimer = false;
    }
    if (isTimer) {
        if (sec <= 0.5) {
            min--;
            sec = 59;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    BaseApp::keyPressed(key);
   if(key == 'a'){
        actionCurtain();
    }
    if(key == 'c'){
        closeCurtain();
    }
   if(key == 'f'){
        switch (getNowScene()) {
            case CONST::PRISON:{
                mScenes.at(0) -> actionBed();
                mBedApp -> mScenes.at(0) -> actionBed();
                mDeskApp -> mScenes.at(0) -> actionBed();
                mFloorApp -> mScenes.at(0) -> actionBed();
                break;
            }
            case CONST::MAGIC:{
                mBedApp -> mScenes.at(0) -> actionBed();
                mDeskApp -> mScenes.at(0) -> actionBed();
                break;
            }
            default:
                break;
        }

    }
    
    if(key == 'o'){
        switch (getNowScene()) {
            case CONST::PRISON:{
                mScenes.at(0) -> actionShelf();
                break;
            }
            case CONST::MAGIC:{
                mDeskApp -> mScenes.at(0) -> actionShelf();
                break;
            }
            default:
                break;
        }

    }
    if(key == 'e'){
        switch (getNowScene()) {
            case CONST::PRISON:{
                mScenes.at(0) -> actionChair();
                break;
            }
            case CONST::MAGIC:{
                mFloorApp -> mScenes.at(0) -> actionChair();
                break;
            }
            default:
                break;
        }

    }
    
    
    //
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
    if (key == 'h') {
        hTower = true;
    }
    if (key == 'e') {
        eHouselight = true;
    }
    
    //階層移動
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission2
    if (key == 'b') {
        isMove = true;
    }
    
    //太陽月
    if (key == 'b') {
        isMove = true;
    }
    
    //Mission3
    if(key =='1'){
        drawline1 = true;
    }
    if(key =='2'){
        drawline2 = true;
    }
    
    if(key =='3'){
        drawline3 = true;
    }
    
    if(key =='4'){
        drawline4 = true;
    }
    
    if(key =='5'){
        drawline5 = true;
    }
    if(key == '6'){
        isBat2 = true;
    }
    
    
    //満天の星
    if (key == 's') {
        mIsKeyPressed = true;
    }

    if (key=='n') {
        isTimer = false;
        
    }
    if (key=='v') {
        isTimer = true;
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
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
void ofApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void ofApp::exit(){
    closeCurtain();
    ofRemoveListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
    
    //TODO: ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•√à√Ö‚àè√ä√§√ª
    mID ++;
    int id = mID % 2 + 1;
    setNowScene((CONST::E_SCENE)id);
//    setNowScene(CONST::MAGIC);
    changeScene();
}

void ofApp::closeCurtain(){
    ofBackground(80);
    if(getNowScene()==CONST::PRISON){
      
        ofRemoveListener(mScenes[0]->mEndMovieEvent,this,&ofApp::endMovie);
    }
    setNowScene(CONST::NONE);
    mBgm.stop();
    if(mScenes.size() > 0){
    changeScene();
    freeToSceneMemory();
    mBedApp -> freeToSceneMemory();
    mDeskApp -> freeToSceneMemory();
    mFloorApp -> freeToSceneMemory();
    }
}


void ofApp::changeScene(){
    BaseScene *newScene;
   
    mBedApp   -> changeScene();
    mDeskApp  -> changeScene();
    mFloorApp -> changeScene();
}


void ofApp::setupLeapMotion(){
    mLeap.open();
}

void ofApp::updateLeapMotion(){
    simpleHands = mLeap.getSimpleHands();
    ofLogNotice() << "a" << simpleHands.size();
    if( mLeap.isFrameNew() && simpleHands.size()){
        mLeap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        mLeap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        mLeap.setMappingZ(-150, 150, -200, 200);
    }
    mLeap.markFrameAsOld();
    
}

void ofApp::endMovie(CONST::E_GIMMICK & gimmick){
    switch (gimmick) {
        case CONST::G_M_CHAIR:
            mBedApp -> mScenes.at(0) -> actionEndMovie();
            break;
        case CONST::G_M_BED:
            mScenes.at(0) -> actionBed();
            mDeskApp -> mScenes.at(0) -> actionBedNext();
            mBedApp -> mScenes.at(0) -> actionBedNext();

        case CONST::G_P_BED:
            break;
        case CONST::G_P_CHAIR:
            mBedApp -> mScenes.at(0) -> actionChair();
            break;
        default:
            break;
        }
}

void ofApp:: receiveData(std::vector<CONST::E_PARTS> & isActionParts){
    for(CONST::E_PARTS isAction :isActionParts){
        switch(isAction){
            case CONST::P_CURTAIN_OPEN:
                actionCurtain();
                break;
            case CONST::P_CURTAIN_CLOSE:
                closeCurtain();
                break;
            case CONST::P_SHELF:
                switch (getNowScene()) {
                    case CONST::PRISON:{
                        mScenes.at(0) -> actionShelf();
                        break;
                    }
                    case CONST::MAGIC:{
                        mDeskApp -> mScenes.at(0) -> actionShelf();
                        break;
                    }
                    default:
                        break;
                }
                break;
            case CONST::P_CHAIR:
                switch (getNowScene()) {
                    case CONST::PRISON:{
                        mScenes.at(0) -> actionChair();
                        break;
                    }
                    case CONST::MAGIC:{
                        mFloorApp -> mScenes.at(0) -> actionChair();
                        break;
                    }
                    default:
                        break;
                }
                break;
            case CONST::P_BED:
                switch (getNowScene()) {
                    case CONST::PRISON:{
                        mScenes.at(0) -> actionBed();
                        mBedApp -> mScenes.at(0) -> actionBed();
                        mDeskApp -> mScenes.at(0) -> actionBed();
                        mFloorApp -> mScenes.at(0) -> actionBed();
                        break;
                    }
                    case CONST::MAGIC:{
                        mBedApp -> mScenes.at(0) -> actionBed();
                        mDeskApp -> mScenes.at(0) -> actionBed();
                        break;
                    }
                    default:
                        break;
                }
                break;
            default:break;
        }
    }
}




