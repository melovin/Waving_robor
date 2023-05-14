#define RED 9
#define GREEN 10
#define BLUE 11

void setup() {
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
}

void loop() {
digitalWrite(RED, LOW);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
delay(500);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, HIGH);
delay(500);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, LOW);
delay(500);
}
