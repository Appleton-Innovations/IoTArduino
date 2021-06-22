#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
WiFiClient client;
String tsAddress="http://api.thingspeak.com/update.json?";
String url;
HTTPClient http;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin("Wifi name","WiFi password");// Provide Wifi Name and Password
while((!(WiFi.status()==WL_CONNECTED))){
  delay(300);
  Serial.println("Wifi Connecting..");
}
Serial.println("Connected to the Internet");
}

void loop() {
    // put your main code here, to run repeatedly:
//https://api.thingspeak.com/update?api_key=2ORTO04IKNUMUGQV&field1=30&field2=70
if(client.connect("api.thingspeak.com",80))
{
  url=tsAddress;
  url+="api_key=";
  url+="*****";//provide write API Key
  url+="&field3=";
  url+=analogRead(A0);
  Serial.println(url);
  http.begin(client,url);
  http.GET();
  http.end();
}
}
