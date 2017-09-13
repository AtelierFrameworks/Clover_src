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
#include "CONST.h"
#include <vector>
#include <array>
#endif /* ArduinoManager_hpp */
class ArduinoManager{
public:
    void setup();
    void update();
    void draw();
    bool getIsSetup();
    std::vector<int> getArduinoData();
    void separateBytes();
    ofSerial mSerial;
    int nBytesRead = 0;
    char mBytesReadString[30];
    std::vector<int> mData;
    std::array<int,4> mPastTimeData{0,0,0,0};
    std::vector<CONST::E_PARTS> judgeData();
};
