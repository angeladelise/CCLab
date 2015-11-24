import processing.video.*;

import processing.serial.*;
Serial port;

Capture cam;

String pressed;
float num;

String yawIn;
String pitchIn; //<>//
String rollIn;

float yaw;
float pitch;
float roll;

int count;
int imageCount;

void setup() {
 //port = new Serial(this, "/dev/cu.usbmodem1421", 250000);
  port = new Serial(this, "/dev/cu.HC-06-DevB", 9600);
  port.bufferUntil('\t');
  
  size(640, 430);
  frameRate(120);
  //320 BY 240 is the resolution, 30 fps
  
  cam = new Capture(this, 640, 430, 30);
  cam.start();
}

void draw() {
  if(cam.available()) {
       cam.read();
  }
    
    image(cam, 0, 0);

    if(port.available()>0){
    //pressed = port.readStringUntil('\t');
    
    yawIn = port.readStringUntil('\t');
    pitchIn = port.readStringUntil('\t');
    rollIn = port.readStringUntil('\n');
    }
    
    if(yawIn != null){
      yaw = float(yawIn);
      
      
      //num = float(pressed);
      //println(num);    
    
    //if(num > 0){
    //  fill(255,0,0);
    //  ellipse(50,50, width/2, height/2);
    //}
    
    }
    
    if(pitchIn != null){
    pitch = float(pitchIn);
    }
    
    if(rollIn != null){
    roll = float(rollIn);
    }
    
    println("yaw" + yaw);
    println("pitch" + pitch);
    println("roll" + roll);
    
    if(pitch > -10 && pitch < 10){
      if (roll > 70 && roll < 85){
        fill(255,0,0);
       // ellipse(width/2, height/2, 50,50);
        //will count the number of frames
        count++;
        //for every second (120 frames) make an image
           if(count % 120 == 0){
             fill(0,0,255);
             //ellipse(width/2, height/2, 50,50);
             imageCount ++;
             saveFrame("image-#####.png");
           }
      }
    }

    //print out count and image count on screen
    textSize(32);
    text("Count: " + count, 10, 30); 
    textSize(32);
    text("Image Count: " + imageCount, 10, 80); 

}