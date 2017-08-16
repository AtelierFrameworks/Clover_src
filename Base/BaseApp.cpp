//
//  BaseApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//

#include "BaseApp.hpp"

static BaseApp::E_SCENE nowScene;
 static int logNumber;

void BaseApp::setup(){
    mLogDataFile.open("LogData.csv",ofFile::Append);
}

//--------------------------------------------------------------
void BaseApp::update(){
    if(nowScene != NONE){
        mScenes.at(0)->update();
    }
}

//-----------------------

void BaseApp::draw(){
    if(nowScene != NONE){
        mScenes.at(0)->draw();
    }
}

//--------------------------------------------------------------
void BaseApp::keyPressed(int key){
    if(nowScene != NONE){
        mScenes.at(0)->keyPressed(key);
    }
}

//--------------------------------------------------------------
void BaseApp::keyReleased(int key){
    if(nowScene != NONE){
        mScenes.at(0)->keyReleased(key);
    }
}

//--------------------------------------------------------------
void BaseApp::mouseMoved(int x, int y ){
    if(nowScene != NONE){
        mScenes.at(0)->mouseMoved(x, y);
    }
}

//--------------------------------------------------------------
void BaseApp::mouseDragged(int x, int y, int button){
    if(nowScene != NONE){
        mScenes.at(0)->mouseDragged(x, y, button);
    }
}

//--------------------------------------------------------------
void BaseApp::mousePressed(int x, int y, int button){
    if(nowScene != NONE){
        mScenes.at(0)->mousePressed(x, y, button);
    }
}

//--------------------------------------------------------------
void BaseApp::mouseReleased(int x, int y, int button){
    if(nowScene != NONE){
        mScenes.at(0)->mouseReleased(x, y, button);
    }
}

//--------------------------------------------------------------
void BaseApp::mouseEntered(int x, int y){
    if(nowScene != NONE){
        mScenes.at(0)->mouseEntered(x, y);
    }
}

//--------------------------------------------------------------
void BaseApp::mouseExited(int x, int y){
    if(nowScene != NONE){
        mScenes.at(0)->mouseExited(x, y);
    }
}

//--------------------------------------------------------------
void BaseApp::windowResized(int w, int h){
    if(nowScene != NONE){
        mScenes.at(0)->windowResized(w, h);
    }
}

//--------------------------------------------------------------
void BaseApp::gotMessage(ofMessage msg){
    if(nowScene != NONE){
        mScenes.at(0)->gotMessage(msg);
    }
}

//--------------------------------------------------------------
void BaseApp::dragEvent(ofDragInfo dragInfo){
    if(nowScene != NONE){
        mScenes.at(0)->dragEvent(dragInfo);
    }
}

void BaseApp::exit(){
    nowScene = NONE;
}

BaseApp::E_SCENE BaseApp::getNowScene(){
    return nowScene;
}

string BaseApp::getLogDay(){
    logNumber++;
    string logDay = ofToString(ofGetMonth()) + "/" + ofToString(ofGetDay()) + " " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds());
    return logDay;
}

void BaseApp::setNowScene(BaseApp::E_SCENE scene){
    nowScene = scene;
    BaseScene * newScene;
}

int BaseApp::getLogNumber(){return logNumber;}
void BaseApp::setLogNumber(int num){logNumber = num;}
ArduinoManager BaseApp::getArduinoManager(){return mArduinoManager;}
void BaseApp::setArduinoManager(ArduinoManager manager){mArduinoManager = manager;}
