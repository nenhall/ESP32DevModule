#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OLEDDisplay.hpp"
#include "LED.hpp"
#include "WifiManager.hpp"


void setup()
{
  LED::setup(2);

  // 连接 Wifi
  WifiManager().connectWifi();
}

void loop()
{
  LED::loop(); 
}