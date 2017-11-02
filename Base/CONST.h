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
#include <array>
class CONST{
public:
    enum E_MISSION{MISSION1,MISSION2,MISSION3,WIN,LOSE};
    enum E_APP {A_CURTAIN,A_DESK,A_FLOOR,A_BED};
    //to use arduino data
    enum E_SENSOR{S1,S2,S3,S4,S5,S6,S7,S8,S9,S10};
    constexpr static const float gravity = 9.8;
    //to use check movie's ending
    enum E_GIMMICK{G_P_CHAIR,G_P_BED,G_M_CHAIR,G_M_BED};
    enum E_MOVIE{M1,M2,M3,MWIN,MLOSE};
    constexpr static  std::array<E_SENSOR,5> ORDER_MISSION1 = {S9,S6,S7,S10,S8};
    constexpr static  std::array<E_SENSOR, 6> ORDER_MISSION2 = {S4,S7,S9,S8,S10};
    constexpr static  std::array<E_SENSOR,6> ORDER_MISSION3 = {S1,S2,S3,S4,S5,S1};
};
