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
    mLogDataFile.open("LogData.csv",ofFile::WriteOnly);
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
    if(mValue[0] > 1 || mValue[1] > 1 ){
        mPastTimeData[0] ++;
        if(mPastTimeData[0] > 60){
            meisaiNum++;
            log = ofToString(getLogNumber())+ "," + ofToString(meisaiNum) + ",action," + getLogDay() + "," + "bed," + BaseApp::getSceneName();
            
            if(mIsCurtainOpen && !mIsPlayBed){
//                isActionParts.push_back(CONST::P_BED);
                mIsPlayBed = true;
                mPastFalseTime[0] = 0;
                log += ",YES";
            }else{
                log += ",NO";
            }
           mLogDataFile << log << endl;
        }
    }else{
        mPastTimeData[0] = 0;
        mPastFalseTime[0] ++;

        if(mIsPlayBed && mPastFalseTime[0] >= 60){
            mIsPlayBed = false;
        }
    }
    //chair
    if(mValue[2] > 5){
        mPastTimeData[1] ++;
        if(mPastTimeData[1] > 60){
            meisaiNum++;
            log = ofToString(getLogNumber())+ "," + ofToString(meisaiNum) + ",action," + getLogDay() + "," + "bed," + BaseApp::getSceneName();

            
            if(mIsCurtainOpen){
                isActionParts.push_back(CONST::P_CHAIR);
                log += ",YES";
            }else{
                log += ",NO";
            }
          mLogDataFile << log <<endl;
        }
    }else{
        mPastTimeData[1] = 0;
    }

    //shelf
    if(mValue[5] > 3 ){
        isActionParts.push_back(CONST::P_SHELF);
        mPastTimeData[2] ++;
        if(mPastTimeData[2] > 60){
            meisaiNum++;
           log = ofToString(getLogNumber())+ "," + ofToString(meisaiNum) + ",action," + getLogDay() + "," + "shelf," + BaseApp::getSceneName() ;
            if(mIsCurtainOpen){
            isActionParts.push_back(CONST::P_SHELF);
                log+= ",YES";
            }else{
                log+= ",NO";
            }
             mLogDataFile << log <<endl;
        }
    }else{
        mPastTimeData[2] = 0;
    }

    //curtain
    if(mValue[4] > 7){
        mPastTimeData[3] ++;
        if(mPastTimeData[3] > 60){
          
            logNumber++;
            meisaiNum = 0;
            log = ofToString(getLogNumber()) + "," + ofToString(meisaiNum) + ",setup," + getLogDay() + "," + "curtain," +  BaseApp::getSceneName();
            if(!mIsCurtainOpen){
            isActionParts.push_back(CONST::P_CURTAIN_OPEN);
                mIsCurtainOpen = true;
                log += ",YES";
            }else{
                log += ",NO";
            }
            
            mLogDataFile << log  <<endl;

        }
         }else{
             mPastTimeData[3] = 0;
             if(mValue[4] == 1 && mIsCurtainOpen){
                 mPastTimeData[3] ++;
                 if(mPastTimeData[4] > 60){
                    meisaiNum++;
                     log = ofToString(getLogNumber()) + "," + ofToString(meisaiNum) + ",exit," + getLogDay() + "," + "curtain,"+ BaseApp::getSceneName();
                     
                     if(mIsCurtainOpen){
                         mIsCurtainOpen = false;
                        log += ",YES";
                         isActionParts.push_back(CONST::P_CURTAIN_CLOSE);
                     }else{
                         log += ",NO";
                     }
                     mLogDataFile << log <<endl;
                 }
             }else{
                 mPastTimeData[4] = 0;
             }
    }
//    ofLogNotice() << "notify" << isActionParts;
    ofNotifyEvent(mSendEvent, isActionParts);
}



string ArduinoManager::getLogDay(){

    string logDay = ofToString(ofGetMonth()) + "/" + ofToString(ofGetDay()) + " " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds());
    return logDay;
}
int ArduinoManager::getLogNumber(){return logNumber;}
void ArduinoManager::setLogNumber(int num){logNumber = num;}
//void BaseApp::setArduinoManager(shared_ptr<ArduinoManager> manager){mArduinoManager = manager;}



