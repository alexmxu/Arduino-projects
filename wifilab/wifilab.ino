#include <Wire.h>
#include <UnoWiFiDevEd.h>// if you are using the Arduino IDE 1.8.x then: //#include <UnoWiFiDevEd.h>

 
#define CONNECTOR     "rest" 
#define SERVER_ADDR   "api.thingspeak.com"

#define APIKEY_THINGSPEAK  "KCBQPP8YN2CZQYYI" //Insert your API Key 
 
int light = 0;
int temp = 0;
int lightPin = A0;
int tempPin = A1;
 
void setup() {
 Ciao.begin(); // CIAO INIT
}
 
void loop() {
temp = analogRead(tempPin);
light = analogRead(lightPin);
float voltage = temp * 5.0;
voltage /= 1024.0; 
float temperatureC = (voltage - 0.5) * 100 ;
      String uri = "/update?api_key=";
    uri += APIKEY_THINGSPEAK;
      uri += "&field1=";
      uri += String(temperatureC);
      uri += "&field2=";
      uri += String(light);
 
      Ciao.println("Send data on ThingSpeak Channel"); 
      
      CiaoData data = Ciao.write(CONNECTOR, SERVER_ADDR, uri);
 
      if (!data.isEmpty()){
        Ciao.println( "State: " + String (data.get(1)) );
        Ciao.println( "Response: " + String (data.get(2)) );
      }
     delay(30000); // Thingspeak policy
}
