// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <DHT.h>
#define DHTPIN D1         
#define DHTTYPE DHT11 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[]="wifi name";//Provide wifi name 
char pass[]="wifi password";//Provide wifi Password

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
