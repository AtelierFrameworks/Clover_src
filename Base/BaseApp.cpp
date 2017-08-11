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
}

int BaseApp::getLogNumber(){return logNumber;}
void BaseApp::setLogNumber(int num){logNumber = num;}

