void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=analogRead(A0);
float volt=3.3*x/1023;
float t=volt*100;
Serial.print("Temperature is: ");
Serial.println(t);
}
