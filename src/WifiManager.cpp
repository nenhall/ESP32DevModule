#include "WifiManager.hpp"
#include <Arduino.h>
#include <WiFi.h>


int isConnected = 0;

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
  isConnected = 1;
  Serial.println("\n WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void WifiManager::setValue(int newValue)
{
  isConnected = newValue;
}

int WifiManager::getValue() const
{
  return isConnected;
}
