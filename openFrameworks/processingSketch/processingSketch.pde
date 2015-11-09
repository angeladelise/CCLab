int xPos;
int yPos;

boolean moveRight;
boolean moveLeft;

boolean moveDown;
boolean moveUp;

int r,g,b;

void setup(){
  size(600,700);
  
  xPos = 20;
  yPos = 30;

  moveRight = true;
  moveDown = true;
}

void draw(){
  background(150);
  
  fill(r,g,b);
  ellipse(xPos, yPos, 50,50);
    
  //yPos = yPos +5;
  
  if (xPos == 25){
  moveRight = true;
  moveLeft = false;
  r = int(random(255));
  g = int(random(100));
  b = int(random(255));
  }
  
  if (xPos == width-25){
  moveLeft = true;
  moveRight = false;
  r = int(random(255));
  g = int(random(100));
  b = int(random(255));
  }
  
  if (moveRight == true){
    xPos = xPos +5;
  }
  
  if(moveLeft == true){
    xPos = xPos -5;
  }
  
    if (yPos == 25){
  moveDown = true;
  moveUp = false;
  r = int(random(255));
  g = int(random(100));
  b = int(random(255));
  }
  
  if (yPos == height-25){
  moveUp = true;
  moveDown = false;
  r = int(random(255));
  g = int(random(100));
  b = int(random(255));
  }
  
  if (moveDown == true){
    yPos = yPos +5;
  }
  
  if(moveUp == true){
    yPos = yPos -5;
  }
}