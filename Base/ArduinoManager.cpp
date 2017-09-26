//
//  ArduinoManager.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/11.
//
//

#include "ArduinoManager.hpp"

const int BORDER_VALUE [] = { 0,0,0,1,1,1,0,0,0,0 };


void ArduinoManager::setup(){
    mSerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mSerial.getDeviceList();
    mSerial.setup(1,9600);
    mValue.clear();
    mHasData = false;
}

void ArduinoManager::update(){
    int nRead = 0;
    char bytesRead[50];
    unsigned char bytesReturned[50];
    
    memset(bytesReturned, 0, 50);
    
    if(mSerial.isInitialized()){
        if(mSerial.available() > 0){
            int available = mSerial.available();
            ofLogNotice() << "available" << mSerial.available();
            while ((nRead = mSerial.readBytes(bytesReturned, 50)) > 0) {
                nBytesRead = nRead;
                ofLogNotice() << "nRead" << nRead;
                ofLogNotice() << "value" <<  bytesReturned;
                mBytesReadString = string((char*)bytesReturned);
                separateBytes();
            };
//            mSerial.flush();
            
        }
    }
}

void ArduinoManager::separateBytes(){
    std::vector<string> result = ofSplitString(mBytesReadString, ",");
    
    for (string stringData:result) {
       
        if(stringData=="{"){
            mHasData = true;
             ofLogNotice() << "string" << stringData;
            mValue.clear();
            
        }else if(stringData == "}" && mHasData){
            judgeData();
            mHasData = false;
            }else{
                if(stringData !="" && mHasData){
                    try{
                        ofLogNotice() << "data" << stringData;
                        int data = std::stoi(stringData);
                        mValue.push_back(data);
                    }catch(const invalid_argument& e){
                         
                        ofLogNotice() << "error" << stringData;
                        if(stringData == "}0" || stringData == "}1"){
                            judgeData();
                            mValue.clear();
                         std::vector<string> errorData = ofSplitString(stringData, "}");
                            try{
                                mValue.push_back(std::stoi(errorData.at(0)));
                            }catch(const invalid_argument& a){
                                
                            }
                        }
                    }
                }

        }
    }
}



bool ArduinoManager::getIsSetup(){
    return mSerial.isInitialized();
}

void ArduinoManager:: judgeData(){
    ofLogNotice() << "judge" << mValue.size() ;
    string log ;
    if(mValue.size() > 9){
        for(int value :mValue){
            log += ofToString(value) + ",";
        }
        ofLogNotice() << "over" << log;
    }
    std::vector <CONST::E_PARTS> isActionParts;
    //bed
    if((mValue[0] < BORDER_VALUE[0] && mValue[3] == BORDER_VALUE[3] )||(mValue[1] < BORDER_VALUE[1] && mValue[4] == BORDER_VALUE[4])||(mValue[2] < BORDER_VALUE[2]&& mValue[5]==BORDER_VALUE[5])){
        mPastTimeData[0] ++;
        if(mPastTimeData[0] > 10){
            isActionParts.push_back(CONST::P_BED);
        }
    }else{
        mPastTimeData[0] = 0;
    }
    //chair
    if(mValue[6] < BORDER_VALUE[6]){
        isActionParts.push_back(CONST::P_CHAIR);
        mPastTimeData[1] ++;
        if(mPastTimeData[1] > 10){
            isActionParts.push_back(CONST::P_CHAIR);
        }
    }else{
        mPastTimeData[1] = 0;
    }

    //shelf
    if(mValue[7] < BORDER_VALUE[7]){
        isActionParts.push_back(CONST::P_SHELF);
        mPastTimeData[2] ++;
        if(mPastTimeData[2] > 10){
            isActionParts.push_back(CONST::P_SHELF);
        }
    }else{
        mPastTimeData[2] = 0;
    }

    //curtain
    if(mValue[8] < BORDER_VALUE[8]){
        mPastTimeData[3] ++;
        if(mPastTimeData[3] > 10){
            isActionParts.push_back(CONST::P_CURTAIN_OPEN);
        }
         }else{
             mPastTimeData[3] = 0;
             if(mValue[8] < BORDER_VALUE[9]){
                 mPastTimeData[3] ++;
                 if(mPastTimeData[4] > 10){
                     isActionParts.push_back(CONST::P_CURTAIN_CLOSE);
                 }
             }else{
                 mPastTimeData[4] = 0;
             }
    }
//    ofLogNotice() << "notify" << isActionParts;
    ofNotifyEvent(mSendEvent, isActionParts);
}

