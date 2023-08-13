#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// 引脚定义
#define TFT_CS   15
#define TFT_RST  5
#define TFT_DC   2
#define TFT_SCLK 18
#define TFT_MOSI 23

// 初始化屏幕对象
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  // 初始化串行通信
  Serial.begin(115200);
  
  // 初始化屏幕
  tft.initR(INITR_144GREENTAB);
  tft.setRotation(2);
  tft.fillRect(0, 0, tft.width(), tft.height(), ST7735_BLACK);
  
  // 在屏幕上显示文字
  displayText("Hello ESP32!", ST7735_WHITE, 2, 20, 40);
}

void loop() {
  // 此处可增加其他循环显示内容
}

// 显示文本的函数
void displayText(const char *text, uint16_t color, uint8_t size, int16_t x, int16_t y) {
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.setCursor(x, y);
  tft.print(text);
}
