#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
char ssid[]="wifi name";//provide wifi (ssid) name
char pass[]="wifi password";// provide wifi password
char auth[]="auth-token";
int x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth,ssid,pass);
pinMode(D2,OUTPUT);//red
pinMode(D3,OUTPUT);//green
pinMode(D4,OUTPUT);//blue
}

BLYNK_WRITE(V1)
{
  x=param.asInt();
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
Serial.println(x);
if(x==0){
 digitalWrite(D2,LOW);
 digitalWrite(D3,LOW);
 digitalWrite(D4,LOW);
}
else if(x==1){
  digitalWrite(D2,HIGH);
 digitalWrite(D3,LOW);
 digitalWrite(D4,HIGH);
}
else if(x==2){
   digitalWrite(D2,LOW);
 digitalWrite(D3,HIGH);
 digitalWrite(D4,LOW);
}
else{
  Serial.println("Invalid Input");
}
}
