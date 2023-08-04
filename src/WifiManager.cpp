#include "WifiManager.hpp"
#include <Arduino.h>
#include <WiFi.h>


void WifiManager::connectWifi()
{
  Serial.begin(115200);
  delay(10);

  Serial.println("\n Connecting to WiFi...");

  WiFi.begin(ssid.c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("\n WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
