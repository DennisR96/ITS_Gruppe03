// Teensy Library
#include <Arduino.h>
#include <Audio.h>
#include <Bounce.h>
#include <SPI.h>
#include <Wire.h>
#include "ILI9341_t3.h"

// Program Library
#include "shield.h"
#include "display.h"
#include "control.h"
#include "encoding.h"

void setup() {
    Serial.begin(115200);

    // Encoder - Init
    encoder_start();                                                          // Encoder PINs
    encoder_init(store[0], prevNextCode[0], CLK[0], DATA[0]);                 // Encoder 0
    encoder_init(store[1], prevNextCode[1], CLK[1], DATA[1]);                 // Encoder 1
    encoder_init(store[2], prevNextCode[2], CLK[2], DATA[2]);                 // Encoder 2
    encoder_init(store[3], prevNextCode[3], CLK[3], DATA[3]);                 // Encoder 3
  
    // Display - Init
    Display.start();                                    // Display Start
    Display.clear();                                    // Display Clear
    Display.rect();                                     // Disp_rect
    Display.reverb();
    Display.update_p(p_reverb[0], wet, p_reverb[1]);
    
    // Fx - Init
    AudioMemory(200);
    sgtl5000_1.enable();
    sgtl5000_1.volume(1);
    mixer1.gain(0,0);                                     // Wet: Right 
    mixer1.gain(1,0);                                     // Wet: Left
    mixer1.gain(2,1);                                     // Dry: Left
    mixer1.gain(3,1);                                     // Dry: Rights

    biquad1.setHighpass(0, p_filter[0], 0.707);
    biquad2.setHighpass(0, p_filter[0], 0.707);
    biquad1.setLowpass(1, p_filter[1], 0.707);
    biquad2.setLowpass(1, p_filter[1], 0.707);
    }

void loop() {
  encoder_update();
}