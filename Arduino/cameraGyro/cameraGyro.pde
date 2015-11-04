import processing.video.*;

import processing.serial.*;
Serial port;

Capture cam;

String pressed;
float num;

String yawIn;
String pitchIn;
String rollIn;

float yaw;
float pitch;
float roll;

void setup() {
  port = new Serial(this, "/dev/cu.usbmodem1421", 250000);
  port.bufferUntil('\t');
  
  size(640, 430);
  frameRate(30);
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
      if (roll > 50 && roll < 80){
        fill(255,0,0);
        ellipse(width/2, height/2, 50,50);
      }
    }

}