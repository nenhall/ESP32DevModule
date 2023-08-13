#include "DisplayRGB.hpp"
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "ImageData.hpp"


// Pin definitions for the ILI9341 screen
#define TFT_CLK 14
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST 4


// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);


void DisplayRGB::drawRGB888Image() 
{
// Serial.begin(115200);
  
//   tft.begin();
//   tft.setRotation(3); // Set the orientation of the display
//   tft.fillScreen(ILI9341_BLACK);

//   int imageWidth = 128;
//   int imageHeight = 64;

//   for(int y = 0; y < imageHeight; y++) {
//     for(int x = 0; x < imageWidth; x++) {
//     //   tft.drawPixel(x, y, rgb_image_map[y * imageWidth + x]);
//     }
//   }
}
