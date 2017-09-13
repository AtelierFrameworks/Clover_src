//
//  ArduinoManager.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/11.
//
//

#include "ArduinoManager.hpp"

const int BORDER_VALUE [] = { 0,0,0,0,0,0,0,0,0 };


void ArduinoManager::setup(){
    mSerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mSerial.getDeviceList();
    mSerial.setup(1,9600);
  
}

void ArduinoManager::update(){
    int nRead = 0;
    char bytesRead[50];
    unsigned char bytesReturned[50];
    
    memset(bytesReturned, 0, 50);
    memset(mBytesReadString, 0, 50);
    
    if(mSerial.isInitialized()){
        if(mSerial.available()){
            unsigned int i = 0;
            while ((nRead = mSerial.readBytes(bytesReturned, 50)) > 0) {
                nBytesRead = nRead;
                i++;
                ofLogNotice() << "num" << i;
                ofLogNotice() << "nRead" << nRead;
                ofLogNotice() << "value" <<  bytesReturned;
            };
            
           if (nBytesRead > 0) {
                memcpy(mBytesReadString, bytesReturned, 50);
                separateBytes();
            }
        }
    }
    
}

void ArduinoManager::separateBytes(){
    mData.clear();
    std::vector<string> result = ofSplitString(mBytesReadString, ",");
    for (string stringData:result) {
        mData.push_back(std::stoi(stringData));
        ofLogNotice() << "values" << std::stoi(stringData);
    }
}

std::vector<int> ArduinoManager::getArduinoData(){
    return mData;
}

bool ArduinoManager::getIsSetup(){
    return mSerial.isInitialized();
}

std::vector<CONST::E_PARTS> ArduinoManager:: judgeData(){
    std::vector <CONST::E_PARTS> isActionParts;
    //bed
    if((mData[0] < BORDER_VALUE[0] && mData[3] <= BORDER_VALUE[3] )||(mData[1] < BORDER_VALUE[1] && mData[4] <= BORDER_VALUE[4])||(mData[2] < BORDER_VALUE[2]&& mData[5]<=BORDER_VALUE[5])){
        mPastTimeData[0] ++;
        if(mPastTimeData[0] > 10){
            isActionParts.push_back(CONST::P_BED);
        }
    }else{
        mPastTimeData[0] = 0;
    }
    //chair
    if(mData[6] < BORDER_VALUE[6]){
        isActionParts.push_back(CONST::P_CHAIR);
        mPastTimeData[1] ++;
        if(mPastTimeData[1] > 10){
            isActionParts.push_back(CONST::P_CHAIR);
        }
    }else{
        mPastTimeData[1] = 0;
    }

    //shelf
    if(mData[7] < BORDER_VALUE[7]){
        isActionParts.push_back(CONST::P_SHELF);
        mPastTimeData[2] ++;
        if(mPastTimeData[2] > 10){
            isActionParts.push_back(CONST::P_SHELF);
        }
    }else{
        mPastTimeData[2] = 0;
    }

    //curtain
    if(mData[8] < BORDER_VALUE[8]){
        mPastTimeData[3] ++;
        if(mPastTimeData[3] > 10){
            isActionParts.push_back(CONST::P_CURTAIN);
        }
         }else{
        mPastTimeData[3] = 0;
    }

    return isActionParts;
}

