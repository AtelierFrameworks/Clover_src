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
#include "BaseApp.hpp"
class ArduinoManager{
public:
    void setup();
    void update();
    void draw();
    bool getIsSetup();
    void separateBytes();
    void judgeData();
    static int getLogNumber();
    static void setLogNumber(int num);
    static string getLogDay();
    ofSerial mSerial;
    int nBytesRead = 0;
    string mBytesReadString;
    std::vector<int> mValue;
    bool mHasData;
    ofEvent<std::vector<CONST::E_SENSOR>> mSendEvent;
    ofFile mLogDataFile;
};
