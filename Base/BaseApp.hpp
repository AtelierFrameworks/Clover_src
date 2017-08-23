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
#include "BaseScene.hpp"
#endif /* BaseApp_hpp */
class ofApp;
class BaseApp : public ofBaseApp{
    
public:
    enum E_SCENE {NONE,MAGIC,PRISON};

    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    virtual void mouseMoved(int x, int y );
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    virtual void mouseEntered(int x, int y);
    virtual void mouseExited(int x, int y);
    virtual void windowResized(int w, int h);
    virtual void dragEvent(ofDragInfo dragInfo);
    virtual void gotMessage(ofMessage msg);
    virtual void exit();
    virtual void changeScene(){};
    static E_SCENE getNowScene();
    static void setNowScene(E_SCENE);
    static int getLogNumber();
    static void setLogNumber(int num);
    ArduinoManager getArduinoManager();
    void setArduinoManager(ArduinoManager manager);
    shared_ptr<ofApp> getOfApp();
    shared_ptr<ofApp> mApp;
   protected:
    static string getLogDay();
    std::vector<BaseScene *> mScenes;
    ofFile mLogDataFile;
    ArduinoManager mArduinoManager;
    
};
