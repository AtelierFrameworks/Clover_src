//
//  P_BedScene.hpp
//  Atelier_Room
//
//  Created by USER1 on 2017/08/31.
//
//

#ifndef P_BedScene_hpp
#define P_BedScene_hpp

#include <stdio.h>

#endif /* P_BedScene_hpp */
class ofApp : public ofBaseApp{
    
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
    ofVideoPlayer fingersMovie;
    bool                frameByframe;
    ofImage myImage;
};
