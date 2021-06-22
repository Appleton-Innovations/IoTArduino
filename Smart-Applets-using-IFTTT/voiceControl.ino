#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
char ssid[] = "wifi name";//change this
char pass[] = "wifi password";//change this
char auth[] = "auth token";//change this

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  }

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  }
