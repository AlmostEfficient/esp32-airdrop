#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "web_content.h" // Include the HTML content

WebServer server(80);
DNSServer dnsServer;

const char *ssid = "Bruh-moment";        // SSID (network name)
const char *password = "password"; // Password for the AP
IPAddress apIP(192, 168, 1, 1);         // IP address for the AP interface

void setup() {
  Serial.begin(115200); // Start the serial communication
  WiFi.softAP(ssid, password); // Start the AP

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP()); // Print the IP address of the AP

  dnsServer.start(53, "*", WiFi.softAPIP());

  server.onNotFound([]() {
    server.send(200, "text/html", html_content); // Serve the HTML content
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  dnsServer.processNextRequest(); // Captive portal DNS re-routing
  server.handleClient();
  uint32_t freeHeap = ESP.getFreeHeap();

  // Print the free heap memory to the serial monitor
  Serial.print("Free Heap Memory: ");
  Serial.print(freeHeap);
  Serial.println(" bytes");

  // Add a delay to avoid flooding the serial monitor
  delay(5000);
}
