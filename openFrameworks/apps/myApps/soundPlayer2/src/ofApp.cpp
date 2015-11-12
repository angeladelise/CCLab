#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.loadSound("BottomsUp.wav");
    
    fftSmooth = new float [8192];
    for (int i =0; i < 8192; i++){
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    beat.setLoop(true);
    beat.setVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    for (int i =0; i < bands; i ++){
        //controls the speed that it dies down
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]){
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor colorOne(255, 0, 0);
    ofColor colorTwo(0, 0, 0);
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255);
    
    for (int i =0; i < bands; i ++){
      //  ofSetColor(255);

      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
        
      //  ofSetColor(150, 80);
      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150));
        
        //ofSetColor(255, 40);
      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500));

        
        ofSetColor(255, 150);

        //starts from top left
//        ofLine(0, 0, fftSmooth[i]*1000, ofGetHeight());
//        //starts from top right
//        ofLine(ofGetWidth(), 0, fftSmooth[i]*1000, ofGetHeight());
//        
//        ofLine(ofGetHeight(), ofGetWidth(), ofGetHeight(), fftSmooth[i]*1000);
//        
//        ofLine(0, 0, fftSmooth[i]*1000, ofGetHeight());
        
       // ofLine(ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()- fftSmooth[i]*500, ofGetWidth()-fftSmooth[i]*150);
        
        //hooked to bottom and moves top right up
        ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()-fftSmooth[i]*500, 0);
        
        //hooked to bottom and moves top right down
        ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()+fftSmooth[i]*500, 0);
        
        //hooked to bottom and moves top left down
        ofLine(ofGetWidth()/2, ofGetHeight(), -(fftSmooth[i]*500), 0);
        
        //hooked to bottom and moves top left up
        ofLine(ofGetWidth()/2, ofGetHeight(), fftSmooth[i]*500, 0);
        
        //-------
        
        //hooked to top and moves top right up
        ofLine(ofGetWidth()/2, 0, ofGetWidth()-fftSmooth[i]*500, ofGetHeight());
        
        //hooked to top and moves top right down
        ofLine(ofGetWidth()/2, 0, ofGetWidth()+fftSmooth[i]*500, ofGetHeight());
        
        //hooked to top and moves top left down
        ofLine(ofGetWidth()/2, 0, -(fftSmooth[i]*500), ofGetHeight());
        
        //hooked to top and moves top left up
        ofLine(ofGetWidth()/2, 0, fftSmooth[i]*500, ofGetHeight());
        
    }
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
    case '1':
            beat.play();
            break;
    case '2':
            beat.stop();
            break;
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
