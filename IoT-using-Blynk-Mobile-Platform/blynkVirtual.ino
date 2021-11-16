// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
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
