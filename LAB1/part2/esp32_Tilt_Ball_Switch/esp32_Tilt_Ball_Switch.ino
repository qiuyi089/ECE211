//www.elegoo.com
// Modified for Adafruit HUZZAH32 ESP32 Feather (5/2/2019)

const int ledPin = BUILTIN_LED; // GPIO pin for LED
const int SwPin  = 21; // GPIO pin for tilt switch
const int buzzer = 16; // GPIO pin for active buzzer

void setup()
{ 
  pinMode(ledPin,OUTPUT); //initialize ledPin as an output
  digitalWrite(ledPin,LOW); //turn the led off
  pinMode(buzzer,OUTPUT); //initialize the buzzer pin as an output
  pinMode(SwPin,INPUT_PULLUP);
} 

void loop() 
{  
  int digitalVal = digitalRead(SwPin);
  
  if(HIGH == digitalVal)
  {
    digitalWrite(ledPin,LOW); //turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH); //turn the led on 
    for(int i=0;i<80;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(1);//wait for 1ms
      digitalWrite(buzzer,LOW);
      delay(1);//wait for 1ms
    }

  }
}
