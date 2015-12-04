class Shark{
  float xPos;
  float yPos;
  float xMin;
  float xMax;
  
  float speed;
  
  PImage sharkLeft;
  PImage sharkRight;
  
  int direction;
  
 Shark(float xPos, float yPos, float xMin, float xMax, int direction){
    this.xPos = xPos;
    this.yPos = yPos;
    this.xMin = xMin;
    this.xMax = xMax;
    this.direction = direction;
    
    sharkLeft = loadImage("sharkLeft.png");
    sharkRight = loadImage("sharkRight.png");
 }
  
  void draw(){
    //movement of shark
    
    //for 2 seconds move in one direction then switch
    //for(float i=xMin; i <xMax; i ++){
    //   image(sharkRight, xPos-50, yPos-30, 60, 60);
    //    xPos ++;
    //}
    
    if(xPos <= xMin){
      direction = 1;
 
    }
    
    //greater max? swim to left
    if(xPos >= xMax){
      direction =2;
    }
    
    ////lower than min? swim back to right
    //if(xPos <= xMin){
    //   image(sharkRight, xPos-50, yPos-30, 120, 80);
    //   xPos ++;
    //}
      
      //MOVES RIGHT
      if(direction == 1){
       image(sharkRight, xPos-50, yPos-30, 120, 80);
       xPos ++;
   
      }
      
      //MOVES LEFT
      if(direction == 2){
       image(sharkLeft, xPos-50, yPos-30, 120, 80);
       xPos --;
      }
      
    //image(shark, xPos-50, yPos-30, 60, 60);

    yPos = yPos - speed;
    
    //to loop back up
    if(yPos < -80){
        yPos = random(height + 150, height + 400);
        xPos = random(0, width);
        
        if(speed < 5){
        speed = speed +.2; //increases in speed 
        }
        else{
        speed = 5;
        }
    }
  }
  
  
}