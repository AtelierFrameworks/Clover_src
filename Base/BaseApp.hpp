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
#include <vector>
#include "CONST.h"
#include "ofMain.h"
#endif /* BaseApp_hpp */
class BaseApp : public ofBaseApp{
    
public:
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
    virtual void changeMission(){};
    virtual void endMovie(CONST::E_MOVIE & movie){};
    virtual void freeToSceneMemory();
    static void setMission(CONST::E_MISSION mission);
    static CONST::E_MISSION getNowMission();
    static void setSensor(CONST::E_SENSOR sensor);
    static std::vector<CONST::E_SENSOR> getNowSensor();
    static std::vector<CONST::E_SENSOR> getJudgeArray();
    static void setIndex(int index);
    static int getIndex();
    static void setIsMovie(bool isMovie);
    static bool getIsMovie();
    //void setArduinoManager(shared_ptr<ArduinoManager> manager);
    
protected:
   
    
    
};
