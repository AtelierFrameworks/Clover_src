//
//  B_FloorApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_FloorApp.hpp"
void B_FloorApp::setup(){
    BaseApp::setup();
    
}

//--------------------------------------------------------------
void B_FloorApp::update(){
    BaseApp::update();
}

//--------------------------------------------------------------
void B_FloorApp::draw(){
    BaseApp::draw();
}

//--------------------------------------------------------------
void B_FloorApp::keyPressed(int key){
    BaseApp::keyPressed(key);
}

//--------------------------------------------------------------
void B_FloorApp::keyReleased(int key){
    BaseApp::keyReleased(key);
}

//--------------------------------------------------------------
void B_FloorApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_FloorApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_FloorApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_FloorApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_FloorApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_FloorApp::changeScene(){
    BaseScene *newScene;

    switch (getNowScene()) {
        case CONST::PRISON:
            newScene = new P_floor();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            break;
        case CONST::MAGIC:
            newScene = new M_FloorScene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            ofAddListener(mScenes[0]->mEndMovieEvent,this,&B_FloorApp::endMovie);
            break;
        case CONST::NONE:
           mScenes[0] -> exit();
            if(getPreScene() == CONST::MAGIC){
                ofRemoveListener(mScenes[0]->mEndMovieEvent,this,&B_FloorApp::endMovie);            }
//            delete mScenes[0];
            mScenes.clear();
            ofBackground(80);
            break;
        default:
            break;
    }
//    if(mScenes.size() > 1){
//        delete mScenes[0];
//        mScenes.erase(mScenes.begin());
//    }
    }


void B_FloorApp::endMovie(CONST::E_GIMMICK & gimmick){
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mMovieEndEvent, e_gimmick);
}




