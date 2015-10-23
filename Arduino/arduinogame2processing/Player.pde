class Player{
  float xPos;
  float yPos;
  PVector location;
  PVector velocity;
  PVector speed;
  PVector friction;
  
  PImage car;
  
  Player(float xPos, float yPos){
    this.xPos = xPos;
    this.yPos = yPos;
    
    location = new PVector(400,600); // initial position
    velocity = new PVector(10,0); //moves only in x direction
    speed = new PVector(1, 0); //adds speed
    friction = new PVector(0.1,0); //friction to stop player
    
    car = loadImage("Car.png");
  }
  
  void draw(){
    fill(255);
    rectMode(CENTER);
   // rect(xPos, yPos, 50,50); 
    rect(location.x, location.y, 50,50);
    image(car, location.x-52, location.y-35, 120, 150);
    xPos = location.x; // to work with the collisions
    yPos = location.y;
    
    if(xPos <25){
   xPos = 25; 
    }
    
     if(xPos > (width - 25)){
   xPos = width-25; 
    }
  }
  
  void left() { //move to the left
      velocity.x = -4;
      speed.x = -1;
      location.add(velocity);
      velocity.add(speed);
      if(xPos <25){
       xPos = 25; 
        }
    }
    
    void moveLeft(){
       location.add(velocity);
       friction.x = 0.08;
      if (velocity.x <0) {  //if you are still moving add friction until you stop
        velocity.add(friction);
      } 
      else {
        velocity.x =0; //then stop
      }
    }

    void right() { //move to the right
      velocity.x = 4; //move in the positive x direction
      speed.x = 1;
      location.add(velocity);
      velocity.add(speed);  
          
     if(xPos > (width - 25)){
       xPos = width-25; 
      }
    }
    
    void moveRight(){
      location.add(velocity);
      friction.x = -0.08; 
      if (velocity.x >0) { //if you are still moving add friction until you stop
        velocity.add(friction);
      } else {
        velocity.x =0; //then stop 
      }
    }
  
  //void left(){
  // xPos = xPos -10; 
  // if(xPos <25){
  //  xPos = 25; 
  // }
  //}
  
  //void right(){
  //  xPos = xPos +10;
  //  if (xPos > (width-25)){
  //   xPos = width-25; 
  //  }
  //}
  
}