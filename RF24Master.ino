
#include <RF24Network.h>
#include <RF24.h>
#include<SPI.h>


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

int led = 2;
String input;
String command;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  //Serial.println("RF24Network Begins..");
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 100, /*node address*/ master);
}

void loop() {
 
    network.update();
    while (network.available()) {
    int sensorData;
    RF24NetworkHeader header;
    input = Serial.readString();
    while(input == "ARM" ){
    network.read(header, &sensorData, sizeof(sensorData));
    uint16_t headerId = header.from_node;

    if (headerId == 1) {
      Serial.println("1");
      digitalWrite(led,HIGH);
      //Serial.print("Alert!! Living Room ");
      //Serial.println(sensorData);
    }
    if (headerId == 2) {
      
      Serial.println("2");
      digitalWrite(led,HIGH);
      //Serial.print("Alert!! Kitchen Door ");
      //Serial.println(sensorData);
    }

    if (headerId == 3) {
      Serial.print("3");
      Serial.print(sensorData);

      /*String data = String(sensorData);
        char buff[4];
        buff[1] = data.charAt(0);
        buff[2] = data.charAt(1);
        buff[3] = data.charAt(2);
        buff[4] = data.charAt(3);
        char a[2] = {buff[1], buff[2]};
        char b[2] = {buff[3], buff[4]};
        int temperature = atoi(a);
        int humidity = atoi(b);
        Serial.println("Temperature:");
        Serial.println(temperature, DEC);
        Serial.println(humidity, DEC);*/
      //Serial.println("Temperature & Humidity:");
      //Serial.println(sensorData);

    }

    /*payload_t payload;
      network.read(header,&payload,sizeof(payload));
      Serial.println(payload.temperature);
      Serial.print("Humidity:");
      Serial.println(payload.humidity);
      }*/

    /*while(network.available()){
      RF24NetworkHeader header;
      payload_t payload;
      network.read(header,&payload,sizeof(payload));
        Serial.print("Temperature:");
        Serial.println(payload.temperature);
        Serial.print("Humidity:");
        Serial.println(payload.humidity);*/
  command = Serial.readString();
  if(command=="DISARM"){
    input = "DISARM";
    }
  }
    }
}

