//
//  ArduinoManager.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//

#include "ArduinoManager.hpp"



void ArduinoManager::setup(){
    //TODO:ArduinoÈÄ£Êê∫
    mSerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mSerial.getDeviceList();
    // シリアル通信開始
    mSerial.setup(1,9600);
}

void ArduinoManager::update(){
    int nRead = 0;
    char bytesRead[50];
    unsigned char bytesReturned[50];
    
    memset(bytesReturned, 0, 50);
    memset(bytesReadString, 0, 50);
    
    if(mSerial.isInitialized()){
        if(mSerial.available()){
            // シリアル通信で受け取ったデータを読み込む
            while ((nRead = mSerial.readBytes(bytesReturned, 50)) > 0) {
                nBytesRead = nRead;
            };
            
            if (nBytesRead > 0) {
                memcpy(bytesReadString, bytesReturned, 50);
                string x = bytesReadString;
                ofLogNotice() << "value" << x;
            }
        }
    }

}


ArduinoDataModel ArduinoManager::getArduinoData(CONST::E_PARTS parts){
    ArduinoDataModel model = *new ArduinoDataModel();
    switch(parts){
        case CONST::P_CURTAIN:
            break;
        case CONST::P_CHAIR:
            break;
        case CONST::P_BED:
            break;
        case CONST::P_SHELF:
            break;
        default:break;
    }
    return model;
}

bool ArduinoManager::getIsSetup(){
    return mSerial.isInitialized();
}


