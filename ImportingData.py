import serial

# Open the serial port
ser = serial.Serial('COM3', 9600) 

try:
    while True:
        # Read a line of data from the Arduino
        data = ser.readline().decode('utf-8').strip()
        print(data) 
except KeyboardInterrupt:
    ser.close()
