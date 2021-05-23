#include <Arduino.h>
#include <display.h>
#include <audio_shield.h>


// Int



void setup() {
    Serial.begin(115200);

    Display.start();                                    // Display Start
    Display.clear();                                    // Display Clear
    Display.rect();                                     // Disp_rect

    Teensy41.init();                                    // Init Audio Shield   
    Teensy41.sound_test();                      

    delay(1000);
    


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Teensy 4.1 - Audio FX");
}
