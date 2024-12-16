#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

// Initialize display and sensor objects
TFT_eSPI tft = TFT_eSPI();
Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  
  Wire.begin(21, 22);  // Add this line to explicitly initialize I2C
  
  // Add I2C Scanner
  Serial.println("I2C Scanner starting...");
  byte error, address;
  int nDevices = 0;
  
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }
  
  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  }
  
  // Initialize display
  tft.init();
  Serial.println("Display initialized");
  
  // Turn on the backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  Serial.println("Backlight on");
  
  tft.setRotation(0);
  Serial.println("Set rotation");
  
  tft.fillScreen(TFT_RED);  
  Serial.println("Should be red now");
  
  delay(2000);  // Longer delay to make sure we see it
  
  tft.fillScreen(TFT_BLACK);
  Serial.println("Should be black now");
  
  // Initialize BME280
  if (!bme.begin(0x76)) {
    Serial.println("Could not find BME280 sensor!");
    tft.drawString("BME280 Error!", 10, 10);
    while (1);
  }
}

void loop() {
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  
  tft.fillScreen(TFT_BLACK);
  
  // Left column for Temperature
  tft.setTextSize(2);
  tft.setCursor(5, 20);
  tft.setTextColor(TFT_RED);
  tft.println("Temp");
  tft.setTextSize(5);
  tft.setCursor(5, 40);
  tft.printf("%.1f", temperature);
  
  // Right column for Humidity
  tft.setTextSize(2);
  tft.setCursor(5, 130);
  tft.setTextColor(TFT_BLUE);
  tft.println("Hum");
  tft.setTextSize(5);
  tft.setCursor(5, 150);
  tft.printf("%.1f", humidity);
  
  delay(2000);
}