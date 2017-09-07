//
//  CONST.h
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/09/02.
//
//
#pragma once
#ifndef CONST_h
#define CONST_h
#endif /* CONST_h */
class CONST{
public:
    enum E_SCENE {NONE,MAGIC,PRISON};
    //投影する面
    enum E_APP {A_CURTAIN,A_DESK,A_FLOOR,A_BED};
    //家具
    enum E_PARTS{P_CURTAIN,P_CHAIR,P_SHELF,P_BED,LEAP};
    constexpr static const float gravity = 9.8;

};
