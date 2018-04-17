#include <SoftwareSerial.h>
SoftwareSerial  BTSerial(2, 3); //TX RX
int buzzerPin = 8;
int led = 9;
void setup() {
  BTSerial.begin(9600); //begin bluetooth communication
  Serial.begin(9600); //begin serial communication
  pinMode(led, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    char inChar = (char) BTSerial.read(); //reads single character at a time
    if(inChar == 'L') {
      digitalWrite(led, LOW);
    }
    else if(inChar == 'H') {
      digitalWrite(led, HIGH);
    }
    Serial.println(inChar);
  }
}
