#include "ofApp.h"
//カーテンゾーン
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    mBgm.setLoop(true);
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
    ofAddListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
    ofAddListener(mBedApp -> mStairEvent,this,&ofApp::magicStair);
}

//--------------------------------------------------------------
void ofApp::update(){
    updateLeapMotion();
    mArduinoManager.update();
    int data = 0;
//    int data = mArduinoManager.getArduinoDatas();
    if(mArduinoManager.getIsSetup()){
//        if(data < 600 /*&& data > 0*/){
//            if(!mIsAction[0]){
//                //TODO::データの分解
//                mBedApp -> actionBed();
//            }
//        }
    
        
    }
    BaseApp::update();
}

//bool ofApp::judgeGimmick(){
//    std::vector<int> value = mArduinoManager.getArduinoData();
//    return true;
//}

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
    ofRemoveListener(mArduinoManager.mSendEvent,this,&ofApp::receiveData);
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
    setLogNumber(0);
    mLogDataFile << ofToString(getLogNumber()) + ",setup," + getLogDay() + "," + "curtain," + "NO" <<endl;
    //TODO: ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•√à√Ö‚àè√ä√§√ª
    int sceneNum = ofRandom(2)+1;
    //setNowScene((BaseApp::E_SCENE)sceneNum);
    setNowScene(CONST::PRISON);
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


void ofApp::changeScene(){
    BaseScene *newScene;
    switch (getNowScene()) {
        case CONST::PRISON:
            mBgm.load("Prison/P_bgm.mp3");
            mBgm.play();
            newScene = new P_Scene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            break;
        case CONST::MAGIC:
            mBgm.load("Magic/M_bgm.mp3");
            mBgm.play();
            newScene = new M_Scene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            break;
        case CONST::NONE:
            mBgm.stop();
            mScenes.clear();
            break;
        default:
            break;
    }
    mBedApp   -> changeScene();
    mDeskApp  -> changeScene();
    mFloorApp -> changeScene();
}


void ofApp::setupLeapMotion(){
    mLeap.open();
}

void ofApp::updateLeapMotion(){
    simpleHands = mLeap.getSimpleHands();
    switch (getNowScene()) {
        case CONST::PRISON:
            mFloorApp -> setLeapData(simpleHands);
            break;
        case CONST::MAGIC:
            mBedApp -> setLeapData(simpleHands);
            break;
        default:
            break;
    }
    
    if( mLeap.isFrameNew() && simpleHands.size()){
        // 画面の大きさにあわせて、スケールをマッピング
//        mLeap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
//        mLeap.setMappingX(-200, 230, -280, ofGetWidth());
//        mLeap.setMappingY(90, 490, 50, ofGetHeight()/2);
//        mLeap.setMappingZ(-150, 150, 0, 200);
//        mLeap.setMappingY(90, 490, 450, ofGetHeight());
//        mLeap.setMappingZ(-150, 150, -200, 200);
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
            mDeskApp -> mScenes.at(0) -> actionEndMovie();
            break;
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
                        mDeskApp -> mScenes.at(0) -> actionDesk();
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

void ofApp::magicStair(bool & flg){
    mScenes.at(0) -> actionBed();
    mDeskApp -> mScenes.at(0) -> actionBedNext();
    mBedApp -> mScenes.at(0) -> actionBedNext();
}




