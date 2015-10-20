class Player{
  float xPos;
  float yPos;
  
  Player(float xPos, float yPos){
    this.xPos = xPos;
    this.yPos = yPos;
  }
  
  void draw(){
    fill(255);
    rectMode(CENTER);
   rect(xPos, yPos, 50,50); 
    
  }
  
  void left(){
   xPos = xPos -10; 
   if(xPos <25){
    xPos = 25; 
   }
  }
  
  void right(){
    xPos = xPos +10;
    if (xPos > (width-25)){
     xPos = width-25; 
    }
  }
  
}