//
//  ArduinoManager.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//
#pragma once
#ifndef ArduinoManager_hpp
#define ArduinoManager_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ArduinoDataModel.hpp"
#include "CONST.h"
#endif /* ArduinoManager_hpp */
class ArduinoManager{
public:
    void setup();
    void update();
    void draw();

    bool getIsSetup();
    ArduinoDataModel getArduinoData(CONST::E_PARTS);
    ofSerial mSerial;
    int nBytesRead = 0;
    char bytesReadString[50];
//    int getArduinoDatas();
};
