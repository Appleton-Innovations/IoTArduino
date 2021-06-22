#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
char ssid[] = "APPLETON";
char pass[] = "Gladys@123";
char auth[] = "dgJ0iBPn29EIGSs7yntGtK9Yl-79at0e";
int x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, OUTPUT); //red
  pinMode(D2, OUTPUT); //green
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
