import processing.serial.*; //<>//
Serial port;

String pressed;
float num;

String yawIn;
String pitchIn; //<>//
String rollIn;

float yaw;
float pitch;
float roll;

Player player;

Fish f1;
Fish f2;
Fish f3;
Fish f4;
Fish f5;

Shark s1;
Shark s2;

Bubbles bub1;
Bubbles bub2; 
Bubbles bub3;
Bubbles bub4;
Bubbles bub5;

Tank t1;

int state;
int lives;
int score;

float xPos = 0;
float yPos = 0;
String xIn;
String yIn;

boolean moveLeft;
boolean moveRight;

PImage title;
PImage lose;
PImage win;

PImage water;

import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

Minim minim;

AudioPlayer music;

AudioPlayer break1;
AudioPlayer break2;

void setup() {
  port = new Serial(this, "/dev/cu.usbmodem1421", 250000);
  port.bufferUntil('\t');
  
  size(800, 750);
  frameRate(120);

  player = new Player(400,400);
  
  bub1 = new Bubbles(width/6, 800, 30);
  bub2 = new Bubbles(width/3, 950, 15);
  bub3 = new Bubbles(3*width/6, 1070, 25);
  bub4 = new Bubbles(4*width/6, 920, 35);
  bub5 = new Bubbles(5*width/6, 1120, 28);
  
  f1 = new Fish (120, 850);
  f2 = new Fish (560, 970);
  f3 = new Fish (850, 950);
  f4 = new Fish (230, 1080);
  f5 = new Fish (460, 900);
  
  s1 = new Shark(width/2, 820, width/2, width*.75, 1);
  s2 = new Shark(50, 800, 50, 150, 2);
  
  t1 = new Tank (300,-90, 1.5);

  state = 1;

  //title = loadImage("icyroads.png");
  //lose = loadImage("sign.png");
  //win = loadImage("win.png");
  water = loadImage("underwater.png");
  
  //minim = new Minim (this);
 //// music = minim.loadFile("Transportation.mp3");
  ////music.loop();
  
  //minim = new Minim (this);
  //break1 = minim.loadFile("Break1.wav");
  ////powerup.loop();
  
  //minim = new Minim (this);
  //break2 = minim.loadFile("Break2.wav");
}

