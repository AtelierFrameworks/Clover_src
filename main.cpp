
#include "Base/BaseApp.hpp"
#include "Base/ofApp.h"
#include "Base/B_BedApp.hpp"
//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    ofGLFWWindowSettings settings;
    
    settings.width = 1440;
    settings.height = 900;
    settings.setPosition(ofVec2f(0,0));
    settings.multiMonitorFullScreen = true;
    settings.decorated = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 1280;
    settings.height = 800;
    settings.setPosition(ofVec2f(1440,0));
    settings.resizable = true;
    settings.shareContextWith = mainWindow;
    settings.multiMonitorFullScreen = true;
    //メニューバーの非表示
    settings.decorated = false;
    shared_ptr<ofAppBaseWindow> bedWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    
   
    
    BaseApp::E_SCENE scene = mainApp -> getNowScene();
    shared_ptr<B_BedApp> bedApp(new B_BedApp);
//    if(scene == ofApp::MAGIC){
//    }else{
//   //     shared_ptr<B_BedApp> bedApp(new B_BedApp);
//    }
    
    mainApp -> mBedApp = bedApp;
    
    
    ofRunApp(mainWindow,mainApp);
    ofRunApp(bedWindow,bedApp);
    
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
