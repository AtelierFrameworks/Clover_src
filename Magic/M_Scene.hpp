//
//  M_Scene.hpp
//  Atelier_Room
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/08/17.
//
//

#ifndef M_Scene_hpp
#define M_Scene_hpp

#include <stdio.h>

#endif /* M_Scene_hpp */
#include "BaseScene.hpp"

class M_Scene : public BaseScene{
    void setup();
    void setupClock();
    void update();
    void updateClock();
    void draw();
    void drawClock();
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
    
    void actionDesk();
    void actionChair();
    void actionBed();
    void actionShelf();
    ofImage magic_kabe;
    float px;
    float py;
    
    //時計等
    //ofImage frameImage; //画像ファイルより読みこまれたイメージデータ
    //ofImage JoImage;
    ofImage ClockImage;
    
    double centerx, centery;
    double needleLx, needleLy;
    double needleSx, needleSy;
    
    ofSoundPlayer BellSound;
    
};
