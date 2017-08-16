//
//  M_BedScene.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/06/11.
//
//
//魔法図書館シーン
#ifndef M_BedScene_hpp
#define M_BedScene_hpp
#include "BaseScene.hpp"
#include <stdio.h>

#endif /* M_BedScene_hpp */
class M_BedScene : public BaseScene{
public:
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
    void startBed();
    void endBed();

};
