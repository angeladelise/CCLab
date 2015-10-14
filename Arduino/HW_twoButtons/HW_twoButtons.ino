
int redLed = 9;
int buttonPin = 2;
int buttonState = 0;

int buttonPin2 = 4; 
int buttonState2 = 0;
int greenLed = 3;



void setup() {
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);

  Serial.begin(9600);
}


void loop() {
    buttonState = digitalRead(buttonPin);
    buttonState2 = digitalRead(buttonPin2);

    //if both are pressed full brightness
    if(buttonState == HIGH && buttonState2 == HIGH){
      analogWrite(redLed, 255);
      analogWrite(greenLed, 255);
      }
  
    //one is pressed, red is half bright
    else if(buttonState == HIGH){
    analogWrite(redLed, 50);
    }

    //two is pressed, green is half bright
    else if(buttonState2 == HIGH){
    analogWrite(greenLed, 50);
    }
    
    //if none are pressed, no lights are on
    else{
    analogWrite(redLed, 0);
    analogWrite(greenLed, 0);
      }
      
    Serial.println(buttonState);
    Serial.println(buttonState2);
}


