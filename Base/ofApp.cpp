#include "ofApp.h"
//カーテンゾーン
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    for(int i = 0; i < 5;i++){
        mIsAction[i] = false;
    }
    setupLeapMotion();
    mArduinoManager.setup();
    setNowScene(CONST::NONE);
    ofSetBackgroundColor(0);
    //„É≠„Ç∞„Éï„Ç°„Ç§„É´‰ΩúÊàê
    isStartScene=false;
    //„Ç∑„Éº„É≥ÂàùÊúüÂåñ
    mScenes.clear();
    actionCurtain();
    //TODO::setJudgeModel
    ofAddListener(mBedApp ->mMovieEndEvent, this, &ofApp::endMovie);
}

//--------------------------------------------------------------
void ofApp::update(){
    updateLeapMotion();
    mArduinoManager.update();
    int data = 0;
//    int data = mArduinoManager.getArduinoDatas();
    if(mArduinoManager.getIsSetup()){
        if(data < 600 /*&& data > 0*/){
            if(!mIsAction[0]){
                //TODO::データの分解
                mBedApp -> actionBed();
            }
        }
    }
    BaseApp::update();
}

//-----------------------

void ofApp::draw(){
    BaseApp::draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    BaseApp::keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    BaseApp::keyReleased(key);
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
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
    setLogNumber(0);
    mLogDataFile << ofToString(getLogNumber()) + ",setup," + getLogDay() + "," + "curtain," + "NO" <<endl;
    //TODO: ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•√à√Ö‚àè√ä√§√ª
    int sceneNum = ofRandom(2)+1;
    //setNowScene((BaseApp::E_SCENE)sceneNum);
    setNowScene(CONST::MAGIC);
    changeScene();
}

void ofApp::closeCurtain(){
    mLogDataFile << ofToString(getLogNumber()) + ",exit," + getLogDay() + "," + "curtain," + "NO" <<endl;
    setNowScene(CONST::NONE);
    freeToSceneMemory();
    mBedApp -> freeToSceneMemory();
    mDeskApp -> freeToSceneMemory();
    mFloorApp -> freeToSceneMemory();
}

void ofApp::sendAction(CONST::E_APP app){
    switch (getNowScene()) {
        case CONST::PRISON:
            switch (app) {
                case CONST::A_BED:
                    break;
                case CONST::A_CURTAIN:
                    break;
                case CONST::A_DESK:
                    break;
                case CONST::A_FLOOR:
                    break;
                default:
                    break;
            }
            break;
        case CONST::MAGIC:
            switch (app) {
                case CONST::A_BED:
                    ofLogNotice() << "bed" << 0;
                    break;
                case CONST::A_CURTAIN:
                    break;
                case CONST::A_DESK:
                    break;
                case CONST::A_FLOOR:
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}


void ofApp::changeScene(){
    BaseScene *newScene;
    switch (getNowScene()) {
        case CONST::PRISON:
            newScene = new P_Scene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            break;
        case CONST::MAGIC:
            newScene = new M_Scene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            break;
        case CONST::NONE:
            mScenes.clear();
            break;
        default:
            break;
    }
       mBedApp -> changeScene();
    //    mDeskApp -> changeScene();
    //    mFloorApp -> changeScene();
}


void ofApp::setupLeapMotion(){
    mLeap.open();
}

void ofApp::updateLeapMotion(){
    simpleHands = mLeap.getSimpleHands();
    if( mLeap.isFrameNew() && simpleHands.size() ){
        // 画面の大きさにあわせて、スケールをマッピング
        mLeap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        mLeap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        mLeap.setMappingZ(-150, 150, -200, 200);
    }
        mLeap.markFrameAsOld();
}

void ofApp::endMovie(CONST::E_APP & app){
    switch(getNowScene()){
        case CONST::PRISON:
            switch (app) {
                case CONST::A_BED:
                    break;
                case CONST::A_CURTAIN:
                    break;
                case CONST::A_DESK:
                    break;
                case CONST::A_FLOOR:
                    break;
                default:
                    break;
            }
            break;
        case CONST::MAGIC:
            switch (app) {
                case CONST::A_BED:
                    ofLogNotice() << "bedAction!" << 0;
                    break;
                case CONST::A_CURTAIN:
                    break;
                case CONST::A_DESK:
                    break;
                case CONST::A_FLOOR:
                    break;
                default:
                    break;
            }
            break;
        default:break;
    }
}





