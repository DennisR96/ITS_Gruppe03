#include <Arduino.h>
#include <Bounce.h>
#include "control.h"
#include "encoding.h"
#include "display.h"
#include "shield.h"


//#include <shield.h>

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
    Display.fx_reverb();
    
    // Fx
    // AudioMemory(20);
    // sgtl5000_1.enable();
    // sgtl5000_1.volume(0.8);

    // input1.amplitude(0.5);
    // input1.frequency(500);
    // freeverb1.roomsize(20);
    // freeverb1.damping(200);
    }

void loop() {
  // put your main code here, to run repeatedly:
  encoder_update();
  
}