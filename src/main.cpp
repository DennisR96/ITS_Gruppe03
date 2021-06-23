#include <Arduino.h>
#include <AudioSampleSnare.h>
#include <Bounce.h>
#include "shield.h"
#include "display.h"
#include "control.h"
#include "encoding.h"


void setup() {
    Serial.begin(115200);

    // Encoder
    encoder_start();
    encoder_init(store[0], prevNextCode[0], CLK[0], DATA[0]);
    encoder_init(store[1], prevNextCode[1], CLK[1], DATA[1]);
    encoder_init(store[2], prevNextCode[2], CLK[2], DATA[2]);
    encoder_init(store[3], prevNextCode[3], CLK[3], DATA[3]);
  
    // Display
    Display.start();                                    // Display Start
    Display.clear();                                    // Display Clear
    Display.rect();                                     // Disp_rect
    Display.fx_bitcrush();
    
    // Fx
    AudioMemory(200);
    sgtl5000_1.enable();
    sgtl5000_1.volume(1);
    mixer1.gain(0,1);                 // Input1: Input
    mixer1.gain(1,0);                 // Input2: Bitcrusher
    mixer1.gain(2,0);                 // Input3: Reverb
    }

void loop() {
  // put your main code here, to run repeatedly:
  encoder_update();

}