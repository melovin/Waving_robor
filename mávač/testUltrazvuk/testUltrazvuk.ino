#define Trig 13
#define Echo 12

void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  Serial.begin(9600);
}

void loop() {
 digitalWrite(Trig, LOW);
 delayMicroseconds(2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(Trig, LOW);

 unsigned long dur = pulseIn(Echo, HIGH);
 int dist = dur / 29 / 2;
 if(dur == 0)
 {
  return;
 }
 Serial.println((String)"Vzdálenost je: " + dist) ;
 delay(600);
}
