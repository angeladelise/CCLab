class Bubbles{
  float xPos;
  float yPos;
  float speed;
  float size;
  
 Bubbles(float xPos, float yPos, float size){
    this.xPos = xPos;
    this.yPos = yPos;
    this.size = size;
 }
  
  void draw(){
    fill(255,80);
    noStroke();
    ellipse(xPos, yPos, size, size);
    
    yPos = yPos - speed;
    
    //to loop back up
    if(yPos < -30){
        yPos = random(height + 100, height+ 400);
        xPos = random(0, width);
            
        if(speed < 5){
        speed = speed +.02; //increases in speed 
        }
        else{
        speed = 5;
        }
    }  
  }
}