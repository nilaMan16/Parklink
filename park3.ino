#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Tenda_94E9E0";  // Replace with your Wi-Fi SSID
const char* password = "12345678";          // Replace with your Wi-Fi password
const char* serverName = "http://192.168.0.150:4000/api/v1/auth/data"; // Replace with your server IP

// Define pins for ultrasonic sensors
const int trigPins[4] = {12, 19, 26, 32}; // Trigger pins for sensors 1 to 4
const int echoPins[4] = {13, 18, 27, 33}; // Echo pins for sensors 1 to 4

// Array to store previous distances
float previousDistances[4] = {-1, -1, -1, -1};

// Threshold to determine significant change
const float changeThreshold = 7.0; // Change in cm

// Function to measure distance from an ultrasonic sensor
float readUltrasonicDistance(int trigPin, int echoPin) {
  // Ensure a clean trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure duration of echo signal
  long duration = pulseIn(echoPin, HIGH, 30000);  // Timeout of 30ms

  // Check if the sensor timed out
  if (duration == 0) {
    Serial.println("No echo received, timeout!");
    return -1;  // Use -1 to indicate an error
  }

  // Calculate distance in centimeters
  return (duration * 0.0343) / 2;
}

void setup() {
  Serial.begin(115200);

  // Initialize ultrasonic sensor pins
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  // Array to store current distances
  float distances[4];
  bool dataChanged = false;

  // Read distances from all sensors
  for (int i = 0; i < 4; i++) {
    distances[i] = readUltrasonicDistance(trigPins[i], echoPins[i]);
    if (distances[i] != -1) {
      Serial.printf("Sensor %d: %.2f cm\n", i + 1, distances[i]);
      // Check if the change exceeds the threshold
      if (fabs(distances[i] - previousDistances[i]) > changeThreshold) {
        dataChanged = true;
      }
    } else {
      Serial.printf("Sensor %d: Error\n", i + 1);
    }
  }

  // Send data only if there is a change
  if (dataChanged) {
    // Prepare JSON payload with ESP ID and sensor data as separate fields
    String jsonPayload = "[";
    jsonPayload += "\"esp2107100070\", ";

    // Loop through the distances array
    for (int i = 0; i < 4; i++) {
      jsonPayload += String(distances[i]);
      if (i < 4 - 1) {
        jsonPayload += ", ";  // Add a comma if it's not the last element
      }
      // Update previous distances
      previousDistances[i] = distances[i];
    }

    jsonPayload += "]";

    // Send data to the server
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverName);
      http.addHeader("Content-Type", "application/json");

      int httpResponseCode = http.POST(jsonPayload);

      if (httpResponseCode > 0) {
        String response = http.getString();
        Serial.printf("HTTP Response code: %d\n", httpResponseCode);
        Serial.println(response);
      } else {
        Serial.printf("Error code: %d\n", httpResponseCode);
      }
      http.end();
    } else {
      Serial.println("Wi-Fi not connected");
    }
  } else {
    Serial.println("No significant change in data");
  }

  delay(5000); // Wait for 5 seconds before the next reading
}
