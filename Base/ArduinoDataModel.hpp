//
//  ArduinoDataModel.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//
#pragma once
#ifndef ArduinoDataModel_hpp
#define ArduinoDataModel_hpp

#include <stdio.h>

#endif /* ArduinoDataModel_hpp */
class ArduinoDataModel{
    
public:
    enum E_PARTS{CURTAIN,CHAIR,SHELF,BED};
    //どの家具からのデータか
    E_PARTS mParts;
    float mValue;
};
