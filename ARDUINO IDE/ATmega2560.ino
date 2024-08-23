#include <Wire.h>
#include <SPI.h>
#include "bme68xLibrary.h"
#include "DFRobot_MICS.h"
#include "PMS.h"
#include "MQ131.h"

// Analog and SPI pin definitions
const int vocPin = A2;
const int coPin = A1;
const int mq131Pin = A6;
#define PIN_CS 10

#define ADC_PIN A0
#define CALIBRATION_TIME   3  
DFRobot_MICS_ADC mics(/*adcPin*/ADC_PIN);

Bme68x bme;

PMS pms(Serial1);
PMS::DATA data;

bool mq131Calibrated = false;

void setup() {
    Serial.begin(115200);
    Serial1.begin(9600);
    Serial3.begin(115200);

    pinMode(vocPin, INPUT);
    pinMode(coPin, INPUT);
    pinMode(mq131Pin, INPUT);
    pinMode(PIN_CS, OUTPUT);
    digitalWrite(PIN_CS, HIGH);  // Ensure CS starts high

    SPI.begin();
    bme.begin(PIN_CS, SPI);

     // 初始化MICS传感器
    while(!Serial);
    while(!mics.begin()){
    Serial.println("NO Deivces !");
    delay(1000);
  } Serial.println("Device connected successfully !");

    // 确保传感器不在休眠模式
    uint8_t mode = mics.getPowerState();
    if (mode == SLEEP_MODE) {
        mics.wakeUpMode();
        Serial.println("Waking up MICS sensor...");
    } else {
        Serial.println("Sensor already in active mode.");
    }

    while(!mics.warmUpTime(CALIBRATION_TIME)){
    Serial.println("Please wait until the warm-up time is over!");
    delay(1000);
    }

    while (!mq131Calibrated) {
        MQ131.begin(24, mq131Pin, LOW_CONCENTRATION, 1000000);
        MQ131.calibrate();
        Serial.println("MQ131 Calibration done!");
        mq131Calibrated = true;
    }

    bme.setTPH();
    bme.setHeaterProf(300, 100);
}


void loop() {
    readSensorsAndSendData();
    delay(10000);

    // Receive and print data from ESP8266
    if (Serial3.available()) {
        String espData = Serial3.readStringUntil('\n');
        if (espData.length() > 0) {
            Serial.println("From ESP8266: " + espData);
        }
    }

}

void readSensorsAndSendData() {
    String jsonData = "{";

    bme.setOpMode(BME68X_FORCED_MODE);
    if (bme.fetchData()) {
        bme68xData bmeData;
        bme.getData(bmeData);
        jsonData += "\"Temperature\":\"" + String(bmeData.temperature) + "\",";
        jsonData += "\"Humidity\":\"" + String(bmeData.humidity) + "\",";
        jsonData += "\"Pressure\":\"" + String(bmeData.pressure) + "\",";
        jsonData += "\"GasResistance\":\"" + String(bmeData.gas_resistance) + "\",";
    }

    int vocValue = analogRead(vocPin);
    int coValue = analogRead(coPin);
    float no2 = mics.getGasData(NO2);
    pms.read(data);

    jsonData += "\"VOC\":\"" + String(vocValue * (5.0 / 1023.0), 3) + "\",";
    jsonData += "\"CO\":\"" + String(coValue * (5.0 / 1023.0), 3) + "\",";
    jsonData += "\"NO2\":\"" + String(no2) + "\",";
    jsonData += "\"O3\":\"" + String(MQ131.getO3(PPM)) + "\",";
    jsonData += "\"PM1_0\":\"" + String(data.PM_AE_UG_1_0) + "\",";
    jsonData += "\"PM2_5\":\"" + String(data.PM_AE_UG_2_5) + "\",";
    jsonData += "\"PM10_0\":\"" + String(data.PM_AE_UG_10_0) + "\"}";
    
    
    Serial3.println(jsonData);  
}

