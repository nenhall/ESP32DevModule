#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OLEDU8g2.hpp"
#include "LED.hpp"
#include "WifiManager.hpp"
#include "BLE.hpp"

OLEDU8g2 oled;

extern int isConnected;

void setup()
{
  LED::setup(2);

  // 初始化串行通信
  Serial.begin(115200);
  delay(10);

  oled.setup();

  // 开启蓝牙
  // BLE::setup();

  // 连接 Wifi
  WifiManager().connectWifi();
}

void loop()
{
  LED::loop();
  oled.loop();
}