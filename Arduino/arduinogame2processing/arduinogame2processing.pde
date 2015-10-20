import processing.serial.*;
Serial port;

Player player;
Circle c1;
Circle c2;
Circle c3;
Circle c4;
Circle c5;
Circle c6;
Circle c7;
Circle c8;
Circle c9;
Triangle t1;
Triangle t2;
Triangle t3;
BlueCircle b1;
BlueCircle b2;
BlueCircle b3;
BlueCircle b4;
BlueCircle b5;
int state;
int lives;
int score;

float xPos = 0;
float yPos = 0;
String xIn;
String yIn;

void setup(){
  size(700,500);
  port = new Serial(this, "/dev/cu.usbmodem1421", 9600);
  port.bufferUntil('\n');
  
  player = new Player(400,400);
  c1 = new Circle (20, -30, 40, .73);
  c2 = new Circle (60, -70, 50, .7);
  c3 = new Circle (150, -150, 20, .99);
  c4 = new Circle (230, -280, 30, .98);
  c5 = new Circle (460, -300, 40, .86);
  c6 = new Circle (600, -30, 60, .92);
  c7 = new Circle (680, -450, 30, .83);
  c8 = new Circle (510, -100, 40, .82);
  c9 = new Circle (300, -40, 60, .98);
  t1 = new Triangle (300,-90, .6);
  t2 = new Triangle (100,-480, .8);
  t3 = new Triangle (450,-750, .85);
  b1 = new BlueCircle (580, -250, 30, .83);
  b2 = new BlueCircle (110, -80, 30, .82);
  b3 = new BlueCircle (200, -60, 20, .98);
  b4 = new BlueCircle (340, -150, 35, .83);
  b5 = new BlueCircle (630, -280, 25, .82);

  state = 1;
  lives = 3;
  score = 0;
}

void draw(){
  
  //intro screen
  if (state == 1){
    background(0);
    fill(255);
    textSize(30);
    text("Welcome!", width/3+30, height/3);
    textSize(20);
    fill(255,0,0);
    text("Use the Left and Right arrows to avoid the red circles", 100, height/2);
    fill(90,220,255);
    text("Catch the blue circles to increase your score!", 120, height/2+30);
    fill(0,255,0);
    text("Catch the green triangles to get more lives", 120, height/2+60);
    
    fill(255,130,50);
    textSize(20);
    text("Click to play!", width/3+40, height/2+100);
    
    
    if (mousePressed){
     state = 2; //go to next state 
    }
    
  }
  
  if (state == 2){
  fill(0, 10);
  background(0);
  player.draw();
  c1.draw();
  c2.draw();
  c3.draw();
  c4.draw();
  c5.draw();
  c6.draw();
  c7.draw();
  c8.draw();
  c9.draw();
  
  t1.draw();
  t2.draw();
  t3.draw();
  
  b1.draw();
  b2.draw();
  b3.draw();
  
  fill(255);
  text("Lives: " + lives, width -100, 30);
  text("Score: " + score, width -250, 30);
  
   if(port.available()>0){
  xIn = port.readStringUntil('\n');
  yIn = port.readStringUntil('\n');
    if(xIn != null && yIn != null){
      xPos = float(xIn);
      yPos = float(yIn);
      println(xIn);
      println(yIn);  
      
      if(xPos> 0){
        player.left();
      }
      
      if(xPos < 0){
        player.right();
      }
    }

  }
  
  //if (keyPressed){
  //  if (key == CODED){
  //   if(keyCode == LEFT){
  //    player.left(); 
  //   }
     
  //   if (keyCode == RIGHT){
  //    player.right(); 
  //   }
  //  }
  //}
  
   if(dist(c1.xPos, c1.yPos, player.xPos, player.yPos) < c1.size/2+25 )
   {
  lives = lives -1;
  c1.yPos = random(-100,-50);
    }
    
  
   if(dist(c2.xPos, c2.yPos, player.xPos, player.yPos) < c2.size/2+25 )
   {
  lives = lives -1;
    c2.yPos = random(-100,-50);
    }
    
  
   if(dist(c3.xPos, c3.yPos, player.xPos, player.yPos) < c3.size/2+25 )
   {
  lives = lives -1;
    c3.yPos = random(-100,-50);
    }
    
  
   if(dist(c4.xPos, c4.yPos, player.xPos, player.yPos) < c4.size/2+25 )
   {
  lives = lives -1;
    c4.yPos = random(-100,-50);
    }
    
    
  
   if(dist(c5.xPos, c5.yPos, player.xPos, player.yPos) < c5.size/2+25 )
   {
  lives = lives -1;
    c5.yPos = random(-100,-50);
    }
    

   if(dist(c6.xPos, c6.yPos, player.xPos, player.yPos) < c6.size/2+25 )
   {
  lives = lives -1;
    c6.yPos = random(-100,-50);
    }
  
   if(dist(c7.xPos, c7.yPos, player.xPos, player.yPos) < c7.size/2 +25)
   {
  lives = lives -1;
    c7.yPos = random(-100,-50);
    }

  
   if(dist(c8.xPos, c8.yPos, player.xPos, player.yPos) < c8.size/2 +25)
   {
  lives = lives -1;
    c8.yPos = random(-100,-50);
    }
    
  
   if(dist(c9.xPos, c9.yPos, player.xPos, player.yPos) < c9.size/2 +25)
   {
  lives = lives -1;
    c9.yPos = random(-100,-50);
    }
    
    
    if(dist(t1.xPos, t1.yPos, player.xPos, player.yPos) < 75 )
   {
  lives = lives +1;
  t1.yPos = random(-100,-50);
    }
    
  
   if(dist(t2.xPos, t2.yPos, player.xPos, player.yPos) < 75 )
   {
  lives = lives +1;
    t2.yPos = random(-100,-50);
    }
    
  
   if(dist(t3.xPos, t3.yPos, player.xPos, player.yPos) < 75 )
   {
  lives = lives +1;
    t3.yPos = random(-100,-50);
    }
    
    
    if(dist(b1.xPos, b1.yPos, player.xPos, player.yPos) < b1.size/2+25 )
   {
    score = score +10;
  b1.yPos = random(-100,-50);
    }
    
  
   if(dist(b2.xPos, b2.yPos, player.xPos, player.yPos) < b2.size/2+25 )
   {
  score = score +10;
    b2.yPos = random(-100,-50);
    }
    
  
   if(dist(b3.xPos, b3.yPos, player.xPos, player.yPos) < b3.size/2+25 )
   {
    score = score +10;
    b3.yPos = random(-100,-50);
    }
    
  
   if(dist(b4.xPos, b4.yPos, player.xPos, player.yPos) < b4.size/2+25 )
   {
    score = score +10;
    b4.yPos = random(-100,-50);
    }
    
    
  
   if(dist(b5.xPos, b5.yPos, player.xPos, player.yPos) < b5.size/2+25 )
   {
  score = score +10;
    b5.yPos = random(-100,-50);
    }
    
    
    
    if (lives ==0){
     state = 3; 
    }
    
}


  if (state ==3){
   background(255,0,0);
   fill(255);
   textSize(50);
    text("You Lose!", width/2-120, height/2);
   textSize(20);
    text("Click to replay!", width/3+40, height*2/3);
    
    if (mousePressed){
      state =1;
      setup();
    }
    
  }

println(state);
}