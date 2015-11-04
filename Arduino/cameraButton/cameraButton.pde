import processing.video.*;

import processing.serial.*;
Serial port;

Capture cam;

String pressed;
float num;

void setup() {
  port = new Serial(this, "/dev/cu.usbmodem1421", 115200);
  port.bufferUntil('\n');
  
  size(640, 430);
  //320 BY 240 is the resolution, 30 fps
  
  cam = new Capture(this, 640, 430, 30);
  cam.start();
}

void draw() {
  if(cam.available()) {
       cam.read();
  } //<>// //<>//
    
    image(cam, 0, 0);

    if(port.available()>0){
    pressed = port.readStringUntil('\n');
    }
    
    if(pressed != null){
      num = float(pressed);
      println(num);    
    
    if(num > 0){
      fill(255,0,0);
      ellipse(50,50, width/2, height/2);
    }
    
    }

}