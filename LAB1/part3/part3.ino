//www.elegoo.com [2016.12.08]
// Modified for Adafruit HUZZAH32 ESP32 Feather (5/2/2019)
// Requires the following library to be installed:
//   ESP32Servo

#include <ESP32Servo.h>

const int servoPin = 23; // Servo data pulse pin
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo angle position
int fast = 1; // base speed(slow speed);

// Joystick pin assignments
const int SW_pin = 16; // Switch output -> digital input pin
const int X_pin  = A0; // X output -> analog input pin
const int Y_pin  = A1; // Y output -> analog input pin


void setup()
{
  pinMode(SW_pin, INPUT_PULLUP);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  myservo.attach(servoPin);  // assigns servo pin to the servo object
}

void loop()
{
  //check for the Y axis to see if it far from the middle and adjust the speed base on it
  //if it less than the center then set the speed to 1.
  if(analogRead(Y_pin) < 1850 && analogRead(Y_pin) < 1800){
    fast = 1;
  }
  //if it bigger than the center then make the speed to 5.
  else if(analogRead(Y_pin) > 1850){
    fast = 5;
  }
  
  if(analogRead(X_pin) < 1750){
    for (pos = 0; pos <= 90; pos += fast) 
    {
      myservo.write(pos);               
      delay(15);                        
    }
    for (pos = 90; pos >= 0; pos -= fast) 
   {
      myservo.write(pos);               
     delay(15);                        
   }
  }
  if(analogRead(X_pin) > 1850){
    
    for (pos = 0; pos <= 180; pos += fast) 
    {
      myservo.write(pos);               
      delay(15);                        
    }
    for (pos = 180; pos >= 0; pos -= fast) 
   {
      myservo.write(pos);               
     delay(15);                        
   }
  }
  delay(500);
}
