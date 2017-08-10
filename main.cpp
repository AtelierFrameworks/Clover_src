#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofGLFWWindowSettings settings;
    
    settings.width = 1024;
    settings.height = 768;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 1920;
    settings.height = 1080;
    settings.setPosition(ofVec2f(1024,0));
    settings.resizable = true;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> bedWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    
    ofRunApp(mainWindow,mainApp);
    
    ofApp::E_SCENE scene = mainApp -> mNowScene;
    shared_ptr<B_BedApp> bedApp(new B_BedApp);
    if(scene == ofApp::MAGIC){
    }else{
        shared_ptr<B_BedApp> bedApp(new B_BedApp);
    }
    
    mainApp -> mBedApp = bedApp;
    
    ofRunApp(bedWindow,bedApp);
    
    ofRunMainLoop();
    
    
//    ofSetFullscreen(true);
//    ofSetWindowShape(1920,1080);
//    ofSetWindowPosition(0,1280);
    //ウィンドウ初期位置
 //   ofSetWindowPosition(0,0);
    //フルスクリーンにする
//    ofSetFullscreen(true);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());

}
