#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "web_content.h" // Include the HTML content

WebServer server(80);
DNSServer dnsServer;

const char *ssid = "Bruh-moment";        // SSID (network name)
const char *password = "password"; // Password for the AP
IPAddress apIP(192, 168, 1, 1);         // IP address for the AP interface

// Function prototypes
bool isDeviceRegistered(const String& uid);
void removeDevice(int index);
void handleDeviceRegistration();
void handleCodeClaim();
void checkForDisconnectedDevices();

// Device information structure
struct DeviceInfo {
  String uid;
  unsigned long timestamp;
};

const int maxDevices = 10; // Maximum number of devices
DeviceInfo registeredDevices[maxDevices]; // Array to store device information
int deviceCount = 0; // Number of registered devices

const char* codes[] = {"CODE1", "CODE2", "CODE3", /*... add more codes ...*/ };
const int codeCount = sizeof(codes) / sizeof(codes[0]);
bool codeClaimed[codeCount] = {false}; // Track claimed status

void setup() {
  Serial.begin(115200); // Start the serial communication
  WiFi.softAP(ssid, password); // Start the AP

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP()); // Print the IP address of the AP

  dnsServer.start(53, "*", WiFi.softAPIP());

  server.begin();
  Serial.println("HTTP server started");
  server.on("/register_device", handleDeviceRegistration);
  server.on("/claim_code", handleCodeClaim);
  server.on("/ping", []() {
    server.send(200, "text/plain", "Pong");
  });
  server.onNotFound([]() {
    Serial.print("Incoming request from: ");
    Serial.print(server.client().remoteIP()); // Logs the client's IP address
    Serial.print(" Requested URL: ");
    Serial.println(server.uri()); // Logs the URI of the request

    server.send(200, "text/html", html_content); // Serve the HTML content
  });


}

void loop() {
  dnsServer.processNextRequest(); // Captive portal DNS re-routing
  server.handleClient();
  checkForDisconnectedDevices();
}

void registerDevice(const String& uid) {
  registeredDevices[deviceCount].uid = uid;
  registeredDevices[deviceCount].timestamp = millis();
  deviceCount++;
}

bool isDeviceRegistered(const String& uid) {
  for (int i = 0; i < deviceCount; i++) {
    if (registeredDevices[i].uid == uid) {
      return true;
    }
  }
  return false;
}

void handleDeviceRegistration() {
  Serial.print("Incoming request from: ");
  Serial.print(server.client().remoteIP()); // Logs the client's IP address
  Serial.print(" Requested URL: ");
  Serial.println(server.uri()); // Logs the URI of the request
  // Log args
  for (int i = 0; i < server.args(); i++) {
    Serial.print(server.argName(i));
    Serial.print(": ");
    Serial.println(server.arg(i));
  }
  
  String uid = server.arg("uid"); // Get UID from request
  if (!isDeviceRegistered(uid)) {
    if (deviceCount < maxDevices) {
      registerDevice(uid);

      Serial.print("Device registered: ");
      Serial.println(uid); // Print the UID of the registered device

      server.send(200, "text/plain", "Device registered");
    } else {
      server.send(503, "text/plain", "Device limit reached");
    }
  } else {
    Serial.print("Device already registered: ");
    Serial.println(uid); // Print the UID of the already registered device
    server.send(200, "text/plain", "Device already registered");
  }
}

void checkForDisconnectedDevices() {
  unsigned long currentTime = millis();
  for (int i = 0; i < deviceCount; i++) {
    if (currentTime - registeredDevices[i].timestamp > 300000) { // 5 minutes
      removeDevice(i);
      i--; // Adjust index after removal
    }
  }
}

void removeDevice(int index) {
  for (int i = index; i < deviceCount - 1; i++) {
    registeredDevices[i] = registeredDevices[i + 1];
  }
  deviceCount--;
}

void handleCodeClaim() {
  String deviceuid = server.arg("uid");
  if (isDeviceRegistered(deviceuid)) {
    for (int i = 0; i < codeCount; i++) {
      if (!codeClaimed[i]) {
        codeClaimed[i] = true;
        server.send(200, "text/plain", codes[i]);
        return;
      }
    }
    server.send(503, "text/plain", "No more codes available");
  } else {
    server.send(401, "text/plain", "Device not registered");
  }
}
