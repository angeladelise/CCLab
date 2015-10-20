class Circle{
  float xPos;
  float yPos;
  float size;
  float speed;
  
 Circle(float xPos, float yPos, float size, float speed){
  this.xPos = xPos;
  this.yPos = yPos;
   this.size = size;
   this.speed = speed;
 }
  
  void draw(){
   fill(255,0,0);
    ellipse(xPos, yPos, size, size);
    
    yPos = yPos + speed;
    
    //to loop back up
    if(yPos > height +size){
        yPos = random(-200,-50);
        xPos = random(0, width);
    speed = speed +.2; //increases in speed 
    }
  }
  
  
}