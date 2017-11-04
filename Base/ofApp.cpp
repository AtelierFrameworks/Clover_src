#include "ofApp.h"
//„Ç´„Éº„ÉÜ„É≥„Çæ„Éº„É≥
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    
    mBgm.setLoop(true);
    mBgm.setVolume(0.5);
    mBgm.load("cloverBGM.mp3");
    mBgm.play();
    for(int i = 0; i < 5;i++){
        mIsAction[i] = false;
    }
    mIsVideoPlaying = false;
    mArduinoManager.setup();
    //‚Äû√â‚â†‚Äû√á‚àû‚Äû√â√Ø‚Äû√á¬∞‚Äû√á¬ß‚Äû√â¬¥‚Ä∞Œ©√∫√ä√†√™
    isStartScene=false;
    isTimer = false;
    //TODO::setJudgeModel
    mID = 0;
    ofAddListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    //ÊåëÊà¶Áä∂
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    Timer.load("MountainsofChristmas.ttf", 200);
}

void ofApp::setupMission1(){
    mIsStartMission = false;
    challenge_Movie.setup("letter1.mp4", OF_LOOP_NONE, CONST::M1);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
    challenge_Movie.play();
    setIsMovie(true);
    //Mission1
    mLamp = false;
    rPampukin = false;
    dTree = false;
    hTower = false;
    eHouselight = false;
    //„Ç¶„Çµ„ÇÆ
    rabbit.load("usa.png");
    town.load("town1.png");
    bat.load("bat2.png");
    lamp.load("lamp.png");
     pampukin.load("pampukin.png");
    tree.load("tree.png");
    tower.load("tower.png");
    houselight.load("houselight.png");
    mSound.load("sound1.mp3");
    mSound.setLoop(false);
    mSound.setVolume(0.8f);
    mSound.setMultiPlay(true);
}

void ofApp::setupStair(){
    //ÈöéÂ±§ÁßªÂãï
    isMove = true;
    town1.load("sky.png");
    town2.load("sky.png");
    town3.load("ontown1.png");
    px = 0;
    py = 0;
    mPosition = ofVec2f(px, py);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
}

void ofApp::setupMission2(){
    
    sky.load("sky2.png");
    challenge_Movie.setup("letter2.mp4", OF_LOOP_NONE, CONST::M2);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
    challenge_Movie.play();
    setIsMovie(true);
    pumpkin.load("pumpkin.png");
    //Mission2
    isBat = true;
    isPumpkin = false;
    //isPumpkin = true;
    mSound.unload();
    mSound.load("sound2.mp3");
}

void ofApp::setupSun(){
    //Â§™ÈôΩÊúà
    isMoved = true;
    px = 0;
    py = 0;
    mPosition = ofVec2f(px, py);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
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
    pumpkin.load("pumpkin.png");

    challenge_Movie.closeMovie();
    challenge_Movie.setup("letter3.mp4", OF_LOOP_NONE, CONST::M3);
    challenge_Movie.play();
    setIsMovie(true);
    ofAddListener(challenge_Movie.mEndEvent, this, &ofApp::endMovie);
    mSound.unload();
    mSound.load("sound3.mp3");
}

