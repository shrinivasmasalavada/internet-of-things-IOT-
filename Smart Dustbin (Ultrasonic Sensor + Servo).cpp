#include <Servo.h>

Servo servo;
int trigPin = D1;
int echoPin = D2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(D3);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20) {
    servo.write(90);  // open lid
  } else {
    servo.write(0);   // close lid
  }

  delay(500);
}