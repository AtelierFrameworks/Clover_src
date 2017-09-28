//
//  P_Crack.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/09/28.
//
//

#ifndef P_Crack_hpp
#define P_Crack_hpp

#include <stdio.h>
#include <string>
#include "ofMain.h"
#endif /* P_Crack_hpp */
class P_Crack{
public:
    void setup();
    void draw();
    static int getCount();
    static void addCount();
    static void reset();
private:
    
     ofImage mImages[4];
};
