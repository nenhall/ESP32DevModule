#include "LED.hpp"
#include <Arduino.h>

int LED::ledPin = 2;

void LED::setup(const int pin)
{
      LED::ledPin = pin;
      pinMode(LED::ledPin, OUTPUT); // 将GPIO2设置为输出模式
}

void LED::loop()
{
      digitalWrite(LED::ledPin, HIGH); // 设置GPIO2电平为高，点亮LED
      delay(1000);                     // 等待1秒钟
      digitalWrite(LED::ledPin, LOW);  // 设置GPIO2电平为低，熄灭LED
      delay(1000);                     // 等待1秒钟
}
