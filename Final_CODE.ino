#include "DHT.h"

#define DHTPIN 2  // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Serial.println("DHT final");

  dht.begin();

}

void loop() {
  // Wait a few moment between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 miliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Farenheit (isFarenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Farenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFarenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.println(t);
  Serial.println(h);

  
}
