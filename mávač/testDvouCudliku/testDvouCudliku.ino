void setup() {
  // put your setup code here, to run once:
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(6) == HIGH && digitalRead(7) == HIGH)
  {
    Serial.println("mackam oba cudliky :)");
  }
  else if (digitalRead(7) == HIGH)
  {
    Serial.println("mackam cudlik cislo 7 :)");
  }
  else if(digitalRead(6) == HIGH)
  {
     Serial.println("mackam cudlik cislo 6 :)");
  }
  
}
