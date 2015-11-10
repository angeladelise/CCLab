#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600,600);
    myfont.loadFont("arial.ttf", 32);
    
    for(int i = 0; i <numOfPos; i ++){
        xPos[i] = 0;
        yPos [i] = 0;
    }
    
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    

  
    for(int i =0; i<numOfPos-1; i++){
        xPos[i] = xPos[i+1]; //<>//
        yPos[i] = yPos[i+1];
        
    }
    
    xPos[numOfPos -1] = mouseX;
    yPos[numOfPos - 1]= mouseY;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    myfont.drawString("Let's Draw! Press C, R, or T!", 10, 570);
    
    if (drawCircle == true){
        for(int i =0; i<numOfPos; i++){
            ofSetColor(ofRandom(250), 50, ofRandom(200));
            ofEllipse(xPos[i], yPos[i], i, 100-i);
        }
    }
    
    if(drawTri == true){
        for(int i =0; i<numOfPos; i++){
            ofSetColor(ofRandom(100), ofRandom(50), ofRandom(250));
            ofTriangle(xPos[i], yPos[i], i, 100-i, i+50, i*2);
        }
        
    }
    
    if(drawRect == true){
        for(int i =0; i<numOfPos; i++){
            ofSetColor(ofRandom(200), ofRandom(250), ofRandom(100));
            ofRect(xPos[i], yPos[i], i, 100-i);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        drawCircle = true;
        drawRect = false;
        drawTri=false;
    }
    
    if(key == 'r'){
        drawRect = true;
        drawCircle= false;
        drawTri= false;
    }
    
    if(key == 't'){
        drawTri=true;
        drawCircle = false;
        drawRect= false;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
