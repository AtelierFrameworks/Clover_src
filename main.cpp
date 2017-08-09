#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofAppGLFWWindow win;
    ofSetupOpenGL(&win, 1920+1024,1080+768, OF_WINDOW);
//    ofSetFullscreen(true);
//    ofSetWindowShape(1920,1080);
//    ofSetWindowPosition(0,1280);
    //ウィンドウ初期位置
    ofSetWindowPosition(1441,0);
    //フルスクリーンにする
    ofSetFullscreen(true);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
