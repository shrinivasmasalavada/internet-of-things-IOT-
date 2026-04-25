#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR_BLYNK_AUTH";
char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASSWORD";

int relayPin = D1;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(relayPin, value);
}

void loop() {
  Blynk.run();
}