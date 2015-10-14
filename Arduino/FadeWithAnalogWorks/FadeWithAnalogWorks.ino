
int brightness;    // how bright the LED is
int fadeAmount = 3;    // how many points to fade the LED by
const int analogPin = A0;    // pin that the sensor is attached to
const int redLed = 9;  // pin that the LED is attached to
const int threshold = 512;  //halfway of possible analog values

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  
  int analogValue = analogRead(analogPin);
   analogWrite(redLed, brightness);

 //  float brightLevel = analogValue - threshold;

    if(analogValue == 0){
      brightness = 0;
    }
   
   if(analogValue >0 && analogValue < 100){
    brightness = 25;
    }

    if(analogValue > 100 && analogValue < 200){
      brightness = 50;
    }

    if(analogValue > 200 && analogValue < 300){
      brightness = 75;
    }

    if(analogValue > 300 && analogValue < 400){
      brightness = 100;
    }
   if(analogValue >400 && analogValue < 500){
    brightness = 125;
    }

    if(analogValue > 500 && analogValue < 600){
      brightness = 150;
    }

    if(analogValue > 600 && analogValue < 700){
      brightness = 175;
    }

    if(analogValue > 700 && analogValue < 800){
      brightness = 200;
    }
       if(analogValue >800 && analogValue < 900){
    brightness = 225;
    }

    if(analogValue > 900 && analogValue < 1000){
      brightness = 127;
    }
  delay(30);

  Serial.println(analogValue);
}

