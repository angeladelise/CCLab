 class Tank{
  float xPos;
  float yPos;
  float speed;
  
  PImage heart;
  
 Tank(float xPos, float yPos, float speed){
  this.xPos = xPos;
  this.yPos = yPos;
  this.speed = speed;
  
   //heart = loadImage("heart.png");
 }
  
  void draw(){
   fill(0,255,0);
   triangle(xPos, yPos+50, xPos+25, yPos, xPos+50, yPos+50);
   //image(heart, xPos-10, yPos-20, 70, 70);

    
    yPos = yPos - speed;
    
    //to loop back up
    if(yPos < -50){
        yPos = random(height + 200, height + 500);
        xPos = random(50, width - 50);
        
        if(speed < 5){
        speed = speed +.2; //increases in speed 
        }
        else{
        speed = 5;
        }
      }
    }
  

}