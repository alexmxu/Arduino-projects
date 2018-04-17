
#include <SoftwareSerial.h>
SoftwareSerial  BTSerial(2, 3); //TX RX
const int button1 = 9;
const int button2 = 10;
const int button3 = 11;

int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup() {
  BTSerial.begin(9600); 
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  val1 = digitalRead(button1);
  val2 = digitalRead(button2);
  val3 = digitalRead(button3);
  Serial.println("b1: "+ (String)val1);
  Serial.println("b2: "+ (String)val2);
  Serial.println("b3: "+ (String)val3);
  if(val1 == HIGH && val2 == LOW && val3 == HIGH) {
    BTSerial.print("H");
    Serial.println("H");
  }
  else{
    BTSerial.print("L");
    Serial.println("L");
  }
  delay(1000);
}

