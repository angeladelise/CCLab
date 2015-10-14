/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 This example code is in the public domain.
 */

int brightness;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
const int analogPin = A0;    // pin that the sensor is attached to
const int redLed = 9;  // pin that the LED is attached to
const int clearLed = 8;
const int threshold = 512;  //halfway of possible analog values

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(redLed, OUTPUT);
  pinMode(clearLed, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  
  int analogValue = analogRead(analogPin);
  
  if (analogValue > threshold) {
    analogWrite(redLed, brightness);
    digitalWrite(clearLed, LOW);

    //controlling the brightness by analog value
    if(analogValue - threshold < 128){
    brightness = 63;
    }

    if(analogValue - threshold < 256){
      brightness = 127;
    }

    if(analogValue - threshold < 384){
      brightness = 190;
    }

    if(analogValue - threshold < 512){
      brightness = 250;
    }

    Serial.println(brightness);
    }
    
//    for(int i = threshold; i < 1023; i = i+2){
//    brightness = brightness + fadeAmount;
//    } 
  
  else {
    brightness = 0;
    analogWrite(redLed, brightness);
    digitalWrite(clearLed, HIGH);
  }

  
  
 // brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
//  if (brightness == 0 || brightness == 255) {
//    fadeAmount = -fadeAmount ;
//  }
  // wait for 30 milliseconds to see the dimming effect
  delay(1);
}

