#include "SPI.h"
#include "ILI9341_t3.h"
#include "font_Arial.h"
#define TFT_DC       9
#define TFT_CS      10
#define TFT_RST    255
#define TFT_MOSI    11
#define TFT_SCLK    13
#define TFT_MISO    12

class Menu {
    ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);
    public:
        void start(){
            tft.begin();                                // Start TFT
            tft.fillScreen(ILI9341_WHITE);              
            tft.setRotation(3);
            tft.setTextSize(3);
            tft.setCursor(108, 12);
            tft.print("Test");
            delay(1000);
        }
        void clear(){
            tft.fillScreen(ILI9341_BLACK);
        }
        void rect(){
            tft.setRotation(0);
            tft.fillRect(0, 0, 60, 320, ILI9341_WHITE);
            tft.drawRect(60, 0, 90, 320, ILI9341_WHITE);
            tft.drawRect(150, 0, 90, 107, ILI9341_WHITE);
            tft.drawRect(150, 106, 90, 107, ILI9341_WHITE);
            tft.drawRect(150, 212, 90, 108, ILI9341_WHITE);
        }
};

Menu Display;









