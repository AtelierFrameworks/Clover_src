#include "ofApp.h"
//カーテンゾーン
static int logNumber;
static bool isStartScene;
static bool isSetupArduino;

//--------------------------------------------------------------
void ofApp::setup(){
    
    mNowScene = MAGIC;
    
    //„É≠„Ç∞„Éï„Ç°„Ç§„É´‰ΩúÊàê
    mCam.setOrientation(ofPoint(-20, 0, 0));
    mLogDataFile.open("LogData.csv",ofFile::Append);
    isStartScene=false;
    //„Ç∑„Éº„É≥ÂàùÊúüÂåñ
    mScenes.clear();
    //TODO:ArduinoÈÄ£Êê∫
    isSetupArduino= false;
    mArduino.connect("/dev/cu.usbmodem1421",57600);
    ofAddListener(mArduino.EInitialized, this, &ofApp::setupArduino);
    setupLeapMotion();
}

//--------------------------------------------------------------
void ofApp::update(){
    updateLeapMotion();
    if(isStartScene){
        mScenes.at(0)->update();
    }
    if(isSetupArduino){
        updateArduino();
    }
    mLeap.markFrameAsOld();

}

//-----------------------

void ofApp::draw(){
    if(simpleHands.size() ){
        mCam.begin();
        ofVec2f p = simpleHands.at(0).fingers.at(INDEX).pos;
        ofSetColor(0);
        ofDrawSphere( simpleHands.at(0).fingers.at(INDEX).pos, 10);
        mCam.end();
    }
    if(isStartScene){
        mScenes.at(0)->draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(isStartScene){
        mScenes.at(0)->keyPressed(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(isStartScene){
        mScenes.at(0)->keyReleased(key);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if(isStartScene){
        mScenes.at(0)->mouseMoved(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(isStartScene){
        mScenes.at(0)->mouseDragged(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(isStartScene){
        mScenes.at(0)->mousePressed(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(isStartScene){
        mScenes.at(0)->mouseReleased(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    if(isStartScene){
        mScenes.at(0)->mouseEntered(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    if(isStartScene){
        mScenes.at(0)->mouseExited(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    if(isStartScene){
        mScenes.at(0)->windowResized(w, h);
    }
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    if(isStartScene){
        mScenes.at(0)->gotMessage(msg);
    }
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    if(isStartScene){
        mScenes.at(0)->dragEvent(dragInfo);
    }
}

void ofApp::exit(){
    isStartScene = false;
}

//„Ç´„Éº„ÉÜ„É≥
void ofApp::actionCurtain(){
    logNumber = 0;
    mLogDataFile << ofToString(logNumber) + "setup," + getLogDay() + "," + "curtain," + "NO" <<endl;
    //TODO: ‚Äû√á‚àë‚Äû√â¬∫‚Äû√â‚â•√à√Ö‚àè√ä√§√ª
    BaseScene * scene = new M_Scene();
    mScenes.push_back(scene);
    mScenes[0]->setup();
    isStartScene = true;
}

void ofApp::closeCurtain(){
    isStartScene = false;
    mScenes.clear();
}

void ofApp::setupArduino(const int & version){
    ofRemoveListener(mArduino.EInitialized,this,&ofApp::setupArduino);
    //TODO: „Éî„É≥Áï™Âè∑ËÅû„ÅèArduino
    mArduino.sendDigitalPinMode(2,ARD_INPUT);
    isSetupArduino = true;
}

void ofApp::updateArduino(){
    mArduino.update();
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
    if(isStartScene){
        mScenes.at(0)->setLeapData(simpleHands);
    }
}

string ofApp::getLogDay(){
     logNumber++;
    string logDay = ofToString(ofGetMonth()) + "/" + ofToString(ofGetDay()) + " " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds());
    return logDay;
}



