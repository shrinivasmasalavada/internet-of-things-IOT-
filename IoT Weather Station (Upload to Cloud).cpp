#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* server = "api.thingspeak.com";
String apiKey = "YOUR_API_KEY";

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (client.connect(server, 80)) {
    String url = "/update?api_key=" + apiKey +
                 "&field1=" + String(temp) +
                 "&field2=" + String(hum);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
  }

  client.stop();
  delay(15000);
}