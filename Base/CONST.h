//
//  CONST.h
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/09/02.
//
//
#pragma once
#ifndef CONST_h
#define CONST_h
#endif /* CONST_h */
class CONST{
public:
    enum E_SCENE {NONE,MAGIC,PRISON};
    // face
    enum E_APP {A_CURTAIN,A_DESK,A_FLOOR,A_BED};
    //to use arduino data
    enum E_PARTS{P_CURTAIN_OPEN,P_CURTAIN_CLOSE,P_CHAIR,P_SHELF,P_BED,LEAP};
    constexpr static const float gravity = 9.8;
    //to use check movie's ending
    enum E_GIMMICK{G_P_CHAIR,G_P_BED,G_M_CHAIR};
};
