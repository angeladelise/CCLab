#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer beat;
    float * fftSmooth;
    int bands;
    
    int state;
    int timer =0;
    int seconds =0;
    
    //according to which position they are moving!
    int y;
    int xPosRight = ofGetWidth()/2;
    int xPosLeft = ofGetWidth()/2;

    int yPosRight = ofGetHeight();
    int yPosLeft = 0;
    
    int xLeft = 0;
    int xRight =0;
    
    int yUp =0;
    int yDown =0;

};
