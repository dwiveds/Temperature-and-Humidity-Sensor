#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DPIN 4        //Pin to connect DHT sensor (GPIO number)
#define DTYPE DHT11   // Define DHT 11 or DHT22 sensor type
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

DHT dht(DPIN,DTYPE);

void setup() {
   lcd.init();                       // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.clear();                      // Clear the LCD screen
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  
  float tc = dht.readTemperature(false);  //Read temperature in C
  float tf = dht.readTemperature(true);   //Read Temperature in F
  float hu = dht.readHumidity(); 
   lcd.setCursor(0, 0);               // Set the cursor to the first column and first row
  lcd.print("    TEMP:   ");
  lcd.print(tc);// Print some text
  
  lcd.setCursor(0,1);
  lcd.print("Humi.:");
  lcd.print(hu);

  
}
