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
#endif /* ArduinoManager_hpp */
class ArduinoManager{
public:
    void setup();
    void update();
    void draw();
    void setupArduino(const int & version);
    static bool getIsSetup();
    ArduinoDataModel getArduinoData(ArduinoDataModel::E_PARTS);
    ofArduino mArduino;
   

};
