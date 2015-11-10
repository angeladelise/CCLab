int numOfPos = 50;
int [] xPos = new int[numOfPos];
int [] yPos = new int[numOfPos];

int[] rectPos = new int[20];

boolean drawCircle;

boolean drawRect;

boolean drawTri;

void setup(){
  size(600,600);
  
  background(0);
  
  for(int i = 0; i <numOfPos; i ++){
   xPos[i] = 0;
   yPos [i] = 0;
  }
}

void draw(){
  fill(0,25);
 // background(0);
 fill(255);
      textSize(40);
   text("Let's Draw! Press C, R, or T!", 10, 570); 

  
  for(int i =0; i<numOfPos-1; i++){
   xPos[i] = xPos[i+1]; //<>//
   yPos[i] = yPos[i+1];
    
  }
  
  xPos[numOfPos -1] = mouseX;
  yPos[numOfPos - 1]= mouseY;
  
  
  if(keyPressed){
    if(key == 'r'){
    
  for(int i =0; i<numOfPos; i++){
    fill(random(250), 50, random(200));
   ellipse(xPos[i], yPos[i], i, 100-i); 
  }
    }
    
  }
  //for (int j =0; j<20; j ++){
  //  rectPos[j] = mouseX;
   
  //}
  
  //  for(int j =0; j<20; j++){
  //  fill(random(250), 50, random(200));
  // ellipse(rectPos[j], 10, 5, 10); 
  //}
  
  
  if (drawCircle == true){
     for(int i =0; i<numOfPos; i++){
    fill(random(250), 50, random(200));
   ellipse(xPos[i], yPos[i], i, 100-i); 
  } 
  }
  
  if(drawTri == true){
    for(int i =0; i<numOfPos; i++){
    fill(random(100), random(50), random(250));
   triangle(xPos[i], yPos[i], i, 100-i, i+50, i*2); 
  }
  
  }
    
  if(drawRect == true){
    for(int i =0; i<numOfPos; i++){
    fill(random(200), random(250), random(100));
   rect(xPos[i], yPos[i], i, 100-i); 
  }
  }
  
  

}
  
  void keyPressed(){
    if(key == 'c'){
      drawCircle = true;
      drawRect = false;
      drawTri=false;
    }
    
    if(key == 'r'){
     drawRect = true; 
     drawCircle= false;
     drawTri= false;
    }
    
    if(key == 't'){
     drawTri=true;
     drawCircle = false;
     drawRect= false;
    }
  
    
  }