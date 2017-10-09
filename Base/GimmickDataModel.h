//
//  GimmickDataModel.h
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/24.
//
//
#pragma once
#ifndef GimmickDataModel_h
#define GimmickDataModel_h


#endif /* GimmickDataModel_h */
#include "ofMain.h"
#include "CONST.h"
class BaseApp;
class GimmickDataModel {
public:
    CONST::E_PARTS mParts;
    int judgementValue;
    CONST::E_SCENE mScene;
    CONST::E_APP mApp;
};
