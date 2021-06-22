#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
char ssid[] = "wifi name";//provide wifi (ssid) name
char pass[] = "wifi password";//provide password
char auth[] = "auth token";//provide project authentication token 
int x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

BLYNK_WRITE(V1)
{
  x = param.asInt();
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  Serial.println(x);
  if (x == 1) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
     }
  else {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
     }
  }
