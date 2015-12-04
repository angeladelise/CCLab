class Player{
  //images depend on moving left or right
  PImage diverLeft;
  PImage diverRight;
 
  float xPos;
  float yPos;
  PVector location;
  PVector velocity;
  PVector speed;
  PVector friction;
  
  Player(float xPos, float yPos){
    this.xPos = xPos;
    this.yPos = yPos;
    
    //starting x and y position
    location = new PVector(400,100);
    //float in x direction
    velocity = new PVector(10,0);
    
    //increase speed
    speed = new PVector(1, 0); 
    //friction makes diver stop moving
    friction = new PVector(0.1,0); 
    
   diverLeft = loadImage("diverleft.png");
   diverRight = loadImage("diverright.png");
  }
  
  void draw(){
    //fill(255);
    //rectMode(CENTER);
    //rect(location.x, location.y, 50,50);
    //image(diver, location.x-52, location.y-35, 120, 150);
    xPos = location.x; // to work with the collisions
    yPos = location.y;
      
    if(xPos <25){
   xPos = 25; 
    }
    
     if(xPos > (width - 25)){
       xPos = width-25; 
      }
  }//end of draw
  
  void left() { //move to the left
      velocity.x = -4;
      speed.x = -1.5;
      
      image(diverLeft, location.x-52, location.y-35, 120, 150);

      location.add(velocity);
      velocity.add(speed);
      if(location.x <40){
       location.x = 40; 
        }
        
   //  break1.play();
   //  break1.rewind();
    } // end of left
    
    void moveLeft(){
       location.add(velocity);
       friction.x = 0.08;
       
        image(diverLeft, location.x-52, location.y-35, 120, 150);

      if (velocity.x <0) {  //if you are still moving add friction until you stop
        velocity.add(friction);
        if(location.x <40){
       location.x = 40; 
        }
      } 
      else {
        velocity.x =0; //then stop
        if(location.x <40){
       location.x = 40; 
        }
      }
    } // end of moveLeft

    void right() { //move to the right
      velocity.x = 4; //move in the positive x direction
      speed.x = 1.5;

       image(diverRight, location.x-52, location.y-35, 120, 150);

      location.add(velocity);
      velocity.add(speed);  
          
     if(location.x > (width - 60)){
       location.x = width-60; 
      }
   //  break2.play();
   //  break2.rewind();
    } // end of right
    
    void moveRight(){
      location.add(velocity);
      friction.x = -0.08; 
      
      image(diverRight, location.x-52, location.y-35, 120, 150);

      
      if (velocity.x >0) { //if you are still moving add friction until you stop
        velocity.add(friction);
         if(location.x > (width - 60)){
         location.x = width-60; 
        }
      } else {
        velocity.x =0; //then stop 
        if(location.x > (width - 60)){
       location.x = width-60; 
        }
      }
    } // end of moveRight
  
} //end of class