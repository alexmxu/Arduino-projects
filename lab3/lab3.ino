const int BUTTON = 7;
int state = 0;
int ThermistorPin = 0;
int V, T;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}
void loop(){
state = digitalRead(BUTTON);
if ((state == HIGH)){
  delay(10);
}
if (state == LOW) {
  V = analogRead(ThermistorPin);
  Serial.print(V);
  T = ((float)V/1024)*500;

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 
}

  

  delay(50);
}

int pinstate=0;//85
bool onePressed=false;
bool twoPressed=false;
void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(6, OUTPUT);
}

void loop()
{
  if((digitalRead(9)==LOW)&&(onePressed==false)){
    onePressed=true;
    pinstate-=85;
    pinstate=constrain(pinstate,0,255);
      Serial.print(pinstate);
  }
  if(digitalRead(9)==HIGH){
    onePressed=false;
  }
  if((digitalRead(8)==LOW)&&(twoPressed==false)){
    twoPressed=true;
    pinstate+=85;
    pinstate=constrain(pinstate,0,255);
      Serial.print(pinstate);
  }
  if(digitalRead(8)==HIGH){
    twoPressed=false;
  }
  digitalWrite(6,pinstate);
  
}



