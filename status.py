import serial
import time

arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(3)
arduino.flush()

cFile = open("/var/www/html/Command.txt", "r+")

command = cFile.read()

cFile.close()

arduino.write(command.encode('utf-8'))

time.sleep(3)
def returnFn(value):
    return value


while arduino.is_open:
    input = arduino.readline().decode('utf-8')
    print(input)
    break
arduino.close()
    




            
