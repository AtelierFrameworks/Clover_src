//
//  BaseApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//

#include "BaseApp.hpp"

static CONST::E_MISSION nowMission;
static std::vector<CONST::E_SENSOR> nowSensor;

void BaseApp::setup(){
    ofBackground(80);
}

//--------------------------------------------------------------
void BaseApp::update(){
  
}

//-----------------------

void BaseApp::draw(){

}

//--------------------------------------------------------------
void BaseApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void BaseApp::keyReleased(int key){
 
}

//--------------------------------------------------------------
void BaseApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void BaseApp::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void BaseApp::mousePressed(int x, int y, int button){
 
}

//--------------------------------------------------------------
void BaseApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void BaseApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void BaseApp::mouseExited(int x, int y){
 
}

//--------------------------------------------------------------
void BaseApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void BaseApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void BaseApp::dragEvent(ofDragInfo dragInfo){
   }

void BaseApp::exit(){
  }



void BaseApp::freeToSceneMemory(){
    //    for(int i = 0; i< mScenes.size();i++){
    //        delete mScenes.at(i);
    //    }
    //    mScenes.clear();
}



void BaseApp::setMission(CONST::E_MISSION mission){
    nowMission = mission;
}

CONST::E_MISSION BaseApp::getNowMission(){
    return nowMission;
}

void BaseApp::setSensor(CONST::E_SENSOR sensor){
    nowSensor.push_back(sensor);
}

std::vector<CONST::E_SENSOR> BaseApp::getNowSensor(){
    return nowSensor;
}

std::vector<CONST::E_SENSOR> BaseApp::getJudgeArray(){
    std::vector<CONST::E_SENSOR> array;
    switch (getNowMission()) {
        case CONST::MISSION1:
            for (CONST::E_SENSOR sensor:CONST::ORDER_MISSION1) {
                array.push_back(sensor);
            }
            break;
        case CONST::MISSION2:
            for (CONST::E_SENSOR sensor:CONST::ORDER_MISSION2) {
                array.push_back(sensor);
            }
            break;
            case CONST::MISSION3:
            for (CONST::E_SENSOR sensor:CONST::ORDER_MISSION3) {
                array.push_back(sensor);
            }
            break;
        default:
            break;
    }
    return array;
}


