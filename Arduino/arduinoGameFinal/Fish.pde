class Fish{
  float xPos;
  float yPos;
  float size;
  float speed;
  
  PImage fish;
  
 Fish(float xPos, float yPos){
    this.xPos = xPos;
    this.yPos = yPos;
    
    fish = loadImage("blowfish.png");
 }
  
  void draw(){
    fill(255,0,0);
    //ellipse(xPos, yPos, 30, 30);
    image(fish, xPos-50, yPos-30, 60, 60);


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