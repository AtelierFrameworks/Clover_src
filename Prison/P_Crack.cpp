//
//  P_Crack.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/09/28.
//
//

#include "P_Crack.hpp"
static int crackCount;
void P_Crack::setup(){
    for(int i = 0;i<4;i++){
        string path = "Prison/Crack/1-" + std::to_string(i+1) + ".png";
        mImages[i].load(path);
    }
    crackCount = -1;
}

void P_Crack::draw(){
    mImages[crackCount].draw(0,0,ofGetWidth(),ofGetHeight());
}

void P_Crack::reset(){
    crackCount = -1;
   
}

void P_Crack::addCount(){
    if(crackCount < 3){
        crackCount++;
    }
}

int P_Crack::getCount(){
    return crackCount;
}
