//
//  BaseApp.hpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/11.
//
//
#pragma once
#ifndef BaseApp_hpp
#define BaseApp_hpp

#include <stdio.h>
#include "ArduinoManager.hpp"
#include <vector>

#endif /* BaseApp_hpp */
class BaseApp : public ofBaseApp{
    
public:
    enum E_SCENE {NONE,MAGIC,PRISON};

    virtual void setup();
//    virtual void update(){};
//    virtual void draw(){};
//    virtual void keyPressed(int key){};
//    virtual void keyReleased(int key){};
//    virtual void mouseMoved(int x, int y ){};
//    virtual void mouseDragged(int x, int y, int button){};
//    virtual void mousePressed(int x, int y, int button){};
//    virtual void mouseReleased(int x, int y, int button){};
//    virtual void mouseEntered(int x, int y){};
//    virtual void mouseExited(int x, int y){};
//    virtual void windowResized(int w, int h){};
//    virtual void dragEvent(ofDragInfo dragInfo){};
//    virtual void gotMessage(ofMessage msg){};
    static E_SCENE getNowScene();
    static void setNowScene(E_SCENE);
    static int getLogNumber();
    static void setLogNumber(int num);
   protected:
    static string getLogDay();
          
    ofFile mLogDataFile;
    ArduinoManager mArduinoManager;
    
};
