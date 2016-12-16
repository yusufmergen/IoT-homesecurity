#include <RF24Network.h>
#include <RF24.h>
#include<SPI.h>


RF24 radio(7, 8);
RF24Network network(radio);

const uint16_t master = 00;
const uint16_t pir = 01;
const uint16_t magSwitch = 02;
const uint16_t temphumd = 03;
int led = 3;
int inputPin = 2;




void setup() {
  pinMode(led,  OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("RF24Network Begins..");
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 100, /*node address*/ pir);
}

void loop() {

  network.update();
  RF24NetworkHeader header(/*to node*/ master);
  if(digitalRead(inputPin) == HIGH){
  
  int payload = 1;
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  
  bool ok = network.write(header, &payload, sizeof(payload));
  if(ok)
  Serial.println("Sending");
  else
  Serial.println("Failed to send");
  
  }
  

}
