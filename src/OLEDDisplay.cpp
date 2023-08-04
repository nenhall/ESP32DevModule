#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// #include <U8g2lib.h>

// 选择您的OLED屏幕类型
// 注意：在使用之前，请确认以下行中的配置与您的OLED屏幕匹配
// U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

#define SCREEN_WIDTH 128 // OLED屏幕宽度，根据您的OLED型号进行调整
#define SCREEN_HEIGHT 64 // OLED屏幕高度，根据您的OLED型号进行调整

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

class OLEDDisplay
{
private:
  /* data */
public:
  void ssd1306Setup()
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
  void u8g2Setup()
  {
    // 初始化OLED屏幕
    // u8g2.begin();
  }
  void u8g2Loop()
  {
    // 清空屏幕缓冲区
    // u8g2.clearBuffer();

    // // 设置字体
    // u8g2.setFont(u8g2_font_ncenB14_tr);

    // // 显示文本
    // u8g2.setCursor(0, 30); // 设置文本显示的位置
    // u8g2.print("Hello, World!");

    // // 刷新屏幕缓冲区，将文本显示在屏幕上
    // u8g2.sendBuffer();

    // delay(1000); // 等待1秒钟
  }
};