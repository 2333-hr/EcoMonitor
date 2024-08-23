#include <ESP8266WiFi.h>
#include <ESP8266Firebase.h>
#include <ArduinoJson.h>  // Include ArduinoJson library

#define _SSID "Your WiFi SSID" // Your WiFi SSID
#define _PASSWORD "Your WiFi Password" // Your WiFi Password
#define REFERENCE_URL "Your Firebase project reference URL" // Your Firebase project reference URL

Firebase firebase(REFERENCE_URL);

void setup() {
    Serial.begin(115200);
    WiFi.begin(_SSID, _PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected");
}

void loop() {
    if (Serial.available()) {
        String jsonData = Serial.readStringUntil('\n');
        
        // Parse the JSON data
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, jsonData);
        if (error) {
            Serial.print("Failed to parse JSON: ");
            Serial.println(error.c_str());
            return;
        }
        
        // Iterate through each key-value pair in the JSON object
        for (JsonPair kv : doc.as<JsonObject>()) {
            String key = kv.key().c_str();
            String value = kv.value().as<String>();
            String firebasePath = "sensorData/" + key;

            // Upload each key-value pair to Firebase
            firebase.setString(firebasePath.c_str(), value.c_str());
            Serial.println("Data set to Firebase: " + firebasePath + " = " + value);
        }
    }
}
