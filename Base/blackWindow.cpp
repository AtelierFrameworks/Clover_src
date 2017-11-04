//
//  blackWindow.cpp
//  Clover
//
//  Created by AtelierFrameworks on 2017/11/04.
//
//

#include "blackWindow.hpp"
void blackWindow::setup(){
    ofBackground(0) ;
    black.load("blackground.png");
}

void blackWindow::draw(){
    ofSetColor(0,0,0,255);
    black.draw(0, 0, ofGetWidth(),ofGetHeight());
}
