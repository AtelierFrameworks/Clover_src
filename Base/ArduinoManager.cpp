//
//  ArduinoManager.cpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/11.
//
//

#include "ArduinoManager.hpp"

 static int logNumber = 0;
static int meisaiNum  = 0;

void ArduinoManager::setup(){
    mSerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mSerial.getDeviceList();
    mSerial.setup(1,38400);
    mValue.clear();
    mHasData = false;
    mIsCurtainOpen = false;
    mIsPlayBed = false;
    mIsPlayChair = false;
    mIsPlayShelf = false;
    mLogDataFile.open("LogData.csv",ofFile::Append);
    meisaiNum = 0;

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
               
                mBytesReadString = string((char*)bytesReturned);
                ofLogNotice() << "value" <<  bytesReturned;
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
    std::vector <CONST::E_PARTS> isActionParts;
    for(int data :mValue){
        int modData = data % 2;
        //反応あるかどうか
        if(modData == 0){
            isPush = true;
            data = data / 2 -1;
            sensor = (CONST::E_SENSOR)data;
        }
    }
    ofNotifyEvent(mSendEvent, isActionParts);
}



string ArduinoManager::getLogDay(){

    string logDay = ofToString(ofGetMonth()) + "/" + ofToString(ofGetDay()) + " " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds());
    return logDay;
}
int ArduinoManager::getLogNumber(){return logNumber;}
void ArduinoManager::setLogNumber(int num){logNumber = num;}



