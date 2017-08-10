//
//  B_BedApp.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#ifndef B_BedApp_hpp
#define B_BedApp_hpp

#include <stdio.h>
#include "ofMain.h"
#endif /* B_BedApp_hpp */

class B_BedApp : public ofBaseApp{
    
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
    
};
