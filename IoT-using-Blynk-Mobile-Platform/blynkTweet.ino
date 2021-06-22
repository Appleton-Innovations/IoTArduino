#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "auth-token";//Provoide authentication Token
char ssid[] = "wifi name";//provide wifi name
char pass[] = "wifi password";//provide wifi password

BlynkTimer timer;

void sensorData() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, humi);

  if( temp > 33) {
    Blynk.tweet("Hey!, Temperature is > 33");//http://docs.blynk.cc/#widgets-notifications-push-notifications
  }
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();

timer.setInterval(1000L, sensorData);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
