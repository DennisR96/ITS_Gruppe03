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
            tft.begin();

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
            tft.print("Wet");
            tft.setTextSize(3);
        }
        void next(){
            tft.setRotation(0);
            tft.fillRect(70, 7, 70, 300, ILI9341_BLACK);                    
            tft.fillRect(155, 4, 80, 95, ILI9341_BLACK);                    
            tft.fillRect(155, 110, 80, 95, ILI9341_BLACK);                   
            tft.fillRect(155, 218, 80, 95, ILI9341_BLACK);                   
        }

        void fft(){
            clear();
            tft.setRotation(0);
            tft.fillRect(0, 0, 60, 320, ILI9341_WHITE);
            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(0, 20);
            tft.setTextColor(ILI9341_BLACK);
            tft.print("        FFT");
            tft.setRotation(1);
            tft.fillRect(305, 20, 10, 150, ILI9341_GREEN);
            tft.fillRect(285, 20, 10, 150, ILI9341_GREEN);
            tft.fillRect(265, 20, 10, 150, ILI9341_GREEN);
            tft.fillRect(245, 20, 10, 150, ILI9341_GREEN);
            tft.fillRect(225, 20, 10, 150, ILI9341_GREEN);
            tft.fillRect(205, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(185, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(165, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(145, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(125, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(105, 20, 10, 150, ILI9341_BLUE);
            tft.fillRect(85, 20, 10, 150, ILI9341_RED);
            tft.fillRect(65, 20, 10, 150, ILI9341_RED);
            tft.fillRect(45, 20, 10, 150, ILI9341_RED);
            tft.fillRect(25, 20, 10, 150, ILI9341_RED);
            tft.fillRect(5, 20, 10, 150, ILI9341_RED);
            
            tft.setTextSize(1);
            tft.setRotation(3);
            tft.setCursor(25, 225);
            tft.setTextColor(ILI9341_GREEN);
            tft.print("50 - 2kHz");
            tft.setCursor(130, 225);
            tft.setTextColor(ILI9341_BLUE);
            tft.print("2kHz - 8kHz");
            tft.setCursor(233, 225);
            tft.setTextColor(ILI9341_RED);
            tft.print("8kHz - 20kHz");
            tft.setTextSize(3);
        }
        void reverb(){
            clear();
            rect();

            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(0, 90);
            tft.print("      Reverb");

            tft.setTextSize(2);
            tft.setCursor(13, 160);
            tft.print("Damping");
            tft.setCursor(120, 160);
            tft.print("Wet");
            
            tft.setCursor(225, 160);
            tft.print("Room");
            tft.setTextSize(3);
        }

        void filter(){
            clear();
            rect();

            tft.setRotation(3);
            tft.setTextColor(ILI9341_WHITE); 
            tft.setCursor(0, 90);
            tft.print("      Filter");

            tft.setTextSize(2);
            tft.setCursor(13, 160);
            tft.print("L-Cut");
            tft.setCursor(120, 160);
            tft.print("Wet");
            
            tft.setCursor(225, 160);
            tft.print("H-Cut");
            tft.setTextSize(3);
        }
        
        void update_p(int p1, int p2, int p3){
            tft.setTextSize(2);
            
            tft.setCursor(13, 200);
            tft.fillRect(5,180, 90,50, ILI9341_BLACK);
            tft.print(p1);
            
            tft.setCursor(120, 200);
            tft.fillRect(115,180, 90,50, ILI9341_BLACK);
            tft.print(p2);
            
            tft.setCursor(225, 200);
            tft.fillRect(220,180, 90,50, ILI9341_BLACK);
            tft.print(p3);
            
            tft.setTextSize(3);

        }

        


};

Menu Display;








