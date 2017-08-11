//
//  ArduinoManager.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//

#include "ArduinoManager.hpp"


static bool isSetupArduino;
void ArduinoManager::setup(){
    //TODO:ArduinoÈÄ£Êê∫
    isSetupArduino= true;
    mArduino.connect("/dev/cu.usbmodem1411",57600);
    ofAddListener(mArduino.EInitialized, this, &ArduinoManager::setupArduino);
}

void ArduinoManager::update(){
    mArduino.update();
    if(isSetupArduino){
        float value = mArduino.getAnalog(0);
        ofLogNotice() << "value: " << value;
    }
}



void ArduinoManager::setupArduino(const int & version){
    ofRemoveListener(mArduino.EInitialized,this,&ArduinoManager::setupArduino);
    //TODO: To check used Arduino's pin
    //Pressure
    mArduino.sendAnalogPinReporting(0, ARD_ANALOG);
    isSetupArduino = true;
}

ArduinoDataModel ArduinoManager::getArduinoData(ArduinoDataModel::E_PARTS parts){
    ArduinoDataModel model = *new ArduinoDataModel();
    switch(parts){
        case ArduinoDataModel::CURTAIN :
            break;
        case ArduinoDataModel::CHAIR:
            break;
        case ArduinoDataModel::BED:
            break;
        default:break;
    }
    return model;
}

bool ArduinoManager::getIsSetup(){
    return isSetupArduino;
}
