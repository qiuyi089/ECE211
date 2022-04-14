//www.elegoo.com [2016.12.09]
// Modified for Adafruit HUZZAH32 ESP32 Feather (5/2/2019)

// Joystick pin assignments
const int SW_pin = 16; // Switch output -> digital input pin
const int X_pin  = A0; // X output -> analog input pin
const int Y_pin  = A1; // Y output -> analog input pin

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
}
