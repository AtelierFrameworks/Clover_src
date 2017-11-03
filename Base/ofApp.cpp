#include "ofApp.h"
//カーテンゾーン
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    changeMission(CONST::MISSION1);
    mBgm.setLoop(true);
    mBgm.setVolume(0.5);
    mBgm.load("cloverBGM.mp3");
    mBgm.play();
    for(int i = 0; i < 5;i++){
        mIsAction[i] = false;
    }
    mIsVideoPlaying = false;
    mArduinoManager.setup();
    //„É≠„Ç∞„Éï„Ç°„Ç§„É´‰ΩúÊàê
    isStartScene=false;
    isTimer = false;
    //TODO::setJudgeModel
    mID = 0;
    ofAddListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    //挑戦状
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    Timer.load("MountainsofChristmas.ttf", 200);
    setupMission1();
}

void ofApp::setupMission1(){
    mIsStartMission = false;
    challenge_Movie.setup("challenge_Movie.m4v", OF_LOOP_NONE, CONST::M1);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
    challenge_Movie.play();
    setIsMovie(true);
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
    lamp.load("lamp.png");
     pampukin.load("pampukin.png");
    tree.load("tree.png");
    tower.load("tower.png");
    houselight.load("houselight.png");
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
    sky.load("sky2.png");
    challenge_Movie.closeMovie();
    challenge_Movie.setup("challenge_Movie.m4v", OF_LOOP_NONE, CONST::M2);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
    challenge_Movie.play();
    setIsMovie(true);
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
    bat.load("bat.png");
    challenge_Movie.closeMovie();
    challenge_Movie.setup("challenge_Movie.m4v", OF_LOOP_NONE, CONST::M3);
    challenge_Movie.play();
    setIsMovie(true);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
}

void ofApp::setupStar(){
    //満天の星
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = false;
    
}
//--------------------------------------------------------------
void ofApp::update(){
    mArduinoManager.update();
    BaseApp::update();
  
    if (isTimer) {
        sec -= 0.01667;
    }
    if (getIsMovie()){
        //挑戦状
        challenge_Movie.update();
    }else{
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
            case CONST::MISSION3:
                updateMission3();
                break;
            case CONST::LOSE:
                //play movie
                break;
            case CONST::WIN:
                //play movie
                break;
            default:
                break;

    }
    }
    
    
    
    
}

void ofApp::updateMission1(){
}

void ofApp::updateStair(){
    //階層移動の終わりは1回したら止まるようにしてる。
    if (isMove) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
        if (mPosition.y >= ofGetHeight()) {
            isMove=false;
        }
    }
}

