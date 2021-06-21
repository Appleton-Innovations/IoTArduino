const int RED = D1;
const int YELLOW = D2;
const int GREEN = D3;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(1000);
}