void draw() {
  
 //HOME SCREEN
  if (state == 1){
    background(100); //gray background
    fill(255);
    textSize(30);
    text("Welcome!", width/3+30, height/3);
    textSize(20);
    fill(255,0,0);
    text("Use the Left and Right arrows to avoid the red circles", 100, height/2);
    fill(90,220,255);
    text("Catch the blue circles to increase your score!", 120, height/2+30);
    fill(0,255,0);
    text("Catch the green triangles to get more lives", 120, height/2+55);
    
    fill(255,130,50);
    textSize(20);
    text("Click to play!", width/3+40, height/2+100);
    
   // image(title, 0,0);
    
    lives = 3;
    score = 0;
   // music.play();
    
    ////every 3minutes replay the song
    //if(millis() % 190000 == 0){
    //  music.rewind();
    //  music.play();
    //}
    
    //fish inital conditions
    //randomize y position every time you replay
    f1.yPos = random(0, -400);
    f2.yPos = random(-150, -400);
    f3.yPos = random(-200, -400);
    f4.yPos = random(-450, -600);
    f5.yPos = random(-200, -600);
    f1.speed = 2.2;
    f2.speed = 2.2;
    f3.speed = 2.2;
    f4.speed = 2.2;
    f5.speed = 2.2;
    
    //tank position and speed
    t1.yPos = random(-500, -1000);
    t1.speed = 2.2;
    
    //bubbles speed
    bub1.speed = 2.2;
    bub2.speed = 2.2;
    bub3.speed = 2.2;
    bub4.speed = 2.2;
    bub5.speed = 2.2;
      
    s1.speed = 2.2;  
    s2.speed = 2.2;
      
    if (mousePressed){
     state = 2; //go to next state 
    }
    
  }
  
  
  if (state == 2){
  fill(0, 10);
  background(100);
  
  image(water, 0, 0);
  
  //   //every 3minutes replay the song
  //  if(millis() % 190000 == 0){
  //  music.rewind();
  //  music.play();
  //  }
 
  
  bub1.draw();
  bub2.draw();
  bub3.draw();
  bub4.draw();
  bub5.draw();

  
  f1.draw();
  f2.draw();
  f3.draw();
  f4.draw();
  f5.draw();
  
  s1.draw();
  s2.draw();
  
  t1.draw();
 
  player.draw();

  
  fill(255);
  text("Lives: " + lives, width -100, 30);
  text("Score: " + score, width -250, 30);
  
  
  if(port.available()>0){
    
    yawIn = port.readStringUntil('\t');
    pitchIn = port.readStringUntil('\t');
    rollIn = port.readStringUntil('\n');
    }
    
    if(yawIn != null){
      yaw = float(yawIn);
      
    
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
    
    if(roll > 5){
      //if (roll > 70 && roll < 85){
  
           
     // }
    }
  
   if(port.available()>0){
    xIn = port.readStringUntil('\n');
    yIn = port.readStringUntil('\n');
   
    if(xIn != null && yIn != null){
      xPos = float(xIn);
      yPos = float(yIn);
      println(xIn);
      println(yIn);  
      
      if(xPos> 0){
        player.right();
        moveRight = true;
        moveLeft = false;
      }
      
      if(xPos < 0){
        player.left();
        moveLeft = true;
        moveRight = false;
       }
     }

    } // end of port loop
    
    
     if(moveLeft == true){
      player.moveLeft(); 
    }
     if(moveRight == true){
      player.moveRight(); 
    }

  
   if(dist(f1.xPos, f1.yPos, player.xPos+10, player.yPos+40) < f1.size/2+70 )
   {
    lives = lives -1;
    f1.yPos = random(-100,-50);
    f1.xPos = random(0, width);
    }
    
  
   if(dist(f2.xPos, f2.yPos, player.xPos+10, player.yPos+40) < f2.size/2+70 )
   {
     lives = lives -1;
     f2.yPos = random(-100,-50);
     f2.xPos = random(0, width);
    }
    
  
   if(dist(f3.xPos, f3.yPos, player.xPos+10, player.yPos+40) < f3.size/2+70 )
   {
    lives = lives -1;
    f3.yPos = random(-100,-50);
    f3.xPos = random(0, width);
    }
    
  
   if(dist(f4.xPos, f4.yPos, player.xPos+10, player.yPos+40) < f4.size/2+70 )
   {
    lives = lives -1;
    f4.yPos = random(-100,-50);
    f4.xPos = random(0, width);
    }
    
    
  
   if(dist(f5.xPos, f5.yPos, player.xPos+10, player.yPos+40) < f5.size/2+70 )
   {
    lives = lives -1;
    f5.yPos = random(-100,-50);
    f5.xPos = random(0, width);
    }
    
    
    
    if(dist(t1.xPos, t1.yPos, player.xPos+10, player.yPos+40) < 25 + 70 )
   {
    lives = lives +1;
    t1.yPos = random(-100,-50);
    t1.xPos = random(0, width);
    }
 
    
    if (lives ==0){
     state = 3; 
    }
    
    //if (score == 500){
    // state = 4; 
    //}
    
}


  if (state ==3){
   background(255,0,0);
   fill(255);
   textSize(50);
    text("You Lose!", width/2-100, height/2);
   textSize(20);
    text("Click to replay!", width/2-30, height*2/3);
    
    //image(lose, 0, 0);
    
    if (mousePressed){
      state =1;
    }
    
    ////every 3minutes replay the song
    //if(millis() % 190000 == 0){
    //   music.rewind();
    //   music.play();
    //}
  }
  
    if (state ==4){
   background(255,0,0);
   fill(255);
   textSize(50);
    text("You Lose!", width/2-100, height/2);
    
   // image(win, 0, 0);
    
    if (mousePressed){
      state =1;
    }
    
    ////every 3minutes replay the song
    //if(millis() % 190000 == 0){
    //   music.rewind();
    //  music.play();
    //}
    
  }

//println(state);
}