void ofApp::setupStar(){
    //Ê∫ÄÂ§©„ÅÆÊòü
    ofEnableAlphaBlending();
    img.load("star.png");
    mIsKeyPressed = true;
    i = ofGetFrameNum();//frameÊï∞
    time = i;
}
//--------------------------------------------------------------
void ofApp::update(){
    mArduinoManager.update();
    BaseApp::update();
    ofSoundUpdate();
    if (isTimer) {
        //timer -= 0.032;
    }
    if (getIsMovie()){
        //ÊåëÊà¶Áä∂
        challenge_Movie.update();
    }else{
        switch (getNowMission()) {
            case CONST::MISSION1:
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
            case CONST::STAR:
//                updateStar();
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
    //ÈöéÂ±§ÁßªÂãï„ÅÆÁµÇ„Çè„Çä„ÅØ1Âõû„Åó„Åü„ÇâÊ≠¢„Åæ„Çã„Çà„ÅÜ„Å´„Åó„Å¶„Çã„ÄÇ
    if (isMove) {
        mVelocity.y += 0.01;
        mPosition += mVelocity;
        if (mPosition.y >= ofGetHeight()) {
            isMove=false;
            changeMission(CONST::MISSION2);
        }
    }
}

void ofApp::updateMission2(){
  
}

void ofApp::updateSun(){
    //Â§™ÈôΩ‚ÜíÊúà„ÅØË¶ÅÂÆüË£Ö
    if (isMoved) {
        mVelocity.y += 0.05;
        mPosition -= mVelocity;
    }
    
    if (mPosition.y <= -ofGetHeight() * 3.5) {
        isMoved = false;
        changeMission(CONST::MISSION3);
    }

}

void ofApp::updateMission3(){
    
}

void ofApp::updateStar(){
    //Ê∫ÄÂ§©„ÅÆÊòü
   if (mIsKeyPressed == true) {
        time --;
    }

}
//-----------------------

void ofApp::draw(){
    BaseApp::draw();
    if (getIsMovie()){
        //ÊåëÊà¶Áä∂
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
        
        case CONST::STAR:
            drawStar();
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
     ofSetColor(255);
    //Mission1
        town.draw(0, 0, ofGetWidth(), ofGetHeight());
    rabbit.draw(w - size / 2, h - size / 2, size, size);
    ofSetColor(255, 255, 255);
    bat.draw(w - size / 2 - 10, h - size / 2+20, size - 20, size);
    
   
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
    

}

void ofApp::drawStair(){
    //ÈöéÂ±§ÁßªÂãï
    town1.draw(mPosition.x, mPosition.y - 1100, ofGetWidth(), ofGetHeight());
    town2.draw(mPosition.x, mPosition.y - 480, ofGetWidth(), ofGetHeight());
    town3.draw(mPosition.x, mPosition.y , ofGetWidth(), ofGetHeight());
}

void ofApp::drawMission2(){
    ofSetColor(255);
    //Mission2
    if(isBat == true){
        pumpkin.draw(w - length / 2 - size / 2 + 10, h + length * q - t - v - size / 2-50, size - 20, size);
    }
    if(isPumpkin == true){
        pumpkin.draw(w + length / 2 - size / 2 + 10,h + length * q - t - v - size / 2-50, size - 20, size);
    }
}

void ofApp::drawSun(){
    //Â§™ÈôΩÊúà
    sky.draw(mPosition.x, mPosition.y, ofGetWidth(), ofGetHeight() * 4);

}

void ofApp::drawMission3(){
    //Mission3
 
        ofSetColor(255, 0, 0);
        pumpkin.draw(w - size / 2 + 10, h - size / 2-50, size - 20, size);//‰∏ä
        ofSetColor(255);
        bat.draw(w - length * p - size / 2 + 10, h + length * q - size / 2-50, size - 20, size);//Â∑¶‰∏ã
        pumpkin.draw(w + length / 2 - size / 2 + 10, h + length * q - t - v - size / 2-50, size - 20, size);//Âè≥
        pumpkin.draw(w - length / 2 - size / 2 + 10, h + length * q - t - v - size / 2-50, size - 20, size);//Â∑¶
        bat.draw(w + length * p - size / 2 + 10, h + length * q - size / 2-50, size - 20, size);//Âè≥‰∏ã
        
    
    ofSetColor(255, 255, 0);
    ofSetLineWidth(5);
    if(drawline1){
        ofDrawLine(w, h-50, w - length * p, h + length * q-50);
    }
    if(drawline2 ){
        ofDrawLine(w - length * p, h + length * q -50, w + length / 2, h + length * q - t - v-50);
    }
    if(drawline3){
        ofDrawLine(w + length / 2, h + length * q - t - v-50, w - length / 2, h + length * q - t - v-50);
    }
    if(drawline4){
        ofDrawLine(w - length / 2, h + length * q - t - v-50, w + length * p, h + length * q-50);
    }
    if(drawline5){
        ofDrawLine(w + length * p, h + length * q-50, w, h-50);
    }
}
void ofApp::drawStar(){
    //Ê∫ÄÂ§©„ÅÆÊòü
    i = ofGetFrameNum();//frameÊï∞
changeMission(CONST::WIN);
//    if (mIsKeyPressed) {
//        if (i - time < 256*2-1) {
//            ofSetColor(255, 255, 255, (i - time)/2);
//        }
//        if (i == 3000) {
//            i = i / 5;
//        }
//        img.draw(0, 0, ofGetWidth(), ofGetHeight());
//        if(i - time >= 300){
//            changeMission(CONST::WIN);
//        }
//    }

}

void ofApp::drawTimer(){
    sec = (int)timer % 60;
    min = (int)timer / 60;
    
    if (min<=0&&sec<=30) {
        ofSetColor(255, 0, 0);
        if (sec<=9.5) {
            timerText = "0" + ofToString(min, 0) + ":" + "0" + ofToString(sec, 0);
        }
        else {
            timerText = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(timerText, (ofGetWidth() / 2) - 150, 200);
    }
    
    else {
        ofSetColor(255, 255, 255);
        if (sec <=9.5) {
            timerText = "0" + ofToString(min, 0) + ":" + "0" +ofToString(sec, 0);
        }
        else {
            timerText = "0" + ofToString(min, 0) + ":" + ofToString(sec, 0);
        }
        Timer.drawString(timerText, (ofGetWidth() / 2) - 150, 200);
    }
    if (sec <= 0.5 && min == 0) {
        isTimer = false;
        changeMission(CONST::LOSE);
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    BaseApp::keyPressed(key);
    if (key=='n') {
        isTimer = false;
        
    }
    if (key=='v') {
        isTimer = true;
    }
    
    if (key == 'f'){
        changeMission(CONST::MISSION1);
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

//‚Äû√á¬¥‚Äû√â¬∫‚Äû√â√ú‚Äû√â‚â•
void ofApp::actionCurtain(){
 }

void ofApp::closeCurtain(){

}


void ofApp::changeMission(CONST::E_MISSION mission){
    setMission(mission);
    setIndex(0);
    
    switch (getNowMission()) {
        case CONST::STAIR:
             mIsStartMission = false;
            isTimer = false;
            setupStair();
           
            break;
        case CONST::SUN:
            isTimer = false;
            mIsStartMission = false;

            setupSun();
            break;
        case CONST::STAR:
            isTimer = false;
            mIsStartMission = false;
            setupStar();
            break;
            
        case CONST::MISSION1:
            setupMission1();
            break;
        case CONST::MISSION2:
            setupMission2();
            break;
            
        case CONST::MISSION3:
            isTimer = false;
            setupMission3();
            break;
        default:
            break;
    }

    if(getNowMission() == CONST::WIN || getNowMission() == CONST::LOSE){
        mBgm.stop();
        if (getNowMission() == CONST::WIN) {
            challenge_Movie.setup("win.mp4", OF_LOOP_NONE, CONST::MWIN);
           
        }else{
            challenge_Movie.setup("lose.mp4", OF_LOOP_NONE, CONST::MLOSE);
        }
         challenge_Movie.play();
        setIsMovie(true);
    }else{
//        mJudgeArray.clear();
        mJudgeArray = getJudgeArray();
    }
    mBedApp -> changeMission();
    mDeskApp -> changeMission();
    mFloorApp -> changeMission();
}




void ofApp::endMovie(CONST::E_MOVIE & movie){
    challenge_Movie.closeMovie();
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

    if(mIsStartMission && mJudgeArray.size()>0){
    for(CONST::E_SENSOR sensor:isActionParts){
        if(mJudgeArray.size() > 0){
        if(sensor == mJudgeArray[getIndex()]){
            mSound.play();
            ofLogNotice() << "sensor!" << sensor;
            switch(sensor){
                case CONST::S1:
                    switch (getNowMission()) {
                        case CONST::MISSION3:
                            if(getIndex()==0){
                                drawline1 = true;
                            }
                            break;
                            
                        default:
                            break;
                    }
                    break;
                case CONST::S2:
                    switch (getNowMission()) {
                        case CONST::MISSION3:
                            drawline2 = true;
                            break;
                            
                        default:
                            break;
                    }
                    break;
                case CONST::S3:
                    switch (getNowMission()) {
                        case CONST::MISSION3:
                            drawline3 = true;
                            break;
                            
                        default:
                            break;
                    }
                    break;
                case CONST::S4:
                    switch (getNowMission()) {
                        case CONST::MISSION2:
                            isPumpkin = false;
                            mBedApp -> isPumpkin = false;
                            mDeskApp -> isPumpkin = true;
                            isBat = false;
                            mBedApp -> isBat = false;
                            mDeskApp -> isBat = false;
                            
                            break;
                        case CONST::MISSION3:
                            drawline4 = true;
                            break;
                        default:
                            break;
                    }
                    break;
                case CONST::S5:
                    switch (getNowMission()) {
                        case CONST::MISSION3:
                            drawline5 = true;
                            break;
                            
                        default:
                            break;
                    }
                    break;
                case CONST::S6:
                    switch (getNowMission()) {
                        case CONST::MISSION1:
                            rPampukin = true;
                            mBedApp -> rPampukin = true;
                            mDeskApp -> rPampukin = true;
                            break;
                        case CONST::MISSION2:
                            //
                            break;
                        default:
                            break;
                    }
                    break;
                case CONST::S7:
                    switch (getNowMission()) {
                        case CONST::MISSION1:
                            dTree = true;
                            mBedApp -> dTree = true;
                            mDeskApp -> dTree = true;
                            break;
                        case CONST::MISSION2:
                            isPumpkin=false;
                            mBedApp -> isPumpkin = true;
                            mDeskApp -> isPumpkin = false;
                            isBat=false;
                            mDeskApp->isBat=false;
                            mBedApp->isBat=false;
                            
                        default:
                            break;
                    }
                    break;
                case CONST::S8:
                    switch(getNowMission()){
                        case CONST::MISSION1:
                            eHouselight = true;
                            mBedApp -> eHouselight = true;
                            mDeskApp -> eHouselight = true;
                            break;
                        case CONST::MISSION2:
                            isBat = false;
                            mBedApp -> isBat = true;
                            mDeskApp -> isBat = false;
                            isPumpkin=false;
                            mBedApp->isPumpkin=false;
                            mDeskApp->isPumpkin=false;
                            break;
                        default:break;
                    }
                    break;
                case CONST::S9:
                    switch (getNowMission()) {
                        case CONST::MISSION1:
                            mLamp=true;
                            mBedApp -> mLamp = true;
                            mDeskApp -> mLamp = true;
                            
                            break;
                            
                        case CONST::MISSION2:
                            isBat = false;
                            mBedApp -> isBat =false;
                            mDeskApp -> isBat = true;
                            isPumpkin=false;
                            mDeskApp->isPumpkin=false;
                            mBedApp->isPumpkin=false;
                            break;
                        default:
                            break;
                    }
                    break;
                case CONST::S10:
                    switch (getNowMission()) {
                        case CONST::MISSION1:
                            hTower=true;
                            mBedApp -> hTower = true;
                            break;
                        case CONST::MISSION2:
                            isPumpkin = true;
                            mBedApp -> isPumpkin = false;
                            mDeskApp -> isPumpkin = false;
                            isBat=false;
                            mBedApp->isBat=false;
                            mDeskApp->isBat=false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:break;
            }
            int index = getIndex();
            index++;
            setIndex(index);
            if(getIndex() == mJudgeArray.size()){
                int mission = (int)getNowMission();
                mission++;
                mIsStartMission = false;
                changeMission((CONST::E_MISSION)mission);
            }
            
            //TODO:effect
        }else{
            //TODO:Miss effect
        }
        }
    }
    }
}






