#include "ofApp.h"
//カーテンゾーン
static bool isStartScene;

//--------------------------------------------------------------
void ofApp::setup(){
    BaseApp::setup();
    mArduinoManager.setup();
    mBedApp -> setArduinoManager(mArduinoManager);
    setNowScene(BaseApp::NONE);
    ofSetBackgroundColor(0);
    //„É≠„Ç∞„Éï„Ç°„Ç§„É´‰ΩúÊàê
        isStartScene=false;
    //„Ç∑„Éº„É≥ÂàùÊúüÂåñ
    mScenes.clear();
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
    mArduinoManager.update();
    
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
    isStartScene = false;
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
    setLogNumber(0);
    mLogDataFile << ofToString(getLogNumber()) + "setup," + getLogDay() + "," + "curtain," + "NO" <<endl;
    //TODO: ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•√à√Ö‚àè√ä√§√ª
    int sceneNum = ofRandom(2)+1;
    setNowScene((BaseApp::E_SCENE)sceneNum);
    changeScene();
}

void ofApp::closeCurtain(){
    isStartScene = false;
    mScenes.clear();
}


void ofApp::changeScene(){
    BaseScene *newScene;
    switch (getNowScene()) {
        case BaseApp::PRISON:
            newScene = new P_Scene();
            break;
        case BaseApp::MAGIC:
            newScene = new M_BedScene();
        case BaseApp::NONE:
            break;
        default:
            break;
    }
    mScenes.push_back(newScene);
    mScenes[0]->setup();
    mBedApp -> changeScene();
    //    mDeskApp -> changeScene();
    //    mFloorApp -> changeScene();
}



