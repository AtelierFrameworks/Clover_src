//
//  P_BedScene.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/17.
//
//

#ifndef P_BedScene_hpp
#define P_BedScene_hpp

#include <stdio.h>
#include "P_Crack.hpp"
#endif /* P_BedScene_hpp */

#include "BaseScene.hpp"
class P_BedScene : public BaseScene{
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void endMovieEvent(CONST::E_GIMMICK & gimmick);
    void actionChair();
    void actionBed();
    void actionShelf();
    void exit();
private:
    ofVideoPlayer fingersMovie;
    ofImage mBackground;
    bool mIsKeyPressed;
    bool mIsPlayChair;
    bool mIsPlayBed;
    bool mIsPlayShelf;
    ofImage shadow;

    int i;
    int j;
    
    float x,y,time;
    
    P_Crack mCrack;
};
