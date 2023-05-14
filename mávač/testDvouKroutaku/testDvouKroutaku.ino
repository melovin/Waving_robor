#define pot1 A7
#define pot2 A6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int pot1Value = analogRead(pot1);
  int pot2Value = analogRead(pot2);

  Serial.println((String)"pot1: " + pot1Value);
  Serial.println((String)"pot2: " + pot2Value);
  delay(600);
}
