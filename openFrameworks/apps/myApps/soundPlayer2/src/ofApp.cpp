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
    
    //cout << "timer:" << timer <<endl;
    cout << "sec:" << seconds <<endl;
    cout << "state:" << state <<endl;
    
    
    
    if (state == 3){
        //for green lines state!
        int y = ofGetHeight();
        xPosRight = xPosRight + 3;
        xPosLeft = xPosLeft - 3;

        xLeft = xLeft -3;
        xRight = xRight +3;

        yUp = yUp -3;
        yDown = yDown +3;
        
        cout << "yUp:" << yUp <<endl;

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofColor colorOne(186, 61, 52);
    ofColor colorTwo(0, 0, 0);
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255);
    
    
    if (state == 2){
    
    for (int i =0; i < bands; i ++){
      //  ofSetColor(255);

      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
        
      //  ofSetColor(150, 80);
      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*150));
        
        //ofSetColor(255, 40);
      //  ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500));

        
        ofSetColor(210, 255, 253, 100);

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
    }//end of state 1
    
    //CIRCLE FOR BEGNINNG!
    if (state == 5){
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
    }//end of state 2
    
    
    //DIAGONAL GREEN LINES
    if (state == 3){
        
        for (int i =0; i < bands; i ++){
            

            ofSetColor(116-i*10, 233+i/2, 189+i*10, 80);
          
            //hooked to bottom and moves top right up
            ofLine(0, ofGetHeight()+yDown, ofGetWidth()-fftSmooth[i]*600 + 100, yUp);
            
            //hooked to bottom and moves top right down
            ofLine(0, ofGetHeight()+yDown, ofGetWidth()+fftSmooth[i]*600 + 100, yUp);
            
            //hooked to bottom and moves top left down
            ofLine(ofGetWidth(), ofGetHeight() + yDown, -(fftSmooth[i]*600), yUp);
            
            //hooked to bottom and moves top left up
            ofLine(ofGetWidth(), ofGetHeight() + yDown, fftSmooth[i]*600, yUp);
            
            
            //hooked to top and moves top right up
            ofLine(xPosRight, 0, ofGetWidth()-fftSmooth[i]*500 +xLeft, ofGetHeight());
            
            //hooked to top and moves top right down
            ofLine(xPosRight, 0, ofGetWidth()+fftSmooth[i]*500+ xLeft, ofGetHeight());
            
            //hooked to top and moves top left down
            ofLine(xPosLeft, 0, -(fftSmooth[i]*500) + xRight, ofGetHeight());
            
            //hooked to top and moves top left up
            ofLine(xPosLeft, 0, fftSmooth[i]*500 + xRight, ofGetHeight());
            
            //middle left
            //hooked to top and moves top right up
            ofLine(0, ofGetHeight()/2+yDown, ofGetWidth()-fftSmooth[i]*500 +xLeft, ofGetHeight()+yUp);
            
            //hooked to top and moves top right down
            ofLine(0, ofGetHeight()/2+yDown, ofGetWidth()+fftSmooth[i]*500+ xLeft, ofGetHeight()+yUp);
            
            //middle right
            //hooked to top and moves top left down
            ofLine(ofGetWidth(), ofGetHeight()/2+yDown, -(fftSmooth[i]*500) + xRight, ofGetHeight()+yUp);
            
            //hooked to top and moves top left up
            ofLine(ofGetWidth(), ofGetHeight()/2+yDown, fftSmooth[i]*500 + xRight, ofGetHeight()+yUp);
            
            
            
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
                state = 4;
            }
            
            
        }
    }//end of state 3

    
    
    //CIRCLE 2nd TIME STATE 4
    if (state == 4){
        
        ofColor colorOne(0, 106, 229);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            
            
            ofSetColor(240, 111, 49, 20);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-3]*500));
            
            
            ofSetColor(240, 46, 43, 40);
            ofNoFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*450));
            
            ofSetColor(88, 206, 200, 50);
            ofFill();
            ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i-2]*350));
            
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
        
        if (seconds == 17){
            //after 40 seconds change the state
            state = 2;
        }
    }//end of state 4

    
    //STATE 5 LINES ON WALLS
    if(state == 1){
        
        ofColor colorOne(49, 46, 9);
        ofColor colorTwo(0, 0, 0);
        
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        
        for (int i =0; i < bands; i ++){
            
            ofSetColor(240, 91, 242, 80);

            for (int y =0; y < ofGetHeight(); y = y+30)
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*800), y);
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*800), y);
                
            }
        ofSetColor(188, 41, 242, 80);
            for (int y =0; y < ofGetHeight(); y = y+100)
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*600), y);
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*600), y);

            }
        ofSetColor(238, 87, 242, 80);
            for (int y =25; y < ofGetHeight(); y = y+50)
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*300), y);
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*300), y);
                
            }
            
            ofSetColor(240, 37, 152, 100);
            for (int y =10; y < ofGetHeight(); y = y+20)
            {
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2+ (fftSmooth[i]*200), y);
                ofLine(ofGetWidth()/2, y, ofGetWidth()/2- (fftSmooth[i]*200), y);
                
            }

        }
        
        if (seconds == 17){
            //after 40 seconds change the state
            state = 2;
        }
    
    
    }//end of state 5
    
    
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
