#include <DHT.h>


#define DHTPIN 15      // pin for Dustation Devkit v1.3
//#define DHTPIN 23      // pin for Dustation Devkit v1.4
#define DHTTYPE DHT22  // DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void dhtSetup(void) {
  dht.begin();
}

void dhtLoop(void) {
  // read temperature and humidity

  TEMP = dht.readTemperature();
  HUMI = dht.readHumidity();

  if (isnan(TEMP) || isnan(HUMI)) {
    Serial.println("AM2302 Failed");
    TEMP = HUMI = 0;
  }
}