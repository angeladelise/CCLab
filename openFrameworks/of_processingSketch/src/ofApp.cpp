#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600,700);
    xPos = 20;
    yPos = 30;
    
    moveRight = true;
    moveDown = true;
    
    ofBackground(150);

}

//--------------------------------------------------------------
void ofApp::update(){
    if (xPos == 25){
        moveRight = true;
        moveLeft = false;
        r = int(ofRandom(255));
        g = int(ofRandom(100));
        b = int(ofRandom(255));
    }
    
    if (xPos == ofGetWidth()-25){
        moveLeft = true;
        moveRight = false;
        r = int(ofRandom(255));
        g = int(ofRandom(100));
        b = int(ofRandom(255));
    }
    
    if (moveRight == true){
        xPos = xPos +5;
    }
    
    if(moveLeft == true){
        xPos = xPos -5;
    }
    
    if (yPos == 25){
        moveDown = true;
        moveUp = false;
        r = int(ofRandom(255));
        g = int(ofRandom(100));
        b = int(ofRandom(255));
    }
    
    if (yPos == ofGetHeight()-25){
        moveUp = true;
        moveDown = false;
        r = int(ofRandom(255));
        g = int(ofRandom(100));
        b = int(ofRandom(255));
    }
    
    if (moveDown == true){
        yPos = yPos +5;
    }
    
    if(moveUp == true){
        yPos = yPos -5;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofEllipse(xPos, yPos, 50, 50);
    ofSetColor(r, g, b);
    ofFill();
    ofEllipse(xPos, yPos, 49, 49);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}