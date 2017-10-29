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
    
    //Mission1
    ofImage town;
    
    ofImage lamp;
    ofImage houselight;
    ofImage tree;
    ofImage pampukin;
    
    ofImage mouse;
    ofImage horse;
    
    bool mLamp;
    bool eHouselight;
    bool dTree;
    bool rPampukin;
    bool hTower;



};
