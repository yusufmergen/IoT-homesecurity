#include <RF24Network.h>
#include <RF24.h>
#include<SPI.h>
#include "DHT.h"


DHT dht;

RF24 radio(7, 8);
RF24Network network(radio);

const uint16_t master = 00;
const uint16_t pir = 01;
const uint16_t magSwitch = 02;
const uint16_t temphumd = 03;

struct payload_t {                  // Structure of payload
  float temperature;
  float humidity;
};




void setup() {
  Serial.begin(9600);
  Serial.println("RF24Network Begins..");
  SPI.begin();
  radio.begin();
  network.begin(100,temphumd);
  dht.setup(2);
}

void loop() {

  network.update();
  delay(dht.getMinimumSamplingPeriod());
  int temp=(dht.getTemperature()*1.8)+32;
  int humd=dht.getHumidity();
  String t_payload ={String(temp)+String(humd)};
  int payload = t_payload.toInt();
 
  
  //payload_t payload = {dht.getTemperature(),dht.getHumidity()};
  RF24NetworkHeader header(/*to node*/ master);
  bool ok = network.write(header, &payload, sizeof(payload));
    if(ok)
  Serial.println("Sending");
    else
  Serial.println("Failed to send");
  delay(5000);
  
 
}