void ofApp::updateMission2(){
    //Mission2
    if (isMove) {
        
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
    //太陽→月は要実装
    if (isMoved) {
      
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
    if (getIsMovie()){
        //挑戦状
        ofSetColor(0xFFFFFF);
        challenge_Movie.draw(0, 0, ofGetWidth(), ofGetHeight());
        ofSetHexColor(0x000000);
    }else{
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
        case CONST::MISSION3:
            drawMission3();
            break;
        case CONST::LOSE:
            //play movie
            break;
        case CONST::WIN:
            //play movie
            break;
            
        default:
            break;
    }
        drawTimer();

    }
    }

void ofApp::drawMission1(){
    //Mission1
    if (mLamp) {
         lamp.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (rPampukin) {
       pampukin.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (dTree) {
         tree.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (hTower) {
        tower.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (eHouselight) {
        houselight.draw(0, 0, ofGetWidth(), ofGetHeight());
    }

    town.draw(0, 0, ofGetWidth(), ofGetHeight());
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
    if(isBat2){
        ofSetColor(255, 0, 0);
        bat.draw(w - size / 2, h - size / 2, size, size);//上
        ofSetColor(255);
        bat.draw(w - length * p - size / 2, h + length * q - size / 2, size, size);//左下
        bat.draw(w + length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);//右
        bat.draw(w - length / 2 - size / 2, h + length * q - t - v - size / 2, size, size);//左
        bat.draw(w + length * p - size / 2, h + length * q - size / 2, size, size);//右下
        
    }
    ofSetColor(255, 255, 0);
    
    if(drawline1){
        ofDrawLine(w, h, w - length * p, h + length * q);
    }
    if(drawline2 ){
        ofDrawLine(w - length * p, h + length * q, w + length / 2, h + length * q - t - v);
    }
    if(drawline3){
        ofDrawLine(w + length / 2, h + length * q - t - v, w - length / 2, h + length * q - t - v);
    }
    if(drawline4){
        ofDrawLine(w - length / 2, h + length * q - t - v, w + length * p, h + length * q);
    }
    if(drawline5){
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
        ofSetColor(255, 0, 0,0);
        if (sec<=9.5) {
            timerText = "0" + ofToString(min, 0) + ":" + "0" + ofToString(sec, 0);
        }
        else {
            timerText = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(timerText, (ofGetWidth() / 2) - 150, 200);
    }else {
        ofSetColor(255, 255, 255);
        if (sec <=9.5) {
           timerText  = "0" + ofToString(min, 0) + ":" + "0" +ofToString(sec, 0);
        }
        else {
           timerText  = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(timerText, (ofGetWidth() / 2) - 150, 200);
    }
    if (sec <= 0.5 && min == 0) {
        changeMission(CONST::LOSE);
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
    ofRemoveListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
 }

void ofApp::closeCurtain(){

}


void ofApp::changeMission(CONST::E_MISSION mission){
    setMission(mission);
    setIndex(0);
    
    switch (getNowMission()) {
        case CONST::STAIR:
            setupStair();
            mIsStartMission = false;
            break;
        case CONST::SUN:
            setupSun();
            mIsStartMission = false;
            break;
        case CONST::STAR:
            setupStar();
            mIsStartMission = false;
        default:
            break;
    }

    if(getNowMission() == CONST::WIN || getNowMission() == CONST::LOSE){
        challenge_Movie.closeMovie();
        if (getNowMission() == CONST::WIN) {
            challenge_Movie.setup("win.mp4", OF_LOOP_NONE, CONST::MWIN);
           
        }else{
            challenge_Movie.setup("lose.mp4", OF_LOOP_NONE, CONST::MLOSE);
            
        }
         challenge_Movie.play();
        setIsMovie(true);
    }else{
        mJudgeArray.clear();
        mJudgeArray = getJudgeArray();
    }
    mBedApp -> changeMission();
    mDeskApp -> changeMission();
    mFloorApp -> changeMission();
}




void ofApp::endMovie(CONST::E_MOVIE & movie){
    setIsMovie(false);
    switch (movie) {
        case CONST::M1:
            isTimer = true;
            mIsStartMission =true;
            break;
        case CONST::M2:
            isTimer = true;
            mIsStartMission = true;
            break;
        case CONST::M3:
            isTimer = true;
            mIsStartMission = true;
            break;
        case CONST::MWIN:
            
            break;
        case CONST::MLOSE:
            break;
        default:
            break;
    }
    ofRemoveListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
}

void ofApp:: receiveData(std::vector<CONST::E_SENSOR> & isActionParts){
    if(mIsStartMission){
    for(CONST::E_SENSOR sensor:isActionParts){
        if(sensor == mJudgeArray[getIndex()]){
            int index = getIndex();
            index++;
            setIndex(index);
            if(getIndex() == mJudgeArray.size()){
                int mission = (int)getNowMission();
                mission++;
                changeMission((CONST::E_MISSION)mission);
            }
            
            //TODO:effect
        }else{
            //TODO:Miss effect
        }
        switch(sensor){
            case CONST::S1:
                break;
            case CONST::S2:
                break;
            case CONST::S3:
                break;
            case CONST::S4:
                break;
            case CONST::S5:
                break;
            case CONST::S6:
                break;
            case CONST::S7:
                break;
            case CONST::S8:
                break;
            case CONST::S9:
                break;
            case CONST::S10:
                break;
            default:break;
            }
    }
    }
}






