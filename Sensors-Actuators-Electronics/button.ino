void setup() {
  // put your setup code here, to run once:
pinMode(D2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonStatus=digitalRead(D2);
Serial.println(buttonStatus);
}
