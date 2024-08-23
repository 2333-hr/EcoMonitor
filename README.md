# EcoMonitor: Real-Time Outdoor Air Quality Monitoring Using IoT-Based Sensor Networks in Urban Environments

## Overview
EcoMonitor is a real-time air quality monitoring system developed to assess and visualize air quality data in urban environments. The system utilizes IoT-based sensor networks to monitor various air pollutants, such as PM2.5, PM10, CO, NO<sub>2</sub>, O<sub>3</sub>, VOCs, and other environmental parameters like temperature, humidity, and atmospheric pressure. The collected data is transmitted to Firebase in real-time and made accessible through a user-friendly web interface.

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
- **Real-time Monitoring**: Continuous tracking of air quality parameters including PM1, PM2.5, PM10, CO, NO<sub>2</sub>, O<sub>3</sub>, and VOCs.
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
 - <img width="175" alt="image" src="https://github.com/user-attachments/assets/b30c2d42-0589-4405-88ff-379d8ae266f9">
- **MQ131**: Ozone Sensor (O<sub>3</sub>)
- <img width="131" alt="image" src="https://github.com/user-attachments/assets/ca9790b7-b8f9-4277-9eb2-b329aaf20bf5">
- **WaveShare BME688**: Measures temperature, humidity, gas resistance, and atmospheric pressure
- <img width="131" alt="image" src="https://github.com/user-attachments/assets/29e67903-ab99-46fd-90e1-fa3f158f97b3">
- **DFRobot Fermion MEMS CO Sensor**: Carbon Monoxide (CO) Sensor
- <img width="131" alt="image" src="https://github.com/user-attachments/assets/dd9b786a-7217-4b5b-85d4-8ec1a4483a1f">
- **DFRobot Fermion MEMS VOC Sensor**: Volatile Organic Compounds (VOC) Sensor
- <img width="131" alt="image" src="https://github.com/user-attachments/assets/c6783ce9-ec12-4192-ad93-af66709ed871">
- **DFRobot Fermion MEMS Gas Sensor - MiCS-2714**: Nitrogen Dioxide (NO<sub>2</sub>) Sensor
- <img width="131" alt="image" src="https://github.com/user-attachments/assets/d1e2357f-d88b-4469-bffc-de663a6603b4">
- **Robotdyn ATmega2560 + ESP8266**: Main microcontroller for data acquisition and Wi-Fi connectivity
- <img width="175" alt="image" src="https://github.com/user-attachments/assets/91f46d03-6cd7-49ef-a840-4e2617cb27c5">
- https://robotdyn.com/mega-wifi-r3-atmega2560-esp8266-flash-32mb-usb-ttl-ch340g-micro-usb.html
- **WaveShare 15W Solar Panel and 9900mAh Lithium Battery**: Powers the sensor box
- <img width="175" alt="image" src="https://github.com/user-attachments/assets/a04c28b8-855a-448b-87a2-002d876144d1">
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

1. **Create the PCB Board**:
   - Download the [ATmega2560 PCB Board.zip](./ATmega2560%20PCB%20Board.zip) file.
   - Unzip the file and directly upload the Gerber files to a PCB manufacturer's website (e.g., JLCPCB, PCBWay) through their online ordering system.
   - Once the PCB is fabricated, solder the components according to the needs.

2. **3D Print the Enclosure**:
   - Navigate to the [3D model](./3D%20model) folder.
   - Use the provided STL files to 3D print the enclosure. Please note that the model should be scaled to **0.17 times** the original size provided in the files for optimal fit and functionality.
   - Ensure that the material used for printing (such as PETG) is suitable for outdoor conditions.
   - After printing, assemble the enclosure, ensuring all components fit securely.

3. **Run Arduino Code**: 
   - Navigate to the [ARDUINO CODE](./ARDUINO%20CODE) folder.
   - Open the `.ino` file in Arduino IDE.
   - Upload the code to the ATmega2560 + ESP8266 board.

4. **Set Up the Web Interface**:
   - Go to the [Web Interface Code](./Web%20Interface%20Code) folder.
   - Deploy the web interface using Firebase.

5. **Assemble the Sensor Box**:
   - **Connect the Sensors and Main Control Board**:
     - Solder or connect the sensors onto the PCB board following the provided schematic.
     - Connect the ATmega2560 + ESP8266 microcontroller to the PCB, ensuring all sensor connections are secure and correct.
   - **Mount the PCB into the Enclosure**:
     - Carefully place the assembled PCB with connected sensors into the 3D-printed enclosure.
   - **Power Connections**:
     - Connect the solar panel and battery to the ATmega2560+ESP8266 to power the system.
     - Double-check all connections to ensure they are secure.
   - **Seal the Enclosure**:
     - Make sure the enclosure is properly sealed to protect the internal components from environmental factors.

6. **Power On the System**:
   - Once assembled, power on the sensor box by ensuring the solar panel and battery are connected.

7. **Begin Data Collection**:
   - The sensor box will start collecting and transmitting data to Firebase automatically.

8. **Access the Web Interface**:
   - **For this project**: Scan the QR code included in the [QR code](./QR%20code) folder to access the pre-deployed web interface for this specific project. This will allow you to monitor real-time air quality data in an easy-to-read format.
   - **For your own project**: If you are deploying your own version of this project, you will need to generate a new QR code linked to the web interface URL provided by Firebase after your deployment. You can use any QR code generator tool to create a QR code that links to your Firebase-hosted web interface.

By following these steps, you'll be able to build, deploy, and use the EcoMonitor system to monitor air quality in your chosen locations.

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
No license is associated with this project. Please contact the author for any questions regarding usage.

## Contact
For any questions or inquiries, please contact ucfnhy0@ucl.ac.uk
