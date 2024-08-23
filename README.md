# EcoMonitor: Real-Time Outdoor Air Quality Monitoring Using IoT-Based Sensor Networks in Urban Environments

## Overview
EcoMonitor is a real-time air quality monitoring system developed to assess and visualize air quality data in urban environments. The system utilizes IoT-based sensor networks to monitor various air pollutants, such as PM2.5, PM10, CO, NO2, O3, VOCs, and other environmental parameters like temperature, humidity, and atmospheric pressure. The collected data is transmitted to Firebase in real-time and made accessible through a user-friendly web interface.

## Table of Contents
1. [Project Description](#project-description)
2. [Features](#features)
3. [System Architecture](#system-architecture)
4. [Hardware Components](#hardware-components)
5. [Software Components](#software-components)
6. [Installation and Setup](#installation-and-setup)
7. [How to Use](#how-to-use)
8. [Results and Analysis](#results-and-analysis)
9. [Limitations](#limitations)
10. [Future Work](#future-work)
11. [License](#license)

## Project Description
EcoMonitor was developed to fill the gap in real-time air quality monitoring, especially in urban parks and residential areas with low traffic, where traditional monitoring systems may not be as effective. This project is particularly focused on collecting accurate air quality data, processing it in real-time, and providing users with immediate access through a web interface.

## Features
- **Real-time Monitoring**: Continuous tracking of air quality parameters including PM1, PM2.5, PM10, CO, NO2, O3, and VOCs.
- **Cloud Integration**: Data is uploaded to Firebase for real-time storage and retrieval.
- **User-friendly Interface**: Access air quality data on-the-go via a responsive web interface.
- **Environmental Adaptability**: The sensor box is designed for outdoor use, powered by a solar panel with battery backup, ensuring consistent operation even in remote locations.

## System Architecture
The system architecture involves several key components:
- **Data Collection**: Sensors detect air pollutants and environmental conditions, sending the data to an ATmega2560 microcontroller.
- **Data Transmission**: Processed data is transmitted using the ESP8266 Wi-Fi module to Firebase in JSON format.
- **Data Storage and Visualization**: Firebase handles the real-time storage, and the data is displayed on a web interface accessible via QR code.

## Hardware Components
- **PMS7003**: Particulate Matter Sensor (PM1, PM2.5, PM10)
- **MQ131**: Ozone Sensor (O3)
- **WaveShare BME688**: Measures temperature, humidity, gas resistance, and atmospheric pressure
- **DFRobot Fermion MEMS CO Sensor**: Carbon Monoxide (CO) Sensor
- **DFRobot Fermion MEMS VOC Sensor**: Volatile Organic Compounds (VOC) Sensor
- **DFRobot Fermion MEMS Gas Sensor - MiCS-2714**: Nitrogen Dioxide (NO2) Sensor
- **Robotdyn ATmega2560 + ESP8266**: Main microcontroller for data acquisition and Wi-Fi connectivity
- **15W Solar Panel and 9900mAh Lithium Battery**: Powers the sensor box
- **3D-Printed PETG Enclosure**: Protects the sensors in outdoor environments

## Software Components
- **Arduino IDE**: Used for programming the microcontroller (ATmega2560 and ESP8266).
- **Firebase**: Real-time database for storing and retrieving data.
- **HTML/CSS/JavaScript**: For developing the web interface.
- **JSON**: Data format used for transmitting sensor data to Firebase.

## Installation and Setup
1. **Hardware Setup**:
   - Assemble the sensor components on the custom PCB.
   - Connect the PCB to the ATmega2560 and ESP8266.
   - Mount the sensors in the 3D-printed PETG enclosure.
   - Install the solar panel and battery to power the system.

2. **Software Installation**:
   - Install necessary libraries for the Arduino IDE:bme68xLibrary.h;DFRobot_MICS.h;PMS.h;MQ131.h
   - Program the ATmega2560 and ESP8266 using Arduino IDE.
   - Set up Firebase and configure real-time database rules.
   - Deploy the web interface using Firebase Hosting.

4. **Configuration**:
   - Modify the Firebase API keys and database URLs in the Arduino code.
   - Test the system for stable data transmission and sensor accuracy.

## How to Use
1. Power on the sensor box by ensuring the solar panel and battery are connected.
2. The sensor box will begin collecting and transmitting data to Firebase.
3. Scan the QR code (included in the repository) to access the web interface.
4. Monitor real-time air quality data, displayed in an easy-to-read format.

## Results and Analysis
- The system was deployed in various locations within East London, including Elizabeth Olympic Park.
- Results indicate consistently low pollutant levels, suggesting good air quality in these areas.
- Detailed data and graphs are available in the project repository for further analysis.

## Limitations
- **Sensor Accuracy**: Budget constraints led to the use of less accurate analog voltage sensors for VOC and CO measurements.
- **Data Transmission**: While Firebase provides robust data storage, there can be slight delays in real-time data visualization.
- **Durability**: The 3D-printed PETG enclosure may degrade under extreme weather conditions over time.

## Future Work
- **Sensor Upgrades**: Implementing more accurate digital sensors for VOCs and CO.
- **Timestamping**: Adding timestamps to each data entry for better temporal analysis.
- **Long-term Deployment**: Testing the system’s durability in more diverse weather conditions.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
