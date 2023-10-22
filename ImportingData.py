import serial
import datetime

# Open the serial port
ser = serial.Serial('COM3', 9600) 

try:
    while True:
        # Read a line of data from the Arduino
        data = ser.readline().decode('utf-8').strip()
        timestamp = datetime.datetime.now().strftime("%m/%d/%Y-%I:%M:%S %p")
        print(f"{timestamp} - {data}") 
except KeyboardInterrupt:
    ser.close()
