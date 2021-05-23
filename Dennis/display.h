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
            tft.setTextColor(ILI9341_BLACK);
            tft.setCursor(100, 100);
            tft.print("Audio FX");
            delay(1000);
            tft.fillScreen(ILI9341_BLACK);              
            tft.setRotation(3);
            tft.setTextSize(3);
            tft.setTextColor(ILI9341_WHITE);
            tft.setCursor(75, 140);
            tft.print("David Yaman");
            tft.setCursor(145, 110);
            tft.print(" & ");
            tft.setCursor(75, 80);
            tft.print("Dennis Raek");
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
            tft.setRotation(3);
            tft.setTextColor(ILI9341_BLACK); 
            tft.setCursor(100, 20);
            tft.print("Audio FX");
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(120, 160);
            tft.setTextSize(2);
            tft.print("Dry/Wet");
            tft.setTextSize(3);
        }
        void fx_chrous(){
            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(110, 90);
            tft.print("Chrous");
        }
        
        void fx_delay(){
            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(110, 90);
            tft.print("Delay");
        }

        void fx_distortion(){
            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(90, 90);
            tft.print("Distortion");
        }

        void fx_reverb(){
            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(120, 90);
            tft.print("Reverb");
            tft.setTextSize(2);
            tft.setCursor(13, 160);
            tft.print("Damping");
            tft.setCursor(245, 160);
            tft.print("Room");
            tft.setCursor(245, 180);
            tft.print("Size");
        }
       
        
          
        
};

Menu Display;









