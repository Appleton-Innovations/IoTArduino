#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN D1         
#define DHTTYPE DHT11     
char ssid[]="wifi name";//provide wifi name 
char pass[]="wifi password";//provide wifi Password
char auth[]="Auth Token";//Provide Auth Token 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sensordata()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Serial.println(t);
  Serial.println(h);
 }

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(1000L, sensordata);
}
 
void loop()
{
Blynk.run();
timer.run();
}
