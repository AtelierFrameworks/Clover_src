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
    void separateBytes();
    void judgeData();
    ofSerial mSerial;
    int nBytesRead = 0;
    string mBytesReadString;
    std::vector<int> mValue;
    bool mHasData;
    std::array<int,5> mPastTimeData{0,0,0,0,0};
    ofEvent<std::vector<CONST::E_PARTS>> mSendEvent;
    bool mIsMagicMove;
};
