#include "SSD1306.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED屏幕宽度，根据您的OLED型号进行调整
#define SCREEN_HEIGHT 64 // OLED屏幕高度，根据您的OLED型号进行调整

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void SSD1306::display()
{
    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // 0x3C是I2C地址，根据您的OLED屏幕型号进行调整
    display.display();                         // 显示屏幕初始化
    delay(2000);                               // 延迟2秒，以便您可以看到初始化画面

    display.clearDisplay();              // 清空屏幕缓冲区
    display.setTextSize(1);              // 设置文本大小
    display.setTextColor(SSD1306_WHITE); // 设置文本颜色
    display.setCursor(0, 10);            // 设置文本显示位置
    display.println("Hello, World!");    // 显示文本
    display.display();                   // 刷新屏幕，显示文本在屏幕上
}

void SSD1306::displayImage()
{
    // Include your image data here
    // display.clearDisplay();
    // display.drawBitmap(0, 0, my_image, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    // display.display();
}