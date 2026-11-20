IoT-Based Gas Leakage and Temperature Monitoring System
![IoT Gas Leakage and Temperature Monitoring System](gas%20leakage%20monitoring%20system.jpeg)

# Project Overview
The IoT-Based Gas Leakage and Temperature Monitoring System is a hardware-based project developed using Arduino. It is designed to detect gas leakage and monitor surrounding temperature to improve safety and provide early warnings.

# Objectives

- Detect gas leakage using a gas sensor.
- Monitor temperature using a temperature sensor.
- Provide alerts when abnormal conditions are detected.
- Improve safety through real-time monitoring.

# Hardware Components

- Arduino Uno
- MQ-135 Gas Sensor
- DHT11 Temperature and Humidity Sensor
- 16x2 I2C LCD Display
- Buzzer
- LED
- Breadboard
- Connecting Wires
- Power Supply

## Pin Connections

| Component | Arduino Uno Pin |
|---|---|
| DHT11 Data | Digital Pin 2 |
| MQ-135 Analog Output | A0 |
| LED | Digital Pin 7 |
| Buzzer | Digital Pin 8 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |

## Working Principle

1. The MQ-135 sensor detects changes in gas-related air quality.
2. The DHT11 measures temperature and humidity.
3. Arduino Uno processes the sensor readings.
4. The LCD displays temperature, humidity and gas readings.
5. When the gas reading reaches the configured threshold, the LED and buzzer are activated.
6. When the reading is below the threshold, the system displays a SAFE status.

## Software Requirements

- Arduino IDE
- DHT Sensor Library
- Adafruit Unified Sensor Library
- LiquidCrystal I2C Library

## How to Run the Project

1. Install Arduino IDE.
2. Install the required libraries.
3. Connect the sensors and other components to Arduino Uno.
4. Open IoT_Gas_Temperature_Monitoring_System.ino.
5. Select Arduino Uno as the board.
6. Select the correct COM port.
7. Upload the program.
8. Open Serial Monitor to observe sensor readings.

## Gas Threshold

The default gas threshold in the program is 300.

This value should be calibrated according to sensor readings and environmental conditions. It is not a certified gas concentration measurement.

## Future Improvements

- Mobile application integration
- Wireless notifications
- Cloud-based monitoring
- AI-based anomaly detection

## Project Status

Completed - Hardware Prototype

## Developed By

Pavithra P R
