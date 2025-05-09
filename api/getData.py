import serial
import time

arduino_port = 'COM8'
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate, timeout=1)

time.sleep(2)

while True:
    data = ser.readline()
    print(data)

    time.sleep(1)