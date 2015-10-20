 class Triangle{
  float xPos;
  float yPos;
  float speed;
  
 Triangle(float xPos, float yPos, float speed){
  this.xPos = xPos;
  this.yPos = yPos;
  this.speed = speed;
 }
  
  void draw(){
   fill(0,255,0);
   triangle(xPos, yPos+50, xPos+25, yPos, xPos+50, yPos+50);
    
    yPos = yPos + speed;
    
    //to loop back up
    if(yPos > height +50){
        yPos = random(-1000,-100);
        xPos = random(0, width);
    speed = speed +.2; //increases in speed 
      }
  }
  
}