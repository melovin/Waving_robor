void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(7) == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
}
