#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
#include<DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
WiFiClient client;
String tsAddress="http://api.thingspeak.com/update.json?";
String url;
HTTPClient http;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
WiFi.begin("wifi name","wifi password");
while((!(WiFi.status()==WL_CONNECTED))){
  delay(300);
  Serial.println("Wifi Connecting..");
}
Serial.println("Connected to the Internet");
}

void loop() {
  float t=dht.readTemperature();
  float h=dht.readHumidity();
  // put your main code here, to run repeatedly:
//https://api.thingspeak.com/update?api_key=2ORTO04IKNUMUGQV&field1=30&field2=70
if(client.connect("api.thingspeak.com",80))
{
  url=tsAddress;
  url+="api_key=";
  url+="***********";//provide Thingspeak Write API Key
  url+="&field1=";
  url+=t;
  url+="&field2=";
  url+=h;
  Serial.println(url);
  http.begin(client,url);
  http.GET();
  http.end();
}
}
