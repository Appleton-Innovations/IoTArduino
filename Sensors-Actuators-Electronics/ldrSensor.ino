const int ldrpin = A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrval = analogRead(A0);
Serial.println(ldrval);
delay(1000);
}
