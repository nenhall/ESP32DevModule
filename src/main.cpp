#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OLEDDisplay.hpp"
#include "LED.hpp"
// #include "WifiManager.hpp"
#include "BLE.hpp"

void setup()
{
  LED::setup(2);

  // 初始化串行通信
  Serial.begin(115200);
  delay(10);

  // 连接 Wifi
  // WifiManager().connectWifi();

  // 开启蓝牙
  BLE::setup();
}

void loop()
{
  LED::loop();
}