# TTGO T1 Weather Station

This project implements a simple weather station using a TTGO T1 ESP32 development board with an integrated ST7789 display and a BME280 temperature/humidity sensor.

## Hardware Requirements

- TTGO T1 ESP32 board
- BME280 temperature/humidity sensor
- Jumper wires for connecting BME280

## Wiring

Connect the BME280 sensor to the TTGO T1 board:
- VIN -> 3.3V
- GND -> GND  
- SCL -> GPIO22
- SDA -> GPIO21

## Software Requirements

This project uses PlatformIO and requires the following libraries:
- TFT_eSPI
- Adafruit BME280 Library

## Features

- Displays temperature and humidity readings on the TFT screen
- Updates every 2 seconds
- Temperature shown in °C
- Humidity shown as percentage
- Serial debugging output

## Building and Uploading

1. Clone this repository
2. Open in PlatformIO
3. Build and upload to your TTGO T1 board

## Configuration

The display and pin configurations are set in `platformio.ini`. The BME280 sensor uses I2C communication on pins 21 (SDA) and 22 (SCL).
kor e bala