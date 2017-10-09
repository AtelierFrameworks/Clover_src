//
//  B_BedApp.cpp
//  Atelier_Room
//
//  Created by 池上綾乃 on 2017/08/10.
//
//

#include "B_BedApp.hpp"
void B_BedApp::setup(){
    BaseApp::setup();
    
}

//--------------------------------------------------------------
void B_BedApp::update(){
    BaseApp::update();
}

//--------------------------------------------------------------
void B_BedApp::draw(){
    BaseApp::draw();
}

//--------------------------------------------------------------
void B_BedApp::keyPressed(int key){
    BaseApp::keyPressed(key);
}

//--------------------------------------------------------------
void B_BedApp::keyReleased(int key){
    BaseApp::keyReleased(key);
}

//--------------------------------------------------------------
void B_BedApp::mouseMoved(int x, int y ){
    BaseApp::mouseMoved(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseDragged(int x, int y, int button){
    BaseApp::mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mousePressed(int x, int y, int button){
    BaseApp::mousePressed(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseReleased(int x, int y, int button){
    BaseApp::mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void B_BedApp::mouseEntered(int x, int y){
    BaseApp::mouseEntered(x, y);
}

//--------------------------------------------------------------
void B_BedApp::mouseExited(int x, int y){
    BaseApp::mouseExited(x, y);
}

//--------------------------------------------------------------
void B_BedApp::windowResized(int w, int h){
    BaseApp::windowResized(w, h);
}

//--------------------------------------------------------------
void B_BedApp::gotMessage(ofMessage msg){
    BaseApp::gotMessage(msg);
}

//--------------------------------------------------------------
void B_BedApp::dragEvent(ofDragInfo dragInfo){
    BaseApp::dragEvent(dragInfo);
}

void B_BedApp::changeScene(){
    BaseScene *newScene;
   
    switch (getNowScene()) {
        case CONST::PRISON:
            newScene = new P_BedScene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            ofAddListener(mScenes[0]->mEndMovieEvent,this,&B_BedApp::endMovie);
            break;
        case CONST::MAGIC:
            newScene = new M_BedScene();
            mScenes.push_back(newScene);
            mScenes[0]->setup();
            ofAddListener(mScenes[0]->mEndMovieEvent,this,&B_BedApp::endMovie);
            ofAddListener(dynamic_cast<M_BedScene*>(mScenes[0])->mStairEvent,this,&B_BedApp::stairEvent);
            break;
        case CONST::NONE:
            
            mScenes[0] -> exit();
            ofRemoveListener(mScenes[0]->mEndMovieEvent,this,&B_BedApp::endMovie);
            if(getPreScene() == CONST::MAGIC){
                ofRemoveListener(dynamic_cast<M_BedScene*>(mScenes[0])->mStairEvent,this,&B_BedApp::stairEvent);
            }
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

void B_BedApp::actionBed(){
    mScenes[0] -> actionBed();
}

void B_BedApp::endMovie(CONST::E_GIMMICK & gimmick){
//  ofRemoveListener(mScenes[0]->mEndMovieEvent,this,&B_BedApp::endMovie);
    CONST::E_GIMMICK e_gimmick = gimmick;
    ofNotifyEvent(mMovieEndEvent, e_gimmick);
}

void B_BedApp::setLeapData(std::vector <ofxLeapMotionSimpleHand> simpleHands){
    mScenes[0] -> setLeapData(simpleHands);
}

void B_BedApp::stairEvent(bool & flg){
    bool a = flg;
    ofNotifyEvent(mStairEvent,a);
}
