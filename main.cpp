
#include "Base/BaseApp.hpp"
#include "Base/ofApp.h"
#include "Base/B_BedApp.hpp"
#include "Base/B_DeskApp.hpp"
#include "Base/B_FloorApp.hpp"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
  
    ofGLFWWindowSettings settings;
    
    settings.width = 1280;
    settings.height = 1000;
//    settings.setPosition(ofVec2f(-1280,0));
    settings.setPosition(ofVec2f(0,0));
    settings.multiMonitorFullScreen = true;
    settings.decorated = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    settings.setPosition(ofVec2f(2560,0));
    settings.resizable = true;
    settings.shareContextWith = mainWindow;
    settings.multiMonitorFullScreen = false;
    //メニューバーの非表示
    settings.decorated = false;
    shared_ptr<ofAppBaseWindow> bedWindow = ofCreateWindow(settings);
    settings.setPosition(ofVec2f(3840,0));
    shared_ptr<ofAppBaseWindow> deskWindow = ofCreateWindow(settings);
    settings.setPosition(ofVec2f(5120,0));
    shared_ptr<ofAppBaseWindow> floorWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<B_BedApp> bedApp(new B_BedApp);
    shared_ptr<B_DeskApp> deskApp(new B_DeskApp);
    shared_ptr<B_FloorApp> floorApp(new B_FloorApp);

    mainApp -> mBedApp = bedApp;
    mainApp -> mDeskApp = deskApp;
    mainApp -> mFloorApp = floorApp;
    ofRunApp(bedWindow,bedApp);
    ofRunApp(deskWindow,deskApp);
    ofRunApp(floorWindow,floorApp);
    ofRunApp(mainWindow,mainApp);

    ofRunMainLoop();
    

//    ofSetWindowShape(1920,1080);
//    ofSetWindowPosition(0,1280);
    //ウィンドウ初期位置
  //  ofSetWindowPosition(0,0);
    //フルスクリーンにする
//    ofSetFullscreen(true);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
//	ofRunApp(new ofApp());

}
