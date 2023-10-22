#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define DHTPIN 6 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  lcd.init();           
  lcd.backlight();      
  lcd.setCursor(0, 0);
  lcd.print("Temp:      ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:  ");

  dht.begin();          
}

void loop() {
  delay(1000); // Delay between readings

  float temperatureC = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();       

  if (!isnan(temperatureC) && !isnan(humidity)) {
    float temperatureF = (temperatureC * 9/5) + 32; // Convert to Fahrenheit

    lcd.setCursor(7, 0);
    lcd.print(temperatureF, 1); 
    lcd.print("F");

    lcd.setCursor(10, 1);
    lcd.print(humidity, 1); 
    lcd.setCursor(14, 1);
    lcd.print("%");

    // Send data to the computer
    Serial.print("Temperature: ");
    Serial.print(temperatureF, 1);
    Serial.print("F, Humidity: ");
    Serial.print(humidity, 1);
    Serial.println("%");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Error reading data");
  }
}