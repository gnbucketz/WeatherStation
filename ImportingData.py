import serial
import tkinter as tk

ser = serial.Serial('COM3', 9600) 
root = tk.Tk()

root.title("Weather Station")
root.configure(bg="lightgray")
temperature_label = tk.Label(root, text="The current ", bg="lightgray")
humidity_label = tk.Label(root, text="The current ", bg="lightgray")
temperature_entry = tk.Entry(root)
humidity_entry = tk.Entry(root)

try:
    while True:
        # Read a line of data from the Arduino
        data = ser.readline().decode('utf-8').strip()
        print(data)  
except KeyboardInterrupt:
    ser.close()