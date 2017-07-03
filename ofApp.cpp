#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ログデータ保存用csvファイルの準備
    mLogDataFile.open("LogData.csv",ofFile::Append);
    isStartScene=false;
    //各自のシーンにP_SceneかM_Sceneか置き換える
    mScenes.clear();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(isStartScene){
        mScenes.at(0)->update();
    }
}

//-----------------------

void ofApp::draw(){
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

//カーテンが開いた時
void ofApp::actionCurtain(){
    logNumber = 0;
    mLogDataFile << ofToString(logNumber) + "setup," + getLogDay() + "," + "ofApp," + "NO" <<endl;
    //TODO: シーン選択
    BaseScene * scene = new M_Scene();
    mScenes.push_back(scene);
    mScenes[0]->setup();
    isStartScene = true;
}

void ofApp::closeCurtain(){
    isStartScene = false;
    mScenes.clear();
}

string ofApp::getLogDay(){
     logNumber++;
    string logDay = ofToString(ofGetMonth()) + "/" + ofToString(ofGetDay()) + " " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds());
    return logDay;
}



