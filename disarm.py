import serial
import time

arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(3)
arduino.flush()

cFile = open("/var/www/html/Command.txt", "r+")

command = cFile.read()


cFile.close()

arduino.write(command.encode('utf-8'))

time.sleep(2)
arduino.flush()
time.sleep(2)

