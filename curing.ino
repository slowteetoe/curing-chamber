// This #include statement was automatically added by the Particle IDE.
#include "adafruit-sht31/adafruit-sht31.h"

// This #include statement was automatically added by the Particle IDE.
#include "Ubidots/Ubidots.h"

#define TOKEN ""  // Put Ubidots TOKEN here
#define DATA_SOURCE_TAG ""  // Put Ubidots data source name here

Ubidots ubidots(TOKEN);

Adafruit_SHT31 sensor = Adafruit_SHT31();

String SENSOR_ID = System.deviceID();

void setup() {
    
    Serial.begin(9600);
    
    delay(10);
    
    sensor.begin(0x44);
    
    Serial.println("Setting up " + SENSOR_ID);
}


void loop() {
    
    
    ubidots.add("temperature-f", cToF(sensor.readTemperature()));
    
    ubidots.add("humidity", sensor.readHumidity());
    
    ubidots.sendAll();
        
    delay(5000);
}

double cToF(double celcius){
    return celcius * 1.80 + 32;
}
