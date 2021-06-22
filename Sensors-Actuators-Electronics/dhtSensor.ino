#include<DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly
 
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Serial.print("Current Humidity: ");
  Serial.println(humi);
  Serial.print("Current Temperature: ");
  Serial.println(temp);
  delay(1000);

}
