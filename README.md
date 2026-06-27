# Smart-irrigation-system
Arduino based smart irrigation system using soil moisture sensor, DHT22(for sensing temperature and humidity from surrounding environment), LCD display, relay and automatic pump control , water tank sensor (to sense the water level in tank) simulated in wokwi

## Project Overview
This project automatically waters plants based on soil moisture.
It also monitors temperature, humidity and water tank level.

## Objective
To reduce water wastage by automatically controlling irrigation.

## Components Used
 Arduino Uno
 Potentiometer (Soil Moisture Simulation)
 Potentiometer (Water Tank Level)
 DHT22
 16x2 I2C LCD
 Relay Module
 LEDs
 Wokwi Simulator

## Software Used
Arduino IDE
Embedded C
 Wokwi

## Features
 Automatic Pump Control
 Soil Moisture Monitoring
 Temperature Monitoring
 Humidity Monitoring
 Water Tank Monitoring
 LCD Display
 Relay Control

## Working Principle
The Arduino continuously reads the soil moisture.
If the soil is dry and the tank has sufficient water,
the relay turns ON the pump.
Temperature and humidity are displayed using the DHT22 sensor.
LCD shows the current system status.

## Future Improvements

 ESP32 Wi-Fi
 IoT Dashboard
 Mobile Notifications
 Mobile App Control

## Wokwi Simulation Link
https://wokwi.com/projects/467630762822395905
