#include "OLEDU8g2.hpp"
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <WiFi.h>
#include <time.h>

extern int isConnected;

// 使用 I2C 连接 SSD1306 OLED，指定 SDA、SCL 端口和屏幕类型
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void OLEDU8g2::setup()
{
  u8g2.begin();
  u8g2.enableUTF8Print(); // 启用 UTF-8 支持以显示中文字符
  // 设置中文字体，此处选择 16x16 像素的字体
  // u8g2.setFont(u8g2_font_unifont_t_chinese2);
  config_time();
}

void OLEDU8g2::loop()
{
  displayChinese();
  if (isConnected)
  {
    displayTime();
  }
}

void OLEDU8g2::config_time()
{
    // 中国大陆使用 UTC +8 时区
  const long utcOffsetInSeconds = 8 * 60 * 60;
  // 正常情况下，中国大陆不使用夏令时，将夏令时偏移量设置为0。
  // 若要考虑夏令时，请相应地设置非零值。
  const int daylightOffsetInSeconds = 0;
  configTime(utcOffsetInSeconds, daylightOffsetInSeconds, "pool.ntp.org"); // 使用 NTP 服务器配置时间
}

void OLEDU8g2::displayTime()
{
  struct tm timeinfo;
  getLocalTime(&timeinfo); // 获取同步的当前时间

  u8g2.setFont(u8g2_font_helvB12_tf);
  u8g2.setCursor(0, 48);                                                             // 设置光标位置
  u8g2.printf("%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); // 打印时间
  u8g2.sendBuffer();

  runingTime();
}

/// @brief 开发版运行的时长
void OLEDU8g2::runingTime()
{
  unsigned long currentTime = millis();
  int seconds = (currentTime / 1000) % 60;
  int minutes = (currentTime / (1000 * 60)) % 60;
  int hours = (currentTime / (1000 * 60 * 60)) % 24;

  // 设置英文字体，此处选择 10x20 像素的字体
  u8g2.setFont(u8g2_font_wqy12_t_gb2312);
  u8g2.setCursor(80, 48);                                  // 设置光标位置
  u8g2.printf("%02d:%02d:%02d", hours, minutes, seconds); // 打印时间
  u8g2.sendBuffer();
}

void OLEDU8g2::displayChinese()
{
  // 设置中文字体，此处选择 12x12 像素的字体
  u8g2.setFont(u8g2_font_wqy12_t_gb2312);
  u8g2.setCursor(0, 16);        // 设置光标位置
  u8g2.print("中华人民共和国"); // 打印中文字符串
  u8g2.sendBuffer();
}