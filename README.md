# IoT-homesecurity
Home Security System with Raspberry Pi, Arduinos and RF24 transceivers.

This project includes 4 arduinos with sensors and a Raspberry Pi. ".ino" files are scripts for sensor embedded Arduinos. Python files work on the server(RPi) to write and read data from the USB serial connected Master Arduino. Structure is as follows: One arduino with RF24 recevier is connected via serial port to the Raspberry Pi. Remainig 3 Arduinos are embedded with sensors such as temperature, PIR and magnetic switch. When a sensor sends high, Arduion will send data through RF24 to the Master Arduino. PHP files work on the server(RPi). Bootstrap is used on styling the website. 

RF24 and RF24Network libraries are downloaded from https://github.com/TMRh20/RF24 and https://github.com/TMRh20/RF24Network

DHT11 library is required for temperature sensor as well. 
