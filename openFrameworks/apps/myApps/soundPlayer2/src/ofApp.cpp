#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.loadSound("BottomsUp.wav");
    
    //rate set to 30
    ofSetFrameRate(30);
    
    fftSmooth = new float [8192];
    for (int i =0; i < 8192; i++){
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    beat.setLoop(true);
    beat.setVolume(0.2);
    
    //inital state
    state = 1;
    
    beat.play();
    
    ofEnableSmoothing();
    
    //initally set timer to 0
    timer = 0;
    seconds = 0;

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
    

    //increase timer every frame
    timer ++;
    if (timer % 30 ==0){
        seconds ++;
    }
    
    //ofLog(timer);
    //ofLogToConsole();
    
    cout << "timer:" << timer <<endl;
    cout << "sec:" << seconds <<endl;
    //cout << "state:" << state <<endl;
    
    
    
    if (state == 10){
        //for green lines state!
        int y = ofGetHeight();
        
        if (xPosRight < ofGetWidth()){
        xPosRight = xPosRight + 5;
        }
        if (xPosLeft > 0){
        xPosLeft = xPosLeft - 5;
        }
        
        xBottomLeft = ofGetWidth() +xLeft;
        xBottomRight = 0+xRight;
        
        if(xBottomRight >= ofGetWidth()){
            xBottomRight += xLeft;
        }
        
        if(xBottomLeft <= 0){
            xBottomLeft += xRight;
        }
        
        if(xPosRight> ofGetWidth()){
            xPosRight += -5;
        }
        
        if(xPosLeft < 0){
            xPosLeft += 5;
        }

        
        if(xPosLeft> ofGetWidth()){
            xPosRight += -5;
        }
        
        if(xPosRight < 0){
            xPosLeft += 5;
        }
        xLeft = xLeft -5;
        xRight = xRight +5;

        yUp = yUp -5;
        yDown = yDown +5;
       
       // cout << "yUp:" << yUp <<endl;

    }
    
    
    //STATE 5
    if (state ==3 && xRedLines >= ofGetWidth()){
        xRedLines = ofGetWidth();
    
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofColor colorOne(186, 61, 52);
    ofColor colorTwo(0, 0, 0);
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255);
    
    
    //CIRCLE FOR BEGNINNG!
    if (state == 8){
        for (int i =0; i < bands; i ++){
            
            
            
            ofSetColor(137, 43, 219, 20);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500));
            
            
            ofSetColor(58, 206, 240, 40);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*450));
            
            ofSetColor(88, 206, 200, 50);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*350));
            
            ofSetColor(130, 80, 240, 60);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*300));
            
            ofSetColor(58, 186, 240, 80);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150));
            
            ofSetColor(154, 240, 239);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
            
            
            
            //Stroke
            ofSetColor(86, 240, 239);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150 +2));
            
            ofSetColor(58, 86, 240, 80);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150 +2));
            
            ofSetColor(137, 43, 219, 40);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500+2));
            
            
            //lines
            ofSetColor(116, 233, 159, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2+ (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2- (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500), ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500), ofGetHeight()/2);
            
            //diagonal lines
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*600), ofGetHeight()/2+ (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*600), ofGetHeight()/2- (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*600), ofGetHeight()/2- (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*600), ofGetHeight()/2+ (fftSmooth[i]*600));
            
            ofSetColor(136, 233, 229, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*300), ofGetHeight()/2+ (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*300), ofGetHeight()/2- (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*300), ofGetHeight()/2- (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*300), ofGetHeight()/2+ (fftSmooth[i]*300)*.75);
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.25, ofGetHeight()/2+ (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.25, ofGetHeight()/2- (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.25, ofGetHeight()/2+ (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.25, ofGetHeight()/2- (fftSmooth[i]*500)*.25);
            
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.75, ofGetHeight()/2+ (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.75, ofGetHeight()/2- (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.75, ofGetHeight()/2+ (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.75, ofGetHeight()/2- (fftSmooth[i]*500)*.75);
            
            //intense lines coming out of sides
            ofSetColor(118, 177, 242, 60);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2-550, ofGetHeight()/2+ (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+550, ofGetHeight()/2- (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)-550, ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)+550, ofGetHeight()/2);
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+550, ofGetHeight()/2+ (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2-550, ofGetHeight()/2- (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)+550, ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)-550, ofGetHeight()/2);
            
            
            
            
        }
        
        if (seconds == 17){
            //after 40 seconds change the state
            state = 2;
        }
    }//end of state 1

    
    if (state == 2){
    
    for (int i =0; i < bands; i ++){

        
        ofSetColor(124, 255, 193, 80);
        
        
        //hooked to bottom and moves top right up
        ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()-fftSmooth[i]*500, 0);
        
        //hooked to bottom and moves top right down
        ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()+fftSmooth[i]*500, 0);
        
        //hooked to bottom and moves top left down
        ofLine(ofGetWidth()/2, ofGetHeight(), -(fftSmooth[i]*500), 0);
        
        //hooked to bottom and moves top left up
        ofLine(ofGetWidth()/2, ofGetHeight(), fftSmooth[i]*500, 0);
        
        
        //------MIDDLE OF BOTTOM AREA
        //hooked to bottom and moves top right up
        ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()-fftSmooth[i]*500 - (ofGetWidth()*.25), 0);
        
        //hooked to bottom and moves top right down
        ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()+fftSmooth[i]*500 - (ofGetWidth()*.25), 0);
        
        //hooked to bottom and moves top left down
        ofLine(ofGetWidth()/2, ofGetHeight()*.75, -(fftSmooth[i]*500)+ (ofGetWidth()*.25), 0);
        
        //hooked to bottom and moves top left up
        ofLine(ofGetWidth()/2, ofGetHeight()*.75, fftSmooth[i]*500 + (ofGetWidth()*.25), 0);
        
        //-------
        
        //hooked to top and moves top right up
        ofLine(ofGetWidth()/2, 0, ofGetWidth()-fftSmooth[i]*500, ofGetHeight());
        
        //hooked to top and moves top right down
        ofLine(ofGetWidth()/2, 0, ofGetWidth()+fftSmooth[i]*500, ofGetHeight());
        
        //hooked to top and moves top left down
        ofLine(ofGetWidth()/2, 0, -(fftSmooth[i]*500), ofGetHeight());
        
        //hooked to top and moves top left up
        ofLine(ofGetWidth()/2, 0, fftSmooth[i]*500, ofGetHeight());
        
        //------- MIDDLE OF TOP AREA
        //hooked to top and moves top right up
        ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()-fftSmooth[i]*500- (ofGetWidth()*.25), ofGetHeight());
        
        //hooked to top and moves top right down
        ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()+fftSmooth[i]*500- (ofGetWidth()*.25), ofGetHeight());
        
        //hooked to top and moves top left down
        ofLine(ofGetWidth()/2, ofGetHeight()*.25, -(fftSmooth[i]*500) + (ofGetWidth()*.25), ofGetHeight());
        
        //hooked to top and moves top left up
        ofLine(ofGetWidth()/2, ofGetHeight()*.25, fftSmooth[i]*500 + (ofGetWidth()*.25), ofGetHeight());
        
        if (seconds == 29){
            //after 20 seconds change the state
            state = 3;
        }
        
        }
    }//end of state 2
    
    
    //moving lines
    
    //RED LINES STATE 3
    if (state == 3){
        
        ofColor colorOne(21, 10, 159);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        
        for (int i =0; i < bands; i ++){
            
            // xRedLines = (ofGetWidth()*fftSmooth[i]*100) -(4*ofGetWidth());
            xRedLines = -(ofGetWidth()*fftSmooth[i]*100);
            xRedLines2 = (ofGetWidth()*fftSmooth[i]*100) + ofGetWidth();
            
            xRedLinesNotIntense = -(ofGetWidth()*fftSmooth[i]*60);
            xRedLinesNotIntense2 = (ofGetWidth()*fftSmooth[i]*60) + ofGetWidth();
            
            
            //red lines
            ofSetColor(220, 25, 24, 80);
            
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight(), xRedLines, 0);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight(), xRedLines, 0);
            
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, 0, xRedLines, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, 0, xRedLines, ofGetHeight());
            
            
            //MIRRORED SIDE RIGHT
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight(), xRedLines2, 0);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight(), xRedLines2, 0);
            
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, 0, xRedLines2, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, 0, xRedLines2, ofGetHeight());
          
    //------------------------
            //HOOKED TO CORNER RIGHT
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth(), ofGetHeight(), xRedLinesNotIntense, 0);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth(), ofGetHeight(), xRedLinesNotIntense, 0);
            
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth(), 0, xRedLinesNotIntense, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth(), 0, xRedLinesNotIntense, ofGetHeight());
            
            
            //MIRRORED SIDE LEFT
            //hooked to bottom and moves top right up
            ofLine(0, ofGetHeight(), xRedLinesNotIntense2, 0);
            
            //hooked to bottom and moves top right down
            ofLine(0, ofGetHeight(), xRedLinesNotIntense2, 0);
            
            
            //hooked to top and moves top right up
            ofLine(0, 0, xRedLinesNotIntense2, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(0, 0, xRedLinesNotIntense2, ofGetHeight());
            
            if(seconds == 42){
                state = 4;
            }
            
            
        }
    }//end of state 3

    //STATE 4 LINES FROM CENTER
    if(state == 4){
        
        ofColor colorOne(0, 89, 62);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            //starting the y and a negative number or else there are no lines on the top (skips 0-30)
            
            ofSetColor(180, 81, 232, 120);
            
            for (int y =-20; y < ofGetHeight()+40; y = y+ ofRandom(40, 50))
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*400), y+ (fftSmooth[i]*400));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*400), y+ (fftSmooth[i]*400));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*400), y- (fftSmooth[i]*400));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*400), y- (fftSmooth[i]*400));
                
            }
            ofSetColor(235, 37, 124, 120);
            for (int y =-50; y < ofGetHeight()+80; y = y+ofRandom(80, 100))
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*300), y+ (fftSmooth[i]*200));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*300), y+ (fftSmooth[i]*200));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*300), y- (fftSmooth[i]*200));
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*300), y- (fftSmooth[i]*200));
                
            }
       
            
        }
        
        if (seconds == 50){
            //after 40 seconds change the state
            state = 5;
        }
        
        
    }//end of state 4
    
    
    //REPEAT YELLOW LINES STATE 5
    if (state == 5){
        
        ofColor colorOne(71, 40, 89);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        
        for (int i =0; i < bands; i ++){
            
            // xRedLines = (ofGetWidth()*fftSmooth[i]*100) -(4*ofGetWidth());
            xRedLines = -(ofGetWidth()*fftSmooth[i]*100);
            xRedLines2 = (ofGetWidth()*fftSmooth[i]*100) + ofGetWidth();
            
            xRedLinesNotIntense = -(ofGetWidth()*fftSmooth[i]*60);
            xRedLinesNotIntense2 = (ofGetWidth()*fftSmooth[i]*60) + ofGetWidth();
            
            
            //red lines
            ofSetColor(220, 225, 24, 60);
            
            //MOVING THIS TO RIGHT CORNER
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth(), ofGetHeight(), xRedLines, 0);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth(), ofGetHeight(), xRedLines, 0);
            
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth(), 0, xRedLines, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth(), 0, xRedLines, ofGetHeight());
            
            
            //MIRRORED SIDE RIGHT MOVE TO LEFT CORNER
            //hooked to bottom and moves top right up
            ofLine(0, ofGetHeight(), xRedLines2, 0);
            
            //hooked to bottom and moves top right down
            ofLine(0, ofGetHeight(), xRedLines2, 0);
            
            
            //hooked to top and moves top right up
            ofLine(0, 0, xRedLines2, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(0, 0, xRedLines2, ofGetHeight());
            
            
            if(seconds == 62){
                state = 6;
            }
            
            
        }
    }//end of state 5
    
    if (state == 6){
        
        ofColor colorOne(11, 30, 129);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            //HOT PINK
            ofSetColor(235, 37, 93, 80);
            
            
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()-fftSmooth[i]*500, ofGetHeight()/2);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()+fftSmooth[i]*500, ofGetHeight()/2);
            
            //hooked to bottom and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight(), -(fftSmooth[i]*500), ofGetHeight()/2);
            
            //hooked to bottom and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight(), fftSmooth[i]*500, ofGetHeight()/2);
            
            
            //------MIDDLE OF BOTTOM AREA
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()-fftSmooth[i]*500 - (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()+fftSmooth[i]*500 - (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, -(fftSmooth[i]*500)+ (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, fftSmooth[i]*500 + (ofGetWidth()*.25), ofGetHeight()/2);
            
            //-------
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, 0, ofGetWidth()-fftSmooth[i]*500, ofGetHeight()/2);
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, 0, ofGetWidth()+fftSmooth[i]*500, ofGetHeight()/2);
            
            //hooked to top and moves top left down
            ofLine(ofGetWidth()/2, 0, -(fftSmooth[i]*500), ofGetHeight()/2);
            
            //hooked to top and moves top left up
            ofLine(ofGetWidth()/2, 0, fftSmooth[i]*500, ofGetHeight()/2);
            
            //------- MIDDLE OF TOP AREA
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()-fftSmooth[i]*500- (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()+fftSmooth[i]*500- (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, -(fftSmooth[i]*500) + (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, fftSmooth[i]*500 + (ofGetWidth()*.25), ofGetHeight()/2);
            
     
    //-------------------
            //REPEAT LINES YELLOW MORE AMPLIFIED
            ofSetColor(235, 219, 88, 80);

            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()-fftSmooth[i]*600, ofGetHeight()/2);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight(), ofGetWidth()+fftSmooth[i]*600, ofGetHeight()/2);
            
            //hooked to bottom and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight(), -(fftSmooth[i]*600), ofGetHeight()/2);
            
            //hooked to bottom and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight(), fftSmooth[i]*600, ofGetHeight()/2);
            
            
            //------MIDDLE OF BOTTOM AREA
            //hooked to bottom and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()-fftSmooth[i]*600 - (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, ofGetWidth()+fftSmooth[i]*600 - (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, -(fftSmooth[i]*600)+ (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to bottom and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight()*.75, fftSmooth[i]*600 + (ofGetWidth()*.25), ofGetHeight()/2);
            
            //-------
            
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, 0, ofGetWidth()-fftSmooth[i]*600, ofGetHeight()/2);
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, 0, ofGetWidth()+fftSmooth[i]*600, ofGetHeight()/2);
            
            //hooked to top and moves top left down
            ofLine(ofGetWidth()/2, 0, -(fftSmooth[i]*600), ofGetHeight()/2);
            
            //hooked to top and moves top left up
            ofLine(ofGetWidth()/2, 0, fftSmooth[i]*600, ofGetHeight()/2);
            
            //------- MIDDLE OF TOP AREA
            //hooked to top and moves top right up
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()-fftSmooth[i]*600- (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top right down
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, ofGetWidth()+fftSmooth[i]*600- (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top left down
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, -(fftSmooth[i]*600) + (ofGetWidth()*.25), ofGetHeight()/2);
            
            //hooked to top and moves top left up
            ofLine(ofGetWidth()/2, ofGetHeight()*.25, fftSmooth[i]*600 + (ofGetWidth()*.25), ofGetHeight()/2);
            
            if (seconds == 88){
                //after 20 seconds change the state
                state = 7;
            }
            
        }
    }//end of state 6

    
    //CIRCLE 2nd TIME STATE 7
    if (state == 7){
        
        ofColor colorOne(0, 106, 229);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            
            
            ofSetColor(240, 111, 49, 20);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*400));
            
            
            ofSetColor(240, 46, 43, 40);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*450));
            
            ofSetColor(88, 206, 200, 50);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*250));
            
            ofSetColor(240, 40, 116, 60);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*300));
            
            ofSetColor(218, 106, 240, 80);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150));
            
            ofSetColor(254, 140, 69);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
            
            
            
            //Stroke
            ofSetColor(186, 40, 239);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150 +2));
            
            ofSetColor(158, 86, 140, 80);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150 +2));
            
            ofSetColor(137, 43, 119, 40);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500+2));
            
            
            //lines
            ofSetColor(240, 161, 169, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2+ (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2- (fftSmooth[i]*500));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500), ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500), ofGetHeight()/2);
        
            
            //diagonal lines
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*600), ofGetHeight()/2+ (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*600), ofGetHeight()/2- (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*600), ofGetHeight()/2- (fftSmooth[i]*600));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*600), ofGetHeight()/2+ (fftSmooth[i]*600));
            
            ofSetColor(236, 183, 29, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*300), ofGetHeight()/2+ (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*300), ofGetHeight()/2- (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*300), ofGetHeight()/2- (fftSmooth[i]*300)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*300), ofGetHeight()/2+ (fftSmooth[i]*300)*.75);
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.25, ofGetHeight()/2+ (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.25, ofGetHeight()/2- (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.25, ofGetHeight()/2+ (fftSmooth[i]*500)*.25);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.25, ofGetHeight()/2- (fftSmooth[i]*500)*.25);
            
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.75, ofGetHeight()/2+ (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*500)*.75, ofGetHeight()/2- (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.75, ofGetHeight()/2+ (fftSmooth[i]*500)*.75);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*500)*.75, ofGetHeight()/2- (fftSmooth[i]*500)*.75);
            
            //intense lines coming out of sides
            ofSetColor(242, 117, 42, 40);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2-550, ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+550, ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*1000)-550, ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*1000)+550, ofGetHeight()/2);
            
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+550, ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2-550, ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*1000)+550, ofGetHeight()/2);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*1000)-550, ofGetHeight()/2);
            
            //extra diagonal lines
            ofSetColor(240, 161, 169, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            
            ofSetColor(240, 61, 69, 100);
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i-2]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i-2]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i-2]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i-2]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i-2]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i-2]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+ (fftSmooth[i-2]*1000), ofGetHeight()/2- (fftSmooth[i]*1000));
            ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2- (fftSmooth[i-2]*1000), ofGetHeight()/2+ (fftSmooth[i]*1000));
            
            
            
        }
        
        if (seconds == 102){
            //after 40 seconds change the state
            state = 8;
        }
    }//end of state 7

    
    
    
    //STATE 8 LINES FROM SIDES REPEAT OF STATE 4
    if(state == 1){
        
        ofColor colorOne(0, 89, 62);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            //starting the y and a negative number or else there are no lines on the top (skips 0-30)
            
            ofSetColor(180, 81, 232, 120);
            
            for (int y =-60; y < ofGetHeight()+60; y = y+ ofRandom(60, 70))
            {
                ofLine(0, y, (fftSmooth[i]*400), y+ (fftSmooth[i]*400));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i]*400), y+ (fftSmooth[i]*200));
                ofLine(0, y, + (fftSmooth[i]*400), y- (fftSmooth[i]*400));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i]*400), y- (fftSmooth[i]*200));
                
            }
            ofSetColor(235, 37, 124, 120);
            for (int y =-110; y < ofGetHeight()+110; y = y+ofRandom(90, 110))
            {
                ofLine(0, y, (fftSmooth[i]*400), y+ (fftSmooth[i]*400));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i]*400), y+ (fftSmooth[i]*200));
                ofLine(0, y, + (fftSmooth[i]*400), y- (fftSmooth[i]*400));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i]*400), y- (fftSmooth[i]*200));
                
            }
            //BLUE
            ofSetColor(15, 197, 254, 60);
            for (int y =-130; y < ofGetHeight()+130; y = y+ofRandom(110, 130))
            {
                ofLine(0, y, (fftSmooth[i-2]*600), y+ (fftSmooth[i-2]*600));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i-2]*600), y+ (fftSmooth[i-2]*300));
                ofLine(0, y, + (fftSmooth[i-2]*600), y- (fftSmooth[i-2]*600));
                ofLine(ofGetWidth(), y, ofGetWidth()- (fftSmooth[i-2]*600), y- (fftSmooth[i-2]*300));
                
            }
            
            
        }
        
        if (seconds == 50){
            //after 40 seconds change the state
            state = 1;
        }
        
        
    }//end of state 8


    
    
    //DIAGONAL GREEN LINES STATE 10
    if (state == 10){
        
        for (int i =0; i < bands; i ++){
            
            
            ofSetColor(116-i*10, 233+i/2, 189+i*10, 80);
            
            //hooked to bottom and moves top right up
            ofLine(xBottomRight, ofGetHeight(), ofGetWidth()-fftSmooth[i]*600 + 100+xLeft, 0);
            
            //hooked to bottom and moves top right down
            ofLine(xBottomRight, ofGetHeight(), ofGetWidth()+fftSmooth[i]*600 + 100+xLeft, 0);
            
            //hooked to bottom and moves top left down
            ofLine(xBottomLeft, ofGetHeight(), -(fftSmooth[i]*600)+xRight, 0);
            
            //hooked to bottom and moves top left up
            ofLine(xBottomLeft, ofGetHeight(), fftSmooth[i]*600+xRight, 0);
            
            
            //hooked to top and moves top right up
            ofLine(xPosRight, 0, ofGetWidth()-fftSmooth[i]*500 +xLeft, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(xPosRight, 0, ofGetWidth()+fftSmooth[i]*500+ xLeft, ofGetHeight());
            
            //hooked to top and moves top left down
            ofLine(xPosLeft, 0, -(fftSmooth[i]*500) + xRight, ofGetHeight());
            
            //hooked to top and moves top left up
            ofLine(xPosLeft, 0, fftSmooth[i]*500 + xRight, ofGetHeight());
            
            //middle left
            //            //hooked to top and moves top right up
            //            ofLine(0, ofGetHeight()/2+yDown, ofGetWidth()-fftSmooth[i]*800 +xLeft, ofGetHeight()+yUp);
            //
            //            //hooked to top and moves top right down
            //            ofLine(0, ofGetHeight()/2+yDown, ofGetWidth()+fftSmooth[i]*800+ xLeft, ofGetHeight()+yUp);
            //
            //            //middle right
            //            //hooked to top and moves top left down
            //            ofLine(ofGetWidth(), ofGetHeight()/2+yDown, -(fftSmooth[i]*800) + xRight, ofGetHeight()+yUp);
            //
            //            //hooked to top and moves top left up
            //            ofLine(ofGetWidth(), ofGetHeight()/2+yDown, fftSmooth[i]*800 + xRight, ofGetHeight()+yUp);
            
            
            
            //            //hooked to bottom and moves top right up
            //            ofLine(0, 0, ofGetWidth()-fftSmooth[i]*600 + xRight, yDown);
            //
            //            //hooked to bottom and moves top right down
            //            ofLine(0, 0, ofGetWidth()+fftSmooth[i]*600 + xRight, yDown);
            //
            //            //hooked to bottom and moves top left down
            //            ofLine(ofGetWidth(), ofGetHeight(), -(fftSmooth[i]*600) + xLeft, yUp);
            //
            //            //hooked to bottom and moves top left up
            //            ofLine(ofGetWidth(), ofGetHeight(), fftSmooth[i]*600+xLeft, yUp);
            
            
            
            
            //            if (timer == 400){
            //                //after 16 seconds change the state
            //                state = 2;
            //            }
            
            if(seconds == 42){
                state = 1;
            }
            
            
        }
    }//end of state 10
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    switch(key){
//    case '1':
//            beat.play();
//            break;
//    case '2':
//            beat.stop();
//            break;
//    }

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